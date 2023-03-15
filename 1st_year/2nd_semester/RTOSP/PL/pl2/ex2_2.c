#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ARRAY_SIZE 1000
#define CHUNK_SIZE (ARRAY_SIZE / 10)
#define SMALL_ARRAY_SIZE 10

int big_array[ARRAY_SIZE];
int small_array[SMALL_ARRAY_SIZE];
pthread_mutex_t mutex;

void *find_max(void *arg) {
    int *chunk = (int *)arg;
    int max_value = chunk[0];
    for (int i = 1; i < CHUNK_SIZE; i++) {
        if (chunk[i] > max_value) {
            max_value = chunk[i];
        }
    }
    int *result = malloc(sizeof(int));
    *result = max_value;
    pthread_exit(result);
}

int main() {
    // Initialize the arrays with random values
    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        big_array[i] = rand();
    }

    // Initialize the mutex
    pthread_mutex_init(&mutex, NULL);

    // Create the threads
    pthread_t threads[10];
    int chunks[10][CHUNK_SIZE];
    for (int i = 0; i < 10; i++) {
        int start = i * CHUNK_SIZE;
        int end = start + CHUNK_SIZE;
        for (int j = start; j < end; j++) {
            chunks[i][j - start] = big_array[j];
        }
        pthread_create(&threads[i], NULL, find_max, chunks[i]);
    }

    // Wait for the threads to finish and collect the results
    int max_value = big_array[0];
    for (int i = 0; i < 10; i++) {
        int *result;
        pthread_join(threads[i], (void **)&result);
        if (*result > max_value) {
            max_value = *result;
        }
        free(result);
    }

    // Print the result
    printf("The maximum value in the big array is %d\n", max_value);

    // Clean up the resources
    pthread_mutex_destroy(&mutex);
    return 0;
}