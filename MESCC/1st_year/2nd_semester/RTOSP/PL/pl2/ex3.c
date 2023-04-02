#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define MATRIX_SIZE 16
#define NR_THREADS 8
#define NR_THREADS_FILL 2

int matrix1[MATRIX_SIZE][MATRIX_SIZE];
int matrix2[MATRIX_SIZE][MATRIX_SIZE];
int result[MATRIX_SIZE][MATRIX_SIZE];

// function to fill a matrix with random integers
void *fillMatrix(void *args)
{
    time_t t;
    srand((unsigned)time(&t));
    int(*matrix)[MATRIX_SIZE] = args;
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            matrix[i][j] = rand() % 100; // fill with random integers between 0 and 99
        }
    }
    pthread_exit(NULL);
}

// function to multiply a portion of the matrices
void *multiplyMatrix(void *args)
{
    int thread_id = *(int *)args;
    int portion_size = MATRIX_SIZE / NR_THREADS;
    int start_row = thread_id * portion_size;
    int end_row = start_row + portion_size;

    for (int i = start_row; i < end_row; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            int sum = 0;
            for (int k = 0; k < MATRIX_SIZE; k++)
            {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            result[i][j] = sum;
        }
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t fill_threads[NR_THREADS_FILL];
    pthread_t multiply_threads[NR_THREADS];
    int thread_ids[NR_THREADS];

    // create threads to fill the matrices
    for (int i = 0; i < NR_THREADS_FILL; i++)
    {
        pthread_create(&fill_threads[i], NULL, fillMatrix, i == 0 ? matrix1 : matrix2);
    }

    // wait for fill threads to finish
    for (int i = 0; i < NR_THREADS_FILL; i++)
    {
        pthread_join(fill_threads[i], NULL);
    }

    // create threads to multiply the matrices
    for (int i = 0; i < NR_THREADS; i++)
    {
        thread_ids[i] = i;
        pthread_create(&multiply_threads[i], NULL, multiplyMatrix, &thread_ids[i]);
    }

    // wait for multiply threads to finish
    for (int i = 0; i < NR_THREADS; i++)
    {
        pthread_join(multiply_threads[i], NULL);
    }

    // print the resulting matrix
    printf("Resulting matrix:\n");
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            printf("| %d ", result[i][j]);
        }
        printf("|\n");
    }

    return 0;
}