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
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

// Matrices dimensions, where A is LxM, B is MxN, and C is LxN
#define L 100
#define M 100
#define N 100

#define DEFAULT_USER_ROWS L / 10

int A[L][M];
int B[M][N];
int C[L][N];
int expected[L][N];
double sequential_time;
// int N_THREADS = sizeof(A[0]) * sizeof(B[0]);
#define N_THREADS 100

#define MIN_RAND -10
#define MAX_RAND 10
pthread_mutex_t sum_mutex = PTHREAD_MUTEX_INITIALIZER;

typedef struct data_t
{
    int col;
    int row;
} data_t;

// Matrix multiplication versions
/**
 * Matrix multiplication: A[L,M]* B[M,N] = C[L,N]
 **/
void seq();
void a_par_by_pos();
void b_par_by_row();
void c_par_by_user_rows(int num_lines_per_thread);

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
    int user_block = DEFAULT_USER_ROWS;
    if (argc < 2)
    {
        printf("Number of lines per thread was not specified, will use default value: %d\n", user_block);
    }
    else
    {
        user_block = atoi(argv[2]);
    }
    printf("Each thread processes %d rows to multiplicate two matrices: A{%d,%d}*B{%d,%d} = C{%d,%d}\n", user_block, L, M, M, N, L, N);

    setup();

    printf("Threads by Position...");
    clock_t begin = clock();
    a_par_by_pos();
    clock_t end = clock();
    double pos_time = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("done.\n");
    assert(C, expected);

    c_clean();

    printf("Thread per line...");
    begin = clock();
    b_par_by_row();
    end = clock();
    double per_row_time = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("done.\n");
    assert(C, expected);

    c_clean();

    printf("Thread processes set of lines (user-defined)...");
    begin = clock();
    c_par_by_user_rows(user_block); // user defined chunk
    end = clock();
    double block_of_rows_time = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("done.\n");
    assert(C, expected);

    printf("\n- ==== Performance ==== -\n");
    printf("Sequential time:          %fs\n", sequential_time);
    printf("Parallel Pos time:        %fs\n", pos_time);
    printf("Parallel per row time:    %fs\n", per_row_time);
    printf("Parallel rows block time: %fs\n", block_of_rows_time);
}

/***
 * YOUR IMPLEMENTATIONS HERE!
 **/
/**
 * Version where each thread is responsible for a single position of the result matrix
 **/
void *myFunctA(void *data)
{
    data_t *mydata = (data_t *)data;
    int l = mydata->row;
    int c = mydata->col;
    calc(l, c);
}

void a_par_by_pos()
{

    data_t myData[L][N];
    pthread_t tid[L * N];
    int k = 0;

    for (int i = 0; i < L; i++)
    {

        for (int j = 0; j < N; j++)
        {
            myData[i][j].col = i;
            myData[i][j].row = j;
            // printf("create thread %d\n", k);
            pthread_create(&tid[k++], NULL, myFunctA, &myData[i][j]);
        }
    }

    for (int i = 0; i < L * N; i++)
    {
        pthread_join(tid[i], NULL);
    }
}

void *myFunctB(void *data)
{
    data_t *mydata = (data_t *)data;
    int row = mydata->row;

    for (int n = 0; n < N; n++)
    {
        int sum = 0;
        for (int m = 0; m < M; m++)
        {
            sum += A[row][m] * B[m][n];
        }
        C[row][n] = sum;
    }

    pthread_exit(NULL);
}

/**
 * Version where each thread is responsible for one line of the result matrix
 **/
void b_par_by_row()
{
    pthread_t tid[L];
    data_t myData[L];

    for (int i = 0; i < L; i++)
    {
        myData[i].row = i;
        pthread_create(&tid[i], NULL, myFunctB, &myData[i]);
    }

    for (int i = 0; i < L; i++)
    {
        pthread_join(tid[i], NULL);
    }
}
/**
 * Version where each thread is responsible for a number of user input lines
 * of the result matrix
 **/
void *myFunctC(void *data)
{
    data_t *mydata = (data_t *)data;
    int start_row = mydata->row;
    int num_lines_per_thread = mydata->col;

    for (int l = start_row; l < start_row + num_lines_per_thread; l++)
    {
        for (int n = 0; n < N; n++)
        {
            int sum = 0;
            for (int m = 0; m < M; m++)
            {
                sum += A[l][m] * B[m][n];
            }

            // Lock the mutex before updating the shared 'C' matrix
            pthread_mutex_lock(&sum_mutex);
            C[l][n] = sum;
            pthread_mutex_unlock(&sum_mutex);
        }
    }

    pthread_exit(NULL);
}

void c_par_by_user_rows(int num_lines_per_thread)
{
    pthread_t tid[N_THREADS];
    data_t myData[N_THREADS];

    int lines_per_thread = L / N_THREADS;
    int remaining_lines = L % N_THREADS;

    for (int i = 0; i < N_THREADS; i++)
    {
        myData[i].row = i * lines_per_thread;
        myData[i].col = num_lines_per_thread;

        // Distribute any remaining lines evenly among threads
        if (remaining_lines > 0)
        {
            myData[i].col += 1;
            remaining_lines--;
        }

        // printf("Thread %d: row %d, lines %d\n", i, myData[i].row, myData[i].col);
        pthread_create(&tid[i], NULL, myFunctC, &myData[i]);
    }

    for (int i = 0; i < N_THREADS; i++)
    {
        pthread_join(tid[i], NULL);
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
    clock_t begin = clock();
    seq();
    clock_t end = clock();
    sequential_time = (double)(end - begin) / CLOCKS_PER_SEC;
    // print((int *)A,L,M);
    // printf("   *   \n");
    // print((int *)B,M,N);
    // printf("   =   \n");
    // print((int *)C,L,N);

    for (int l = 0; l < L; l++)
    {
        for (int n = 0; n < N; n++)
        {
            expected[l][n] = C[l][n];
            C[l][n] = 0;
        }
    }
}