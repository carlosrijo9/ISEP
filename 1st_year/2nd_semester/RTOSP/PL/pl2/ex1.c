#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define NR_THREADS 10
#define ARRAY1_SIZE 1000
#define ARRAY2_SIZE 10

int arr1[ARRAY1_SIZE];
int arr2[ARRAY2_SIZE];

void *findMax(void *arg)
{
    int subarray_idx = *(int *)arg;
    int start_idx = subarray_idx * ARRAY1_SIZE / NR_THREADS;
    int end_idx = start_idx + ARRAY1_SIZE / NR_THREADS;

    int local_max = arr1[start_idx];
    for (int i = start_idx + 1; i < end_idx; i++)
    {
        if (arr1[i] > local_max)
        {
            local_max = arr1[i];
        }
    }

    arr2[subarray_idx] = local_max;
    pthread_exit(NULL);
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

    pthread_t threads[NR_THREADS];
    int thread_args[NR_THREADS];

    for (int i = 0; i < NR_THREADS; i++)
    {
        thread_args[i] = i;
        pthread_create(&threads[i], NULL, findMax, &thread_args[i]);
    }

    for (int i = 0; i < NR_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    int max_val = arr2[0];
    for (int i = 1; i < ARRAY2_SIZE; i++)
    {
        if (arr2[i] > max_val)
        {
            max_val = arr2[i];
        }
    }

    printf("Biggest number detected: %d\n", max_val);

    return 0;
}