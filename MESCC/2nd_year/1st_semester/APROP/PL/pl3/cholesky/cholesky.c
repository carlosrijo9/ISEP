#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <assert.h>
#include "omp.h"
#include "cholesky.h"

// Parallel For
void cholesky_blocked_par_for(const int ts, const int nt, double *Ah[nt][nt])
{

   for (int k = 0; k < nt; k++)
   {
      // Diagonal Block factorization
      potrf(Ah[k][k], ts, ts);

#pragma omp parallel
      {
// Triangular systems
#pragma omp for
         for (int i = k + 1; i < nt; i++)
         {
            trsm(Ah[k][k], Ah[k][i], ts, ts);
         }

#pragma omp for //collapse(2)
         // Update trailing matrix
         for (int i = k + 1; i < nt; i++)
         {
            // #pragma omp for
            for (int j = k + 1; j < i; j++)
            {
               gemm(Ah[k][i], Ah[k][j], Ah[j][i], ts, ts);
            }
            syrk(Ah[k][i], Ah[i][i], ts, ts);
         }
      }
   }
}

void cholesky_task(int ts, int nt, double *Ah[nt][nt])
{
#pragma omp parallel
   {
#pragma omp single
      {
         for (int k = 0; k < nt; k++)
         {
            // Diagonal Block factorization
            potrf(Ah[k][k], ts, ts);

            // Triangular systems
            for (int i = k + 1; i < nt; i++)
            {
#pragma omp task
               trsm(Ah[k][k], Ah[k][i], ts, ts);
            }

#pragma omp taskwait

            // Update trailing matrix
            for (int i = k + 1; i < nt; i++)
            {
#pragma omp task
               for (int j = k + 1; j < i; j++)
               {

                  gemm(Ah[k][i], Ah[k][j], Ah[j][i], ts, ts);
               }
#pragma omp task
               syrk(Ah[k][i], Ah[i][i], ts, ts);
            }
#pragma omp taskwait
         }
      }
   }
}

void cholesky_task_deps(int ts, int nt, double *Ah[nt][nt])
{
#pragma omp parallel
   {
#pragma omp single
      {
         for (int k = 0; k < nt; k++)
         {
            // Diagonal Block factorization
            potrf(Ah[k][k], ts, ts);

#pragma omp taskloop
            // Triangular systems
            for (int i = k + 1; i < nt; i++)
            {
// Make sure the current task depends on the diagonal factorization
#pragma omp task depend(in : Ah[k][k]) depend(out : Ah[k][i])
               trsm(Ah[k][k], Ah[k][i], ts, ts);
            }

// Ensure all tasks for triangular systems are completed before proceeding
#pragma omp taskwait

            // Update trailing matrix
            for (int i = k + 1; i < nt; i++)
            {

               for (int j = k + 1; j < i; j++)
               {
#pragma omp task depend(in : Ah[k][i], Ah[k][j]) depend(inout : Ah[j][i])
                  gemm(Ah[k][i], Ah[k][j], Ah[j][i], ts, ts);
               }
#pragma omp task depend(in : Ah[k][i]) depend(out : Ah[i][i])
               syrk(Ah[k][i], Ah[i][i], ts, ts);
            }
#pragma omp taskwait
         }
      }
   }
}

// Sequential
void cholesky_seq_blocked(const int ts, const int nt, double *Ah[nt][nt])
{
   for (int k = 0; k < nt; k++)
   {
      // Diagonal Block factorization
      potrf(Ah[k][k], ts, ts);

      // Triangular systems
      for (int i = k + 1; i < nt; i++)
      {
         trsm(Ah[k][k], Ah[k][i], ts, ts);
      }

      // Update trailing matrix
      for (int i = k + 1; i < nt; i++)
      {
         for (int j = k + 1; j < i; j++)
         {
            gemm(Ah[k][i], Ah[k][j], Ah[j][i], ts, ts);
         }
         syrk(Ah[k][i], Ah[i][i], ts, ts);
      }
   }
}

