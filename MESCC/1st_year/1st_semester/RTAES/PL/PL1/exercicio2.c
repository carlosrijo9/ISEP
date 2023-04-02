#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>

int main()
{
    cpu_set_t mask;

    /* Set affinity to the 2nd core -> {0 , 1 , 2 , 3} */
    CPU_ZERO(&mask);
    CPU_SET(1, &mask);

    if (sched_setaffinity(getpid(), sizeof(cpu_set_t), &mask) == -1)
    {
        perror(" set_affinity : ");
    }
    while (1)
    {
        printf("[%d] I am here !\n", getpid());
        sleep(5);
    }
}