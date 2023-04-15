#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h> // for sleep()
#include <stdint.h>
#include <sys/wait.h>

#define NUM_READERS 5
#define NUM_WRITERS 2

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t read_condition = PTHREAD_COND_INITIALIZER;
pthread_cond_t write_condition = PTHREAD_COND_INITIALIZER;

int num_readers = 0;
int num_writers_waiting = 0;
int is_writing = 0;

void *reader(void *thread_id)
{
    long tid;
    tid = (long)thread_id;

    while (1)
    {
        // Acquire the mutex lock
        pthread_mutex_lock(&mutex);
        // Wait until there are no writers or waiting writers
        while (is_writing || num_writers_waiting > 0)
        {
            pthread_cond_wait(&read_condition, &mutex);
        }
        // Increment the number of readers
        num_readers++;
        printf("Reader %ld started reading. Number of readers: %d\n", tid, num_readers);
        // Release the mutex lock
        pthread_mutex_unlock(&mutex);

        // Read data from the shared resource
        sleep(1);

        // Acquire the mutex lock
        pthread_mutex_lock(&mutex);
        // Decrement the number of readers
        num_readers--;
        printf("Reader %ld stopped reading. Number of readers: %d\n", tid, num_readers);
        // Signal any waiting writers if no more readers are reading
        if (num_readers == 0)
        {
            pthread_cond_signal(&write_condition);
        }
        // Release the mutex lock
        pthread_mutex_unlock(&mutex);

        // Sleep for some time
        sleep(1);
    }
    pthread_exit(NULL);
}

void *writer(void *thread_id)
{
    long tid;
    tid = (long)thread_id;

    while (1)
    {
        // Acquire the mutex lock
        pthread_mutex_lock(&mutex);
        // Increment the number of waiting writers
        num_writers_waiting++;
        // Wait until there are no readers or writers
        while (num_readers > 0 || is_writing)
        {
            pthread_cond_wait(&write_condition, &mutex);
        }
        // Decrement the number of waiting writers and mark as writing
        num_writers_waiting--;
        is_writing = 1;
        printf("Writer %ld started writing.\n", tid);
        // Release the mutex lock
        pthread_mutex_unlock(&mutex);

        // Write to the shared resource
        sleep(1);

        // Acquire the mutex lock
        pthread_mutex_lock(&mutex);
        // Mark as not writing and signal any waiting readers or writers
        is_writing = 0;
        printf("Writer %ld stopped writing.\n", tid);
        pthread_cond_broadcast(&read_condition);
        pthread_cond_signal(&write_condition);
        // Release the mutex lock
        pthread_mutex_unlock(&mutex);

        // Sleep for some time
        sleep(1);
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t readers[NUM_READERS];
    pthread_t writers[NUM_WRITERS];

    for (i = 0; i < NUM_READERS; i++)
    {
        pthread_create(&readers[i], NULL, reader, (void *)i);
    }
    for (i = 0; i < NUM_WRITERS; i++)
    {
        pthread_create(&writers[i], NULL, writer, (void *)i);
    }

    for (i = 0; i < NUM_READERS; i++)
    {
        pthread_join(readers[i], NULL);
        printf("\nNUM_READERS: %d\n", i);
    }
    for (j = 0; j < NUM_WRITERS; j++)
    {
        pthread_join(writers[j], NULL);
        printf("\nNUM_WRITERS: %d\n", j);
    }
    return 0;
}