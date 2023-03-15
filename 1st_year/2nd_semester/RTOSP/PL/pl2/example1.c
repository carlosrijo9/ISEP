// Passing arguments to threads

#include <stdio.h>
#include <pthread.h>
#include <string.h>
#define NR_THREADS 5

void *thread_function(void *arg)
{
    char *received_arg = (char *)arg;
    printf("running thread: %lu received: %s\n", pthread_self(), received_arg);
    pthread_exit((void *)NULL);
}
int main()
{
    pthread_t threads[NR_THREADS];
    int i;
    char str[8] = "";
    for (i = 0; i < NR_THREADS; i++)
    {
        snprintf(str, sizeof(str), "MESCC_%d", i);
        pthread_create(&threads[i], NULL, thread_function, (void *)&str);
    }
    printf("All threads were created\n");

    for (i = 0; i < NR_THREADS; i++)
        pthread_join(threads[i], NULL);
    printf("All threads finished\n");
}
