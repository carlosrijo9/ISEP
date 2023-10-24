/*
 * Copyright 2022 Instituto Superior de Engenharia do Porto
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * 	http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <omp.h>

// Matrices dimensions, where A is LxM, B is MxN, and C is LxN
#define L 1024
#define M 1024
#define N 1024

#define DEFAULT_NUM_THREADS 4

int A[L][M];
int B[M][N];
int C[L][N];
int expected[L][N];
double sequential_time;

#define MIN_RAND -10
#define MAX_RAND 10

// Matrix multiplication versions
/**
 * Matrix multiplication: A[L,M]* B[M,N] = C[L,N]
 **/
void seq();
void par_seq();
void par_row(int num_threads);
void par_block(int num_threads);
void pTask_cell();
void pTask_line();

// Utility functions
void calc(int l, int n);
void fill(int *matrix, int height, int width);
void print(int *matrix, int height, int width);
void assert(int C[L][N], int expected[L][N]);
void c_clean();
void setup();

// C[0][0] = sum(A[0][i] * B[0][i]) for i = 0 to M ...
// do this from c[0][0] till c[L-1][N-1]
int main(int argc, char *argv[])
{
    srand(time(NULL));
    int num_threads = DEFAULT_NUM_THREADS;
    if (argc < 2)
    {
        printf("Number of threads was not specified. Will use default value: %d\n", DEFAULT_NUM_THREADS);
    }
    else
    {
        num_threads = atoi(argv[1]);
    }
    printf("Working with %d threads to multiplicate two matrices: A{%d,%d}*B{%d,%d} = C{%d,%d}\n", num_threads, L, M, M, N, L, N);

    setup();

    printf("Thread working on lines... ");
    double begin = omp_get_wtime();
    par_row(num_threads);
    double end = omp_get_wtime();
    double per_row_time = (double)(end - begin);
    printf("done.\n");
    assert(C, expected);

    c_clean();

    printf("Thread working on region (block)... ");
    begin = omp_get_wtime();
    par_block(num_threads);
    end = omp_get_wtime();
    double per_block_time = (double)(end - begin);
    printf("done.\n");
    assert(C, expected);

    c_clean();

    printf("Thread working with for loop... ");
    begin = omp_get_wtime();
    par_seq(num_threads);
    end = omp_get_wtime();
    double par_seq_time = (double)(end - begin);
    printf("done.\n");
    assert(C, expected);

    printf("Thread working with parallel task p/ cell... ");
    begin = omp_get_wtime();
    pTask_cell(num_threads);
    end = omp_get_wtime();
    double pTask_cell_time = (double)(end - begin);
    printf("done.\n");
    assert(C, expected);

    printf("Thread working with parallel task p/ line... ");
    begin = omp_get_wtime();
    pTask_line(num_threads);
    end = omp_get_wtime();
    double pTask_line_time = (double)(end - begin);
    printf("done.\n");
    assert(C, expected);

    printf("\n- ==== Performance ==== -\n");
    printf("Sequential time:     %fs\n", sequential_time);
    printf("Parallel lines time: %fs\n", per_row_time);
    printf("Parallel block time: %fs\n", per_block_time);
    printf("For loop time: %fs\n", par_seq_time);
    printf("parallel task p/ cell time: %fs\n", pTask_cell_time);
    printf("parallel task p/ line time: %fs\n", pTask_line_time);
}

/**
 * Version where each thread is responsible for a set of rows
 **/
void par_row(int num_threads)
{
    omp_set_num_threads(num_threads);

#pragma omp parallel
    {
        int threadID = omp_get_thread_num();
        // printf("\nThread %d", threadID);
        int rowSize = L / num_threads;

        int initValue = threadID * rowSize;
        int endValue = (threadID + 1) * rowSize;

        for (int i = initValue; i < endValue; i++)
        {
            for (int j = 0; j < N; j++)
            {
                calc(i, j);
            }
        }
    }

    int restValue = L % num_threads;
    int initValue = L - restValue;

    if (restValue > 0)
    {
        for (int k = initValue; k < L; k++)
        {
            for (int l = 0; l < N; l++)
            {
                calc(k, l);
            }
        }
    }
}

/**
 * Version where each thread is responsible for a block of cells
 **/
