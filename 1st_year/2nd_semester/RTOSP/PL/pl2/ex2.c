#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define NR_THREADS 10
#define ARRAY1_SIZE 1000
#define ARRAY2_SIZE 10

pthread_mutex_t mutex;

int arr1[ARRAY1_SIZE];
int arr2[ARRAY2_SIZE];

void *findMax(void *arg)
{
    int *subarray = (int *)arg;
    int max_val = subarray[0];
    for (int i = 1; i < ARRAY1_SIZE / NR_THREADS; i++)
    {
        if (subarray[i] > max_val)
        {
            max_val = subarray[i];
        }
    }
    int *result = malloc(sizeof(int));
    *result = max_val;
    pthread_exit(result);
}

int main(void)
{
    time_t t;
    srand((unsigned)time(&t));
    for (int i = 0; i < ARRAY1_SIZE; i++)
    {
        // printf("%d\n", rand());
        arr1[i] = rand();
    }

    pthread_mutex_init(&mutex, NULL);

    pthread_t threads[NR_THREADS];

    int thread_args[10][ARRAY1_SIZE / NR_THREADS];
    for (int i = 0; i < 10; i++) {
        int start = i * ARRAY1_SIZE / NR_THREADS;
        int end = start + ARRAY1_SIZE / NR_THREADS;
        for (int j = start; j < end; j++) {
            thread_args[i][j - start] = arr1[j];
        }
        pthread_create(&threads[i], NULL, findMax, thread_args[i]);
    }

    // Wait for the threads to finish and collect the results
    int max_val = arr1[0];
    for (int i = 0; i < 10; i++) {
        int *result;
        pthread_join(threads[i], (void **)&result);
        if (*result > max_val) {
            max_val = *result;
        }
        free(result);
    }

    printf("Biggest number detected: %d\n", max_val);
    pthread_mutex_destroy(&mutex);
    return 0;
}