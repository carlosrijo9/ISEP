#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <omp.h>

// Matrices dimensions, where M is row x col
#define row 1024
#define col 1024
#define N 1024

#define BS 2

#define DEFAULT_NUM_THREADS 4

float M[row][col];
float M_seq[row][col];
float M_task[row][col];
float M_taskBS[row][col];
double sequential_time;

#define MIN_RAND -10
#define MAX_RAND 10

void seq();
void task();
void taskBS(int num_threads);

// Utility functions
void fill(float *matrix, int height, int width);
void print(int *matrix, int height, int width);
void printFLOAT(float *matrix, int height, int width);
void c_clean();
void setup();
void assert(float M_seq[row][col], float M_task[row][col]);

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
    printf("Working with %d threads row %d || column %d\n", num_threads, row, col);

    setup();

    printf("matrix working with parallel task... ");
    double begin = omp_get_wtime();
    task(num_threads);
    double end = omp_get_wtime();
    double pTask_time = (double)(end - begin);
    printf("done.\n");
    assert(M_seq, M_task);

    printf("matrix working with parallel task p/ BS... ");
    begin = omp_get_wtime();
    taskBS(num_threads);
    end = omp_get_wtime();
    double pTaskBS_time = (double)(end - begin);
    printf("done.\n");
    assert(M_seq, M_taskBS);

    printf("\n- ==== Performance ==== -\n");
    printf("Sequential time:     %fs\n", sequential_time);
    printf("parallel task: %fs\n", pTask_time);
    printf("parallel task p/ BS: %fs\n", pTaskBS_time);
}

// Functions
void seq()
{
    for (int i = 1; i < row - 1; i++) // row
    {
        for (int j = 1; j < col - 1; j++) // column
        {
            M_seq[i][j] = (M[i][j - 1] + M[i - 1][j] + M[i][j + 1] + M[i + 1][j]) / 4.0;
        }
    }
}

void task(int num_threads)
{
#pragma omp parallel
#pragma omp single
    for (int i = 1; i < row - 1; i++)
    {
        for (int j = 1; j < col - 1; j++)
        {
#pragma omp task depend(in : M[i][j - 1], M[i - 1][j]) depend(out : M_task[i][j])
            M_task[i][j] = (M[i][j - 1] + M[i - 1][j] + M[i][j + 1] + M[i + 1][j]) / 4.0;
        }
    }
}

void taskBS(int num_threads)
{
#pragma omp parallel
    for (int k = 0; k < BS - 1; k + BS)
    {
        for (int l = 0; l < BS - 1; l + BS)
        {
#pragma omp task depend(in : M[k][l - 1], M[k - 1][l]) depend(out : M_taskBS[k][l])
            for (int i = 1; i < k; i++)
            {
                for (int j = 1; j < l; j++)
                {
                    M_taskBS[i][j] = (M[i][j - 1] + M[i - 1][j] + M[i][j + 1] + M[i + 1][j]) / 4.0;
                }
            }
        }
    }
}

// Utility functions
void fill(float *matrix, int height, int width)
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

void printFLOAT(float *matrix, int height, int width)
{

    for (int l = 0; l < height; l++)
    {
        printf("[");
        for (int n = 0; n < width; n++)
        {
            printf(" %.5f", *((matrix + l * width) + n));
        }
        printf(" ]\n");
    }
}

void c_clean()
{
    for (int l = 0; l < row; l++)
    {
        for (int n = 0; n < N; n++)
        {
            M[l][n] = 0;
        }
    }
}

void setup()
{
    fill((float *)M, row, col);
    double begin = omp_get_wtime();
    // printFLOAT((float *)M, row, col);
    printf("\n");
    seq();
    // printFLOAT((float *)M_seq, row, col);
    double end = omp_get_wtime();
    sequential_time = (double)(end - begin);
}

void assert(float M_seq[row][col], float M_task[row][col])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (M_task[i][j] != M_seq[i][j])
            {
                printf("Wrong value at position [%d,%d], expected %.5f, but got %.5f instead\n", i, j, M_seq[i][j], M_task[i][j]);
                exit(-1);
            }
        }
    }
}