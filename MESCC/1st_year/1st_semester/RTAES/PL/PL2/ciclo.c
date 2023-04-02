#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[])
{

    unsigned long int i, n;

    if (argc > 2)
    {
        printf("Usage : %s number-of-iterations\n\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    else if (argc == 1)
    {
        n = 1000000;
        printf("Default number of iterations:1000000\n");
    }
    else if (sscanf(argv[1], "%lu", &n) != 1)
    {
        printf("Usage : %s number-of-iterations\n\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    printf(" [%d] Starting loop (%lu iterations)...\n ", getpid(), n);
    for (i = 0; i < n; i++)
    {
        getpid();
    }
    printf("[%d] Finished loop (%lu iterations)!\n ", getpid(), n);
    return 0;
}