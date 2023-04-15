#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define NUM_THREADS 100 // number of threads

int value = 0;                                      // global variable to be shared by threads
pthread_mutex_t mutex;                              // mutex for synchronization
pthread_cond_t cond_var = PTHREAD_COND_INITIALIZER; // condition variable

int bufsize = 1; // initial buffer size
int index = -1;  // initialize to -1 so that first index is 0

int n, *Buffer; // this Buffer pointer hold the base address of the block created
int ans;

// thread function 1
void *Consumer(void *arg)
{
    while (1)
    {

        // Remove from the buffer
        pthread_mutex_lock(&mutex);
        printf("\n\nConsumer");
        // check if there is anything on the buffer to consume
        if (index > 0)
        {
            printf("\nConsumed the value:%d", Buffer[index - 1]);
            index--;
            printf("\nBuffer index before %d", index + 1);
            if (index == 0)
            {
                Buffer = (int *)malloc(sizeof(int));
            }
            else
            {
                // halve the buffer if necessary, dividing by 2 in size if needed basically reducing the time we are using realloc
                // To say we consumed we will only reduce the index, basically reducing the strain in memory writing kinda
                if (bufsize / 2 > index)
                {
                    bufsize /= 2;
                    Buffer = (int *)realloc(Buffer, bufsize * sizeof(int));
                    printf("\n\n                                    I reduced the Buffer size from %d to %d \n\n", bufsize, index);
  
                }
            }
            printf("\nBuffer index after %d", index);
        }
        else
        {
            printf("\nNothing to consume");
        }

        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}


void *Producer(void *arg)
{

    while (1)
    {
        // Produce
        int x = rand() % 256;

        pthread_mutex_lock(&mutex);

        printf("\n\nProducer");

        index++;
        if (index >= bufsize)
        {
            // expand buffer if necessary, doubling in size if needed basically reducing the time we are using realloc
            bufsize *= 2;
            Buffer = (int *)realloc(Buffer, bufsize * sizeof(int));
            printf("\n\n                                    I doubled the Buffer size from %d to %d \n\n", bufsize, index);
            if (Buffer == NULL)
            {
                printf("\nmemory cannot be allocated");
                pthread_mutex_unlock(&mutex);
                return NULL;
            }
        }
        Buffer[index] = x;

        printf("\nBuffer index after %d", index);

        printf("\nThe number produced for the buffer was:%d", Buffer[index]);

        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}

// main function
int main()
{

    int ans;
    int i = 0;
    Buffer = (int *)malloc(sizeof(int)); // dynamically allocate memory using malloc
    // check if the memory is successfully allocated by
    // malloc or not?
    if (Buffer == NULL)
    {
        printf("memory cannot be allocated");
    }
    else
    {
        // memory has successfully allocated
        printf("Memory has been successfully allocated by using malloc\n");
        printf("\n Buffer base address= %p \n", Buffer); // print the base or beginning address of allocated memory
    }

    pthread_t threads[NUM_THREADS];   // array to store threads
    pthread_mutex_init(&mutex, NULL); // initialize the mutex
    for (i = 0; i < NUM_THREADS; i++)
    {
        if (i == 0)
        {
            if (pthread_create(&threads[i], NULL, Consumer, NULL) != 0)
            {
                perror("Failed to create Consumer Thread\n");
            }
        }
        else
        {
            if (pthread_create(&threads[i], NULL, Producer, NULL) != 0)
            {
                perror("Failed to create producer thread Number [");
                printf("%d]\n\n", i);
            }
        }
    }

    for (i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL); // join all threads
    }

    pthread_mutex_destroy(&mutex);   // destroy the mutex
    pthread_cond_destroy(&cond_var); // destroy the condition variable

    return 0;
}