void print_matrix(int n, double *const matrix)
{
   printf("\t{\n\t");
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         printf("%.5f, ", matrix[i * n + j]);
      }
      printf("\n\t");
   }
   printf("};\n");
}

int main(int argc, char *argv[])
{

   if (argc < 4)
   {
      printf("cholesky matrix_size block_size num_threads\n");
      exit(-1);
   }
   const int n = atoi(argv[1]);     // matrix size
   const int ts = atoi(argv[2]);    // tile size
   int num_threads = atoi(argv[3]); // number of threads to use
   omp_set_num_threads(num_threads);
   // Allocate matrix
   double *const matrix = (double *)malloc(n * n * sizeof(double));
   assert(matrix != NULL);

   // Init matrix
   initialize_matrix(n, ts, matrix);

   // Allocate matrix
   double *const original_matrix = (double *)malloc(n * n * sizeof(double));
   assert(original_matrix != NULL);

   // Allocate matrix
   double *const expected_matrix = (double *)malloc(n * n * sizeof(double));
   assert(expected_matrix != NULL);

   const int nt = n / ts;

   // Allocate blocked matrix
   double *Ah[nt][nt];

   for (int i = 0; i < nt; i++)
   {
      for (int j = 0; j < nt; j++)
      {
         Ah[i][j] = malloc(ts * ts * sizeof(double));
         assert(Ah[i][j] != NULL);
      }
   }

   for (int i = 0; i < n * n; i++)
   {
      original_matrix[i] = matrix[i];
   }
   // Sequential
   convert_to_blocks(ts, nt, n, (double(*)[n])matrix, Ah);
   // warming up libraries
   cholesky_seq_blocked(ts, nt, (double *(*)[nt])Ah);
   convert_to_blocks(ts, nt, n, (double(*)[n])matrix, Ah);
   // done warming up
   double t1 = omp_get_wtime();
   // run sequential version
   cholesky_seq_blocked(ts, nt, (double *(*)[nt])Ah);
   double t2 = omp_get_wtime() - t1;
   // calculate timing metrics
   const double seq_time = t2;
   const double seq_gflops = (((1.0 / 3.0) * n * n * n) / ((seq_time) * 1.0e+9));

   // saving matrix to the expected result matrix
   convert_to_linear(ts, nt, n, Ah, (double(*)[n])matrix);
   for (int i = 0; i < n * n; i++)
   {
      expected_matrix[i] = matrix[i];
   }
   // End Sequential

   /*************************************************************************************************************
    * NOTE FOR STUDENTS:
    * COPY the following code (between multiline comments, up to "End Parallel For") to invoke your version
    * AND make the following changes:
    *  1. change "cholesky_blocked_par_for" to the name of your method
    *  2. change "par_for_time" and "par_for_gflops" for names that reflect your implementation (e.g. par_task_time)
    *     2.1. Don't forget to change the "par_for_time" variable that is used to calculate the gflops
    *  3. add two lines that print the time for your code (below in "Print Result" section)
    *************************************************************************************************************/

   /*****************************************************************************************************
    * Parallel For
    *****************************************************************************************************/
   // resetting matrix
   for (int i = 0; i < n * n; i++)
   {
      matrix[i] = original_matrix[i];
   }
   // require to work with blocks
   convert_to_blocks(ts, nt, n, (double(*)[n])matrix, Ah);
   t1 = omp_get_wtime();
   // run parallel version using parallel fors
   cholesky_blocked_par_for(ts, nt, (double *(*)[nt])Ah);
   t2 = omp_get_wtime() - t1;
   // calculate timing metrics
   const double par_for_time = t2;
   const double par_for_gflops = (((1.0 / 3.0) * n * n * n) / ((par_for_time) * 1.0e+9));

   // asserting result, comparing the output to the expect matrix
   convert_to_linear(ts, nt, n, Ah, (double(*)[n])matrix);
   assert_matrix(n, matrix, expected_matrix);

   /*****************************************************************************************************
    * End Parallel For
    *****************************************************************************************************/

   /*****************************************************************************************************
    * Parallel Task
    *****************************************************************************************************/
   // resetting matrix
   for (int i = 0; i < n * n; i++)
   {
      matrix[i] = original_matrix[i];
   }
   // require to work with blocks
   convert_to_blocks(ts, nt, n, (double(*)[n])matrix, Ah);
   t1 = omp_get_wtime();
   // run parallel version using parallel fors
   cholesky_task(ts, nt, (double *(*)[nt])Ah);
   t2 = omp_get_wtime() - t1;
   // calculate timing metrics
   const double task_time = t2;
   const double task_gflops = (((1.0 / 3.0) * n * n * n) / ((task_time) * 1.0e+9));

   // asserting result, comparing the output to the expect matrix
   //  convert_to_linear(ts, nt, n, Ah, (double (*)[n]) matrix);
   //  assert_matrix(n,matrix,expected_matrix);

   /*****************************************************************************************************
    * End Parallel Task
    *****************************************************************************************************/

   /*****************************************************************************************************
    * Parallel Task with dependencies
    *****************************************************************************************************/
   // resetting matrix
   for (int i = 0; i < n * n; i++)
   {
      matrix[i] = original_matrix[i];
   }
   // require to work with blocks
   convert_to_blocks(ts, nt, n, (double(*)[n])matrix, Ah);
   t1 = omp_get_wtime();
   // run parallel version using parallel fors
   cholesky_task_deps(ts, nt, (double *(*)[nt])Ah);
   t2 = omp_get_wtime() - t1;
   // calculate timing metrics
   const double task_dep_time = t2;
   const double task_dep_gflops = (((1.0 / 3.0) * n * n * n) / ((task_dep_time) * 1.0e+9));

   // asserting result, comparing the output to the expect matrix
   convert_to_linear(ts, nt, n, Ah, (double(*)[n])matrix);
   assert_matrix(n, matrix, expected_matrix);

   /*****************************************************************************************************
    * End Parallel Task with dependencies
    *****************************************************************************************************/

   // // Print result
   // printf("============ CHOLESKY RESULTS ============\n");
   // printf("  matrix size:                  %dx%d\n", n, n);
   // printf("  block size:                   %dx%d\n", ts, ts);
   // printf("  number of threads:            %d\n", num_threads);
   // printf("  seq_time (s):                 %f\n", seq_time);
   // printf("  seq_performance (gflops):     %f\n", seq_gflops);
   // printf("  par_for_time (s):             %f\n", par_for_time);
   // printf("  par_for_performance (gflops): %f\n", par_for_gflops);
   // printf("  task_time (s):                %f\n", task_time);
   // printf("  task_performance (gflops):    %f\n", task_gflops);
   // printf("  task_dep_time (s):            %f\n", task_dep_time);
   // printf("  task_dep_performance (gflops):%f\n", task_dep_gflops);
   // printf("==========================================\n");

   printf(" ,Time (s),Performance (gflops),Matrix Size,Block Size,Nr Threads\n");
   printf("seq,%f,%f,%d,%d,%d\n", seq_time, seq_gflops, n, ts, num_threads);
   printf("par_for,%f,%f\n", par_for_time, par_for_gflops);
   printf("task,%f,%f\n", task_time, task_gflops);
   printf("task_dep,%f,%f\n", task_dep_time, task_dep_gflops);

   free(original_matrix);
   free(expected_matrix);
   // Free blocked matrix
   for (int i = 0; i < nt; i++)
   {
      for (int j = 0; j < nt; j++)
      {
         assert(Ah[i][j] != NULL);
         free(Ah[i][j]);
      }
   }
   // Free matrix
   free(matrix);

   return 0;
}
