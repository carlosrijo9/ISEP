/*
 * Copyright 2023 Instituto Superior de Engenharia do Porto
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
/*
**  PROGRAM: Mandelbrot area (solution)
**
**  PURPOSE: Program to compute the area of a  Mandelbrot set.
**           The correct answer should be around 1.510659.
**
**  USAGE:   Program runs without input ... just run the executable
**
**  ADDITIONAL EXERCISES:  Experiment with the schedule clause to fix
**               the load imbalance.   Experiment with atomic vs. critical vs.
**               reduction for numoutside.
**
**  HISTORY: Written:  (Mark Bull, August 2011).
**
**           Changed "comples" to "d_comples" to avoid collsion with
**           math.h complex type.   Fixed data environment errors
**          (Tim Mattson, September 2011)
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <omp.h>

#define DEFAULT_NUM_THREADS 4

#define NPOINTS 5000
#define MAXITER 1000

typedef struct result_t
{
    double area;
    double error;
} result_t;

struct d_complex
{
    double r;
    double i;
};

struct d_complex c;
int numoutside = 0;

void testpoint(struct d_complex, int maxiter);
void testpoint_par(struct d_complex, int maxiter);
void testpoint_task(struct d_complex, int maxiter);

result_t seq_mandel(int num_points, int maxiter);
result_t par_mandel(int num_threads, int num_points, int maxiter);
result_t par_for(int num_threads, int num_points, int maxiter);
result_t par_task(int num_threads, int num_points, int maxiter);
result_t par_mandel_block(int num_threads, int num_points, int maxiter, int block_size_ratio);

int main(int argc, char *argv[])
{
    srand(time(NULL));
    int num_threads = DEFAULT_NUM_THREADS;
    int num_points = NPOINTS;
    int maxiter = MAXITER;
    int block_size_ratio = 10;

    if (argc < 4)
    {
        // printf("Arguments not specified. Will use default values\n");
    }
    else
    {
        num_points = atoi(argv[1]);
        maxiter = atoi(argv[2]);
        block_size_ratio = atoi(argv[3]);
        num_threads = atoi(argv[4]);
    }

    result_t expected;

    // printf("Sequential Mandelbrot... ");
    double begin = omp_get_wtime();
    expected = seq_mandel(num_points, maxiter);
    double end = omp_get_wtime();
    double seq_time = (double)(end - begin);
    // printf("done.\n");
    // printf("[SEQ]Area of Mandlebrot set = %12.8f +/- %12.8f (outside: %d)\n", expected.area, expected.error, numoutside);

    // resetting values
    int expected_num_outside = numoutside;
    numoutside = 0;

    // printf("\nParallel Mandelbrot... ");
    begin = omp_get_wtime();
    result_t par_res = par_mandel(num_threads, num_points, maxiter);
    end = omp_get_wtime();
    double par_time = (double)(end - begin);
    // printf("done.\n");
    int par_num_outside = numoutside;
    // printf("[PAR]Area of Mandlebrot set = %12.8f +/- %12.8f (outside: %d)\n", par_res.area, par_res.error, par_num_outside);

    // resetting values
    expected_num_outside = numoutside;
    numoutside = 0;

    // printf("\nParallel Mandelbrot FOR... ");
    begin = omp_get_wtime();
    result_t par_for_res = par_for(num_threads, num_points, maxiter);
    end = omp_get_wtime();
    double par_for_time = (double)(end - begin);
    // printf("done.\n");
    int par_for_num_outside = numoutside;
    // printf("[PAR FOR]Area of Mandlebrot set = %12.8f +/- %12.8f (outside: %d)\n", par_for_res.area, par_for_res.error, par_for_num_outside);

    // resetting values
    expected_num_outside = numoutside;
    numoutside = 0;

    // printf("\nParallel Mandelbrot Task... ");
    begin = omp_get_wtime();
    result_t par_task_res = par_task(num_threads, num_points, maxiter);
    end = omp_get_wtime();
    double par_task_time = (double)(end - begin);
    // printf("done.\n");
    int par_task_num_outside = numoutside;
    // printf("[PAR TASK]Area of Mandlebrot set = %12.8f +/- %12.8f (outside: %d)\n", par_task_res.area, par_task_res.error, par_task_num_outside);

    // printf("\nParallel Mandelbrot Block Task... ");
    begin = omp_get_wtime();
    result_t par_block_res = par_mandel_block(num_threads, num_points, maxiter, block_size_ratio);
    end = omp_get_wtime();
    double par_block_time = (double)(end - begin);
    // printf("done.\n");
    int par_block_num_outside = numoutside;
    // printf("[PAR TASK Block]Area of Mandlebrot set = %12.8f +/- %12.8f (outside: %d)\n", par_block_res.area, par_block_res.error, par_block_num_outside);

    // printf("\n- ==== Performance ==== -\n");
    // printf("Sequential time: %fs\n", seq_time);
    // printf("Parallel   time: %fs\n", par_time);
    // printf("Parallel FOR time: %fs\n", par_for_time);
    // printf("Parallel Task time: %fs\n", par_task_time);
    // printf("Parallel Block time: %fs\n", par_block_time);

    printf(" ,Time (s),Matrix Size,Block Size,Nr Threads\n");
    printf("MandelBrot Area Calc, ,%d,%d,%d\n", num_points, block_size_ratio, num_threads);
    printf("seq,%f\n", seq_time * 1000);
    printf("par,%f\n", par_time * 1000);
    printf("par_for,%f\n", par_for_time * 1000);
    printf("task,%f\n", par_task_time * 1000);
    printf("task_block,%f\n", par_block_time * 1000);

    // if (expected.area != par_res.area || expected.error != par_res.error || expected_num_outside != par_num_outside)
    if (expected.area != par_res.area || expected.error != par_res.error || expected_num_outside != par_num_outside || expected.area != par_for_res.area || expected.error != par_for_res.error || expected_num_outside != par_for_num_outside || expected_num_outside != par_block_num_outside)
    {
        // printf("\n!Assert failed!\n");
        // printf("Sequential:\n");
        // printf("\tArea of Mandlebrot set = %12.8f +/- %12.8f (outside: %d)\n", expected.area, expected.error, expected_num_outside);
        // printf("Parallel:\n");
        // printf("\tArea of Mandlebrot set = %12.8f +/- %12.8f (outside: %d)\n", par_res.area, par_res.error, par_num_outside);
        // printf("PAR FOR:\n");
        // printf("\tArea of Mandlebrot set = %12.8f +/- %12.8f (outside: %d)\n", par_for_res.area, par_for_res.error, par_for_num_outside);
    }
}

result_t par_mandel(int num_threads, int num_points, int maxiter)
{
    int i, j;
    double area, error, eps = 1.0e-5;

    //   Loop over grid of points in the complex plane which contains the Mandelbrot set,
    //   testing each point to see whether it is inside or outside the set.
    omp_set_num_threads(num_threads);
#pragma omp parallel default(shared) firstprivate(eps) private(i, c, j)
    // reduction(+:numoutside)
    {
        int tid = omp_get_thread_num();
        int BS = num_points * num_points / num_threads;
        int REST = (num_points * num_points) % num_threads;
        int init = BS * tid;
        int fini = BS * (tid + 1);
        if (tid + 1 == num_threads)
        {
            fini += REST;
        }

        for (int p = init; p < fini; p++)
        {
            i = p / num_points;
            j = p % num_points;
            // //printf("i:%d,j%d\n",i,j);
            c.r = -2.0 + 2.5 * (double)(i) / (double)(num_points) + eps;
            c.i = 1.125 * (double)(j) / (double)(num_points) + eps;
            testpoint_par(c, maxiter);
        }
    }

    // Calculate area of set and error estimate and output the results

    area = 2.0 * 2.5 * 1.125 * (double)(num_points * num_points - numoutside) / (double)(num_points * num_points);
    error = area / (double)num_points;

    result_t result = {area, error};
    return result;
}

result_t par_mandel_2(int num_threads, int num_points, int maxiter)
{
    int i, j;
    double area, error, eps = 1.0e-5;

    //   Loop over grid of points in the complex plane which contains the Mandelbrot set,
    //   testing each point to see whether it is inside or outside the set.
    omp_set_num_threads(num_threads);
#pragma omp parallel for default(shared) firstprivate(eps) private(c, j)
    // reduction(+:numoutside)
    for (i = 0; i < num_points; i++)
    {
        for (j = 0; j < num_points; j++)
        {
            c.r = -2.0 + 2.5 * (double)(i) / (double)(num_points) + eps;
            c.i = 1.125 * (double)(j) / (double)(num_points) + eps;
            testpoint_par(c, maxiter);
        }
    }

    // Calculate area of set and error estimate and output the results

    area = 2.0 * 2.5 * 1.125 * (double)(num_points * num_points - numoutside) / (double)(num_points * num_points);
    error = area / (double)num_points;

    result_t result = {area, error};
    return result;
}

void testpoint_par(struct d_complex c, int maxiter)
{

    // Does the iteration z=z*z+c, until |z| > 2 when point is known to be outside set
    // If loop count reaches maxiter, point is considered to be inside the set

    struct d_complex z;
    int iter;
    double temp;

    z = c;
    for (iter = 0; iter < maxiter; iter++)
    {
        temp = (z.r * z.r) - (z.i * z.i) + c.r;
        z.i = z.r * z.i * 2 + c.i;
        z.r = temp;
        if ((z.r * z.r + z.i * z.i) > 4.0)
        {
#pragma omp atomic
            numoutside++;
            break;
        }
    }
}

result_t seq_mandel(int num_points, int maxiter)
{
    int i, j;
    double area, error, eps = 1.0e-5;

    for (i = 0; i < num_points; i++)
    {
        for (j = 0; j < num_points; j++)
        {
            c.r = -2.0 + 2.5 * (double)(i) / (double)(num_points) + eps;
            c.i = 1.125 * (double)(j) / (double)(num_points) + eps;
            testpoint(c, maxiter);
        }
    }

    // Calculate area of set and error estimate and output the results
    area = 2.0 * 2.5 * 1.125 * (double)(num_points * num_points - numoutside) / (double)(num_points * num_points);
    error = area / (double)num_points;

    result_t result = {area, error};
    printf("Area seq = %f",area);
    printf("\nError seq = %f",error);
    printf("\numoutside seq = %d",numoutside);
    return result;
}

result_t par_for(int num_threads, int num_points, int maxiter)
{
    double area = 0, error = 0, eps = 1.0e-5;
    numoutside = 0;
    omp_set_num_threads(num_threads);

#pragma omp parallel for default(shared) firstprivate(eps) private(c) collapse(2)
    for (int i = 0; i < num_points; i++)
    {
        for (int j = 0; j < num_points; j++)
        {
            c.r = -2.0 + 2.5 * (double)(i) / (double)(num_points) + eps;
            c.i = 1.125 * (double)(j) / (double)(num_points) + eps;
            // #pragma omp critical
            testpoint_par(c, maxiter);
        }
    }

    // Calculate area of set and error estimate and output the results
    area = 2.0 * 2.5 * 1.125 * (double)(num_points * num_points - numoutside) / (double)(num_points * num_points);
    error = area / (double)num_points;

    result_t result = {area, error};
    return result;
}

void testpoint(struct d_complex c, int maxiter)
{
    // Does the iteration z=z*z+c, until |z| > 2 when point is known to be outside set
    // If loop count reaches maxiter, point is considered to be inside the set

    struct d_complex z;
    int iter;
    double temp;

    z = c;
    for (iter = 0; iter < maxiter; iter++)
    {
        temp = (z.r * z.r) - (z.i * z.i) + c.r;
        z.i = z.r * z.i * 2 + c.i;
        z.r = temp;
        if ((z.r * z.r + z.i * z.i) > 4.0)
        {
            numoutside++;
            break;
        }
    }
}

void testpoint2(struct d_complex c, int maxiter)
{
    // Does the iteration z=z*z+c, until |z| > 2 when point is known to be outside set
    // If loop count reaches maxiter, point is considered to be inside the set

    struct d_complex z;
    int iter;
    double temp;

    z = c;
    for (iter = 0; iter < maxiter; iter++)
    {
        temp = (z.r * z.r) - (z.i * z.i) + c.r;
        z.i = z.r * z.i * 2 + c.i;
        z.r = temp;
        if ((z.r * z.r + z.i * z.i) > 4.0)
        {
#pragma omp critical
            numoutside++;

            break;
        }
    }
}
// The corrected par_task function with appropriate OpenMP pragmas and dependency handling
result_t par_task(int num_threads, int num_points, int maxiter)
{
    double area = 0, error = 0, eps = 1.0e-5;
    numoutside = 0;
    omp_set_num_threads(num_threads);

    // Corrected parallel region with task creation and dependencies
#pragma omp parallel
    {
#pragma omp single
        {
            for (int i = 0; i < num_points; i++)
            {
                for (int j = 0; j < num_points; j++)
                {
                    struct d_complex point;
                    point.r = -2.0 + 2.5 * (double)(i) / (double)(num_points) + eps;
                    point.i = 1.125 * (double)(j) / (double)(num_points) + eps;

                    // Task creation with dependencies
#pragma omp task firstprivate(point)
                    testpoint_par(point, maxiter);
                }
            }
        }
    }

    // Calculate area of set and error estimate
    area = 2.0 * 2.5 * 1.125 * (double)(num_points * num_points - numoutside) / (double)(num_points * num_points);
    error = area / (double)num_points;

    result_t result = {area, error};
    printf("\n\nArea par_task = %f",area);
    printf("\nError par_task = %f",error);
    printf("\numoutside par_task = %d",numoutside);
    return result;
}


result_t par_mandel_block(int num_threads, int num_points, int maxiter, int block_size_ratio)
{
    double area = 0, error = 0, eps = 1.0e-5;
    numoutside = 0;
    omp_set_num_threads(num_threads);

 int block_size = num_points / block_size_ratio;

#pragma omp parallel for collapse(2) default(shared) firstprivate(eps) private(c)
    for (int bi = 0; bi < block_size_ratio; bi++)
    {
        for (int bj = 0; bj < block_size_ratio; bj++)
        {
            int i_start = bi * block_size;
            int j_start = bj * block_size;
            int i_end = i_start + block_size;
            int j_end = j_start + block_size;

            // Adjust bounds if they exceed num_points
            if (i_end > num_points) i_end = num_points;
            if (j_end > num_points) j_end = num_points;

            for (int i = i_start; i < i_end; i++)
            {
                for (int j = j_start; j < j_end; j++)
                {
                    c.r = -2.0 + 2.5 * (double)(i) / (double)(num_points) + eps;
                    c.i = 1.125 * (double)(j) / (double)(num_points) + eps;
                    testpoint_par(c, maxiter);
                }
            }
        }
    }

    // Calculate area of set and error estimate and output the results
    area = 2.0 * 2.5 * 1.125 * (double)(num_points * num_points - numoutside) / (double)(num_points * num_points);
    error = area / (double)num_points;

    result_t result = {area, error};
    printf("\n\nArea par_mandel_block = %f",area);
    printf("\nError par_mandel_block = %f",error);
    printf("\numoutside par_mandel_block = %d \n\n -------------------------------------------",numoutside);
    return result;
}