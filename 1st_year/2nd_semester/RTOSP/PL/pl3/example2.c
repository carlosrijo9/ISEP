#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 2

int value = 0;
pthread_mutex_t mutex;
pthread_cond_t cond_var = PTHREAD_COND_INITIALIZER;

void *thread_fn_1(void *arg)
{
    pthread_mutex_lock(&mutex);
    while (value == 0)
    {
        printf("thread_fn_1: value is %d - going to wait\n", value);
        pthread_cond_wait(&cond_var, &mutex); // mutex is released after wait is called so that thread 2 can access the critical section
        printf("thread_fn_1: value is %d - after waiting\n", value);
    }
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

void *thread_fn_2(void *arg)
{
    pthread_mutex_lock(&mutex);
    value = value + 1;
    if (value > 0)
    {
        printf("thread_fn_2: value is %d - going to signal\n", value);
        pthread_cond_signal(&cond_var);
    }
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[2];
    int i = 0;
    pthread_mutex_init(&mutex, NULL);
    pthread_create(&threads[0], NULL, thread_fn_1, NULL);
    pthread_create(&threads[1], NULL, thread_fn_2, NULL);

    for (i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond_var);

    printf("main: value is %d\n", value);
    return 0;
}