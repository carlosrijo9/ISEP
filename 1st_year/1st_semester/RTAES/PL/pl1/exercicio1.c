#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        puts("Invalid format. Set priority");
        exit(1);
    }
    struct sched_param param;

    int priority_val, max_val, min_val;

    max_val = sched_get_priority_max(SCHED_FIFO);
    min_val = sched_get_priority_min(SCHED_FIFO);
    priority_val = atoi(argv[1]);

    if (priority_val >= min_val && priority_val <= max_val)
    {
        // printf("Set priority to: %d\n", priority_val);
        //param.sched_priority = sched_get_priority_max(SCHED_FIFO);
        param.sched_priority = priority_val;

        sched_setscheduler(getpid(), SCHED_FIFO, &param);
        while (1)
        {
            printf("[%d] I am here with priority %d!\n", getpid(), param.sched_priority);
            sleep(5);
        }
    }
    else if (priority_val < 1)
    {
        printf("Priority value mus be bigger than %d\n", min_val);
        exit(1);
    }
    else if (priority_val > 99)
    {
        printf("Priority value mus be smaller than %d\n", max_val);
        exit(1);
    }
}