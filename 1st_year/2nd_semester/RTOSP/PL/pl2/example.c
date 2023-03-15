#include <stdio.h>
#include <pthread.h>
#define NR_THREADS 5

void *thread_function(void *arg)
{
    printf("running thread: %lu\n", pthread_self());
    pthread_exit((void *)NULL);
}
int main()
{
    pthread_t threads[NR_THREADS];
    int i;
    for (i = 0; i < NR_THREADS; i++)
    {
        pthread_create(&threads[i], NULL, thread_function, NULL);
        printf("i=%d\n", i);
    }

    printf("All threads were created\n");

    for (i = 0; i < NR_THREADS; i++)
        pthread_join(threads[i], NULL);
    printf("All threads finished\n");
}