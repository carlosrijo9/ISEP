#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sched.h>

#define NUM_THREADS 3
#define TARGET_CORE 2
struct taskargs
{
    struct timespec period;
    int priority;
    int number_of_jobs;
    int dummy_cycles;
};
void *periodic_task(void *arg)
{
    struct taskargs *targs;
    struct timespec next, period;
    int i, dummy_cycles;
    int job, number_jobs;
    int priority;
    struct sched_param params;
    cpu_set_t cores_mask;

    /* Read parameters from arg . */
    targs = (struct taskargs *)arg;
    period = targs->period;
    priority = targs->priority;
    number_jobs = targs->number_of_jobs;
    dummy_cycles = targs->dummy_cycles;
    /* Set affinity of thread to cores -> {0 , 1 , 2 , 3} */
    CPU_ZERO(&cores_mask);
    CPU_SET(TARGET_CORE, &cores_mask);
    pthread_setaffinity_np(pthread_self(), sizeof(cores_mask), &cores_mask);

    /* Set thread priority under SHED_FIFO scheduler . */
    params.sched_priority = priority;
    pthread_setschedparam(pthread_self(), SCHED_FIFO, &params);

    /* Sleep for 100 microseconds , to allow other threads to modify
   their priorities . */
    usleep(100);

    /* Read current time . */
    clock_gettime(CLOCK_MONOTONIC, &next);

    for (job = 1; job <= number_jobs; job++)
    {
        /* Do some work , burn some clock cycles . */
        for (i = 0; i < dummy_cycles; i++)
        {
            getpid();
        }

        /* Set timer for next activation . */
        next.tv_sec += period.tv_sec;   /* Seconds */
        next.tv_nsec += period.tv_nsec; /* Nanoseconds */
        if (next.tv_nsec > 1000000000L)
        {
            /* Nanoseconds can not exceed one second . */
            next.tv_nsec -= 1000000000L;
            next.tv_sec++;
        }
        clock_nanosleep(CLOCK_MONOTONIC,
                        TIMER_ABSTIME, &next, 0);
    }
}

int main()
{
    struct taskargs targs[NUM_THREADS];
    pthread_t threads[NUM_THREADS];
    int i;

    /* HIGH priority task . */
    targs[0].period.tv_sec = 0;
    targs[0].period.tv_nsec = 50000000; /* 50 ms */
    targs[0].priority = 99;
    targs[0].number_of_jobs = 20;
    targs[0].dummy_cycles = 10000; /* ---> 5 ms */

    /* LOW priority task . */
    targs[1].period.tv_sec = 0;
    targs[1].period.tv_nsec = 500000000; /* 500 ms */
    targs[1].priority = 97;
    targs[1].number_of_jobs = 2;
    targs[1].dummy_cycles = 500000; /* ---> 260 ms */

    /* INTERMEDIATE priority task . */
    targs[2].period.tv_sec = 0;
    targs[2].period.tv_nsec = 100000000; /* 100 ms */
    targs[2].priority = 98;
    targs[2].number_of_jobs = 10;
    targs[2].dummy_cycles = 10000; /* ---> 5 ms */

    /* Create three concurrent threads . */
    for (i = 0; i < NUM_THREADS; i++)
    {
        pthread_create(&threads[i], NULL, periodic_task, &targs[i]);
    }

    /* Wait for the 3 threads to complete their executions . */
    for (i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
