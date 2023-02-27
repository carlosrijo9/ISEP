#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sched.h>
#define NUM_THREADS 4
#define TARGET_CORE 2
#define CEILING 3

/* Global mutex , accessible to all threads . */
pthread_mutex_t mutex;

struct task_sched
{
    int priority;
    int core;
    struct timespec period;
    struct timespec first_arrival;
    struct timespec TimeNow;
};

int set_task_priority(int priority)
{
    struct sched_param params;
    int retval;

    /* Set thread priority under SHED_FIFO scheduler . */
    params.sched_priority = priority;
    retval = pthread_setschedparam(pthread_self(), SCHED_FIFO, &params);

    return retval; /* 0 if success . */
}

int set_task_affinity(int core)
{
    cpu_set_t cores_mask;
    int retval;

    /* Set affinity of thread to cores -> {0 , 1 , 2 , 3} */
    CPU_ZERO(&cores_mask);
    CPU_SET(TARGET_CORE, &cores_mask);
    retval = pthread_setaffinity_np(pthread_self(), sizeof(cores_mask), &cores_mask);

    return retval; /* 0 if success . */
}

struct timespec next_arrival(struct timespec previous, struct timespec period)
{
    struct timespec next;

    next.tv_sec = previous.tv_sec + period.tv_sec;    /* Seconds */
    next.tv_nsec = previous.tv_nsec + period.tv_nsec; /* Nanoseconds*/

    if (next.tv_nsec > 1000000000L)
    {
        /* Nanoseconds can not exceed one second . */
        next.tv_nsec -= 1000000000L;
        next.tv_sec++;
    }
    return next;
}

void *periodic_task(void *arg)
{
    struct task_sched *targs;
    struct timespec next, period;
    struct timespec TimeNow, Timefirstt2, Timefirstt3, Timefirstt1, Timefirstt4;
    int i, dummy_cycles = 40000;
    int job, number_jobs;

    /* Read parameters from arg . */
    targs = (struct task_sched *)arg;

    period = targs->period;
    next = targs->first_arrival;

    number_jobs = 1000000000 / targs->period.tv_nsec;

    /* Set affinity of thread to cores -> {0 , 1 , 2 , 3} */
    set_task_affinity(targs->core);

    /* Set thread priority under SHED_FIFO scheduler . */
    set_task_priority(targs->priority);

    /* Sleep until the first arrival time . */
    clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &next, 0);

    for (job = 1; job <= number_jobs; job++)
    {
        /* Do some work , burn some clock cycles . */
        switch (targs->priority)
        {
        case 4:
            /* High priority job . */
            clock_gettime(CLOCK_MONOTONIC, &Timefirstt4);
            pthread_mutex_lock(&mutex);
            for (i = 0; i < 500; i++) // 200000
            {
                getpid();
            }
            pthread_mutex_unlock(&mutex);
            clock_gettime(CLOCK_MONOTONIC, &TimeNow);
            if ((TimeNow.tv_nsec - 50000000) > Timefirstt4.tv_nsec)
            {
                printf("Deadline Aperiodicas Missed \n\n\n");
                break;
            }
            break;

        case 3:
            /* High priority job . */
            clock_gettime(CLOCK_MONOTONIC, &Timefirstt1);

            pthread_mutex_lock(&mutex);
            for (i = 0; i < 200000; i++) // 200000
            {
                getpid();
            }
            pthread_mutex_unlock(&mutex);
            clock_gettime(CLOCK_MONOTONIC, &TimeNow);
            if ((TimeNow.tv_nsec - 100000000) > Timefirstt1.tv_nsec)
            {
                printf("Deadline 1 Missed \n\n\n");
                break;
            }
            break;

        case 2:
            /* Intermediate priority job . */
            clock_gettime(CLOCK_MONOTONIC, &Timefirstt2);
            for (i = 0; i < 400000; i++)
            {
                getpid();
            }
            clock_gettime(CLOCK_MONOTONIC, &TimeNow);
            if ((TimeNow.tv_nsec - 150000000) > Timefirstt2.tv_nsec)
            {
                printf("Deadline 2 Missed \n\n\n");
                break;
            }
            break;

        case 1:
            //* Low priority job
            clock_gettime(CLOCK_MONOTONIC, &Timefirstt3);
            pthread_mutex_lock(&mutex);
            for (i = 0; i < 1000000; i++)
            {
                getpid();
            }
            pthread_mutex_unlock(&mutex);
            clock_gettime(CLOCK_MONOTONIC, &TimeNow);
            if ((TimeNow.tv_nsec - 350000000) > Timefirstt3.tv_nsec)
            {
                printf("Deadline 3 Missed \n\n\n");
                break;
            }
            break;

        default:
            break;
        }

        /* Set timer for next activation . */
        next = next_arrival(next, period);

        clock_nanosleep(CLOCK_MONOTONIC,
                        TIMER_ABSTIME, &next, 0);
    }
}

int main()
{
    struct task_sched targs[NUM_THREADS];
    pthread_t threads[NUM_THREADS];
    int i;
    struct timespec first_arrival;
    pthread_mutexattr_t mutex_attr;

    /* Create and initialize the mutex . */
    pthread_mutexattr_init(&mutex_attr);
    pthread_mutexattr_setprotocol(&mutex_attr, PTHREAD_PRIO_INHERIT);
    pthread_mutex_init(&mutex, &mutex_attr);
    pthread_mutexattr_destroy(&mutex_attr);

    /* Set the time instant when tasks will arrive (in less than 2 seconds ). */
    clock_gettime(CLOCK_MONOTONIC, &first_arrival);
    first_arrival.tv_nsec += 100000000;
    first_arrival.tv_sec += first_arrival.tv_nsec / 1000000000L;
    first_arrival.tv_nsec = first_arrival.tv_nsec % 1000000000L;

    /* HIGH priority task . */
    targs[1].priority = 3;
    targs[1].core = TARGET_CORE;
    targs[1].period.tv_sec = 0;
    targs[1].period.tv_nsec = 300000000; /* 300 ms */
    targs[1].first_arrival = first_arrival;

    /* LOW priority task . */
    targs[2].priority = 1;
    targs[2].core = TARGET_CORE;
    targs[2].period.tv_sec = 0;
    targs[2].period.tv_nsec = 900000000; /* 900 ms */
    targs[2].first_arrival = first_arrival;

    /* INTERMEDIATE priority task . */
    targs[3].priority = 2;
    targs[3].core = TARGET_CORE;
    targs[3].period.tv_sec = 0;
    targs[3].period.tv_nsec = 800000000; /* 800 ms */
    targs[3].first_arrival = first_arrival;

    /* Create three concurrent threads . */
    for (i = 0; i < NUM_THREADS; i++)
    {
        pthread_create(&threads[i], NULL, periodic_task, &targs[i]);
    }
    /* Wait for the 4 threads to complete their executions . */
    for (i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    return 0;
}