void par_block(int num_threads)
{

    omp_set_num_threads(num_threads);
#pragma omp parallel
    {
        int threadID = omp_get_thread_num();
        int blockSize = (L * N) / num_threads;

        int initValue = threadID * blockSize;
        int endValue = (threadID + 1) * blockSize;

        // printf("\nID: %d -> From %d to %d (%d)\n", threadID, initValue, endValue - 1, blockSize);

        for (int k = initValue; k < endValue; k++)
        {
            int i = k / N;
            int j = k % N;
            calc(i, j);
        }
    }

    int restValue = (L * N) % num_threads;
    int initValue = (L * N) - restValue;

    if (restValue > 0)
    {
        for (int l = initValue; l < L * N; l++)
        {
            int q = l / N;
            int w = l % N;
            calc(q, w);
        }
    }
}

/**

 * Example of a sequential matrix multiplication
*/
void seq()
{
    for (int l = 0; l < L; l++)
    {
        for (int n = 0; n < N; n++)
        {
            int sum = 0;
            for (int m = 0; m < M; m++)
            {
                sum += A[l][m] * B[m][n];
            }
            C[l][n] = sum;
        }
    }
}

void par_seq(int num_threads)
{

    omp_set_num_threads(num_threads);
#pragma omp parallel for collapse(2)
    for (int l = 0; l < L; l++)
    {
        for (int n = 0; n < N; n++)
        {
            int sum = 0;
            for (int m = 0; m < M; m++)
            {
                sum += A[l][m] * B[m][n];
                // printf("\n%d", omp_get_thread_num());
            }
            C[l][n] = sum;
        }
    }
}

void pTask_cell(int num_threads)
{
    omp_set_num_threads(num_threads);
#pragma omp parallel
#pragma omp single
    {
        for (int l = 0; l < L; l++)
        {
            for (int n = 0; n < N; n++)
            {
                int sum = 0;
#pragma omp task firstprivate(l, n), shared(C)
                {
                    for (int m = 0; m < M; m++)
                    {
                        sum += A[l][m] * B[m][n];
                    }
                    C[l][n] = sum;
                }
            }
        }
    }
}

void pTask_line(int num_threads)
{
    omp_set_num_threads(num_threads);
#pragma omp parallel
#pragma omp single
    {
        for (int l = 0; l < L; l++)
        {
#pragma omp task firstprivate(l), shared(C)
            {
                for (int n = 0; n < N; n++)
                {
                    int sum = 0;
                    for (int m = 0; m < M; m++)
                    {
                        sum += A[l][m] * B[m][n];
                    }
                    C[l][n] = sum;
                }
            }
        }
    }
}

///////////////////////////////////////////////////////////////////////////
/**
 * UTILITY FUNCTIONS
 */
void calc(int l, int n)
{
    int sum = 0;
    for (int m = 0; m < M; m++)
    {
        sum += A[l][m] * B[m][n];
    }
    C[l][n] = sum;
}

void fill(int *matrix, int height, int width)
{
    for (int l = 0; l < height; l++)
    {
        for (int n = 0; n < width; n++)
        {
            *((matrix + l * width) + n) = MIN_RAND + rand() % (MAX_RAND - MIN_RAND + 1);
        }
    }
}

void print(int *matrix, int height, int width)
{

    for (int l = 0; l < height; l++)
    {
        printf("[");
        for (int n = 0; n < width; n++)
        {
            printf(" %5d", *((matrix + l * width) + n));
        }
        printf(" ]\n");
    }
}

void assert(int C[L][N], int expected[L][N])
{
    for (int l = 0; l < L; l++)
    {
        for (int n = 0; n < N; n++)
        {
            if (C[l][n] != expected[l][n])
            {
                printf("Wrong value at position [%d,%d], expected %d, but got %d instead\n", l, n, expected[l][n], C[l][n]);
                exit(-1);
            }
        }
    }
}

void c_clean()
{
    for (int l = 0; l < L; l++)
    {
        for (int n = 0; n < N; n++)
        {
            C[l][n] = 0;
        }
    }
}

void setup()
{
    fill((int *)A, L, M);
    fill((int *)B, M, N);
    double begin = omp_get_wtime();
    seq();
    double end = omp_get_wtime();
    sequential_time = (double)(end - begin);

    for (int l = 0; l < L; l++)
    {
        for (int n = 0; n < N; n++)
        {
            expected[l][n] = C[l][n];
            C[l][n] = 0;
        }
    }
}