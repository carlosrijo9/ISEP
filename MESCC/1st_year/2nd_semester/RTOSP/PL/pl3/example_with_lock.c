#include <stdio.h>
#include <pthread.h>
#define NUM_THREADS 10
int counter = 0;
pthread_mutex_t mutex;
void *thread_fn_1(void *arg)
{
    pthread_mutex_lock(&mutex);
    for (int i = 0; i < 10000000; i++)
    {
        counter = counter + 1;
    }
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}
int main()
{
    pthread_t threads[10];
    int i = 0;
    pthread_mutex_init(&mutex, NULL);
    for (i = 0; i < NUM_THREADS; i++)
    {
        pthread_create(&threads[i], NULL, thread_fn_1, NULL);
    }

    for (i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    printf("counter = %d\n", counter);
    return 0;
}