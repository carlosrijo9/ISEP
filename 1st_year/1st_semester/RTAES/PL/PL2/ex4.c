#define _GNU_SOURCE
#define _XOPEN_SOURCE_EXTENDED 1
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
#include <sys/resource.h>
#include <sys/wait.h>

#define errExit(msg)        \
    do                      \
    {                       \
        perror(msg);        \
        exit(EXIT_FAILURE); \
    } while (0)

int main(int argc, char *argv[])
{

    cpu_set_t set;
    int parentCPU, childCPU;
    int nloops;

    if (argc != 4)
    {
        fprintf(stderr, "Usage: %s parent-cpu child-cpu num-loops\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    parentCPU = atoi(argv[1]);
    childCPU = atoi(argv[2]);
    nloops = atoi(argv[3]);

    CPU_ZERO(&set);
    switch (fork())
    {
    case -1:
        errExit("FORK");
        break;

    case 0:
        CPU_SET(childCPU, &set);
        if (sched_setaffinity(getpid(), sizeof(set), &set) == -1)
            errExit("sched_setaffinity");
        for (int j = 0; j < nloops; j++)
            getppid(); /* Just burning some time ... */
        exit(EXIT_SUCCESS);

        break;

    default:
        CPU_SET(parentCPU, &set);
        if (sched_setaffinity(getpid(), sizeof(set), &set) == -1)
            errExit("sched_setaffinity");
        for (int j = 0; j < nloops; j++)
            getppid(); /* Also just burning some time ... */
        wait(NULL);    /* Wait for child to terminate */
        exit(EXIT_SUCCESS);
        break;
    }
}
