#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 10

// Define buffer structure
struct buffer_t
{
    int *items;           // array of items
    int in;               // index of next free slot
    int out;              // index of next item to remove
    int count;            // number of items in buffer
    pthread_mutex_t lock; // mutex to protect buffer
    pthread_cond_t full;  // condition variable for full buffer
    pthread_cond_t empty; // condition variable for empty buffer
};

// Initialize buffer
void buffer_init(struct buffer_t *buffer)
{
    buffer->items = malloc(BUFFER_SIZE * sizeof(int));
    buffer->in = 0;
    buffer->out = 0;
    buffer->count = 0;
    pthread_mutex_init(&buffer->lock, NULL);
    pthread_cond_init(&buffer->full, NULL);
    pthread_cond_init(&buffer->empty, NULL);
}

// Add item to buffer
void buffer_put(struct buffer_t *buffer, int item)
{
    pthread_mutex_lock(&buffer->lock);
    while (buffer->count == BUFFER_SIZE)
    {
        pthread_cond_wait(&buffer->full, &buffer->lock);
    }
    buffer->items[buffer->in] = item;
    buffer->in = (buffer->in + 1) % BUFFER_SIZE;
    buffer->count++;
    pthread_cond_signal(&buffer->empty);
    pthread_mutex_unlock(&buffer->lock);
}

// Remove item from buffer
int buffer_get(struct buffer_t *buffer)
{
    int item;
    pthread_mutex_lock(&buffer->lock);
    while (buffer->count == 0)
    {
        pthread_cond_wait(&buffer->empty, &buffer->lock);
    }
    item = buffer->items[buffer->out];
    buffer->out = (buffer->out + 1) % BUFFER_SIZE;
    buffer->count--;
    pthread_cond_signal(&buffer->full);
    pthread_mutex_unlock(&buffer->lock);
    return item;
}

// Define producer thread
void *producer(void *arg)
{
    struct buffer_t *buffer = (struct buffer_t *)arg;
    int i;
    for (i = 0;; i++)
    {
        buffer_put(buffer, i);
        printf("Producer produced item %d\n", i);
    }
}

// Define consumer thread
void *consumer(void *arg)
{
    struct buffer_t *buffer = (struct buffer_t *)arg;
    int item;
    while (1)
    {
        item = buffer_get(buffer);
        printf("Consumer consumed item %d\n", item);
    }
}

int main()
{
    // Initialize buffer
    struct buffer_t buffer;
    buffer_init(&buffer);

    // Create producer thread
    pthread_t producer_thread;
    if (pthread_create(&producer_thread, NULL, producer, &buffer))
    {
        fprintf(stderr, "Error creating producer thread\n");
        return 1;
    }

    // Create consumer thread
    pthread_t consumer_thread;
    if (pthread_create(&consumer_thread, NULL, consumer, &buffer))
    {
        fprintf(stderr, "Error creating consumer thread\n");
        return 1;
    }

    // Wait for threads to finish
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    return 0;
}
