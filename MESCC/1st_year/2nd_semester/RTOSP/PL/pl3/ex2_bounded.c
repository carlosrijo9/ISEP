#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 2 // number of threads

int value = 0; // global variable to be shared by threads
pthread_mutex_t mutex; // mutex for synchronization
pthread_cond_t cond_var = PTHREAD_COND_INITIALIZER; // condition variable

int buffer[100];
int count= 0;

// thread function 1
void *Consumer(void *arg)
{
    while (1) {
        int y;

        // Remove from the buffer
        pthread_mutex_lock(&mutex);
        // check if there is anything on the buffer to consume
        if (count!=0)
        {
            y = buffer[count - 1];
            count--;
            // Consume
            printf("Consumed %d\n", y);
        }
        
        pthread_mutex_unlock(&mutex);

    }
}

// thread function 2
void *Producer(void *arg)
{
    while (1) {
        // Produce
        int x = rand() % 256;
        pthread_mutex_lock(&mutex);
        // check overflow of buffer
        if(count!=100){
            buffer[count] = x;
            count++;
        }
        pthread_mutex_unlock(&mutex);
        //sleep(1);
    }


}

// main function
int main()
{
    pthread_t threads[NUM_THREADS]; // array to store threads
    int i = 0;
    pthread_mutex_init(&mutex, NULL); // initialize the mutex
    for (i = 0; i < NUM_THREADS; i++) {
        if (i > 0) {
            if (pthread_create(&threads[i], NULL, Consumer, NULL) != 0) {
                perror("Failed to create Consumer Thread\n");
            }
        } else {
            if (pthread_create(&threads[i], NULL, Producer, NULL) != 0) {
                perror("Failed to create producer thread Number [");
                printf("%d]\n\n",i);
            }
        }
    }

    for (i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL); // join all threads
    }

    pthread_mutex_destroy(&mutex); // destroy the mutex
    pthread_cond_destroy(&cond_var); // destroy the condition variable

    return 0;
}
