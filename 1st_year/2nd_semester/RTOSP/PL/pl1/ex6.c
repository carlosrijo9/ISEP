#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <time.h>

int Rand_Numb_Gen()
{
    srand((unsigned int)time(NULL));
    int Rand_Number;
    Rand_Number = rand() % 6;
    return Rand_Number;
}

int main(void)
{
    // Create fork
    pid_t pid = fork();
    if (pid == -1)
    {
        perror("fork");
        return 1;
    }
    else if (pid == 0)
    { // Child process
        int Rand_Number = Rand_Numb_Gen();
        printf("[child] pid %d created\n", getpid());
        //printf("Rand value: %d\n", Rand_Number);
        return Rand_Number;
    }
    int Rand_Number_W;
    int status;
    wait(&status);
    Rand_Number_W = WEXITSTATUS(status);
    printf("Goal: create %d child processes\n", Rand_Number_W);

    for (int i = 0; i < Rand_Number_W; i++)
    {
        pid = fork();
        if (pid == -1)
        {
            perror("fork");
            exit(1);
        }
        else if (pid == 0)
        {
            printf("[child nr %d] pid %d created from %d\n", i + 1, getpid(), getppid());
            exit(0);
        }
    }

    // Wait for child processes with odd PID
    for (int i = 0; i < Rand_Number_W; i++)
    {
        int status;
        pid_t pid = wait(&status);
        printf("Child process with PID %d has terminated\n", pid);
    }
    printf("All child processes terminated\n");
    return 0;
}