#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int n_processes = 4;
    for (int i = 0; i < n_processes; i++)
    {
        pid_t pid = fork();
        if (pid == -1)
        {
            perror("fork");
            exit(1);
        }
        else if (pid == 0)
        {
            printf("[child] pid %d\n", getpid());
            exit(0);
        }
    }

    // Wait for child processes with odd PID
    for (int i = 0; i < n_processes; i++)
    {
        int status;
        pid_t pid = wait(&status);
        if (pid != -1 && pid % 2 == 1)
        {
            printf("Child process with odd PID %d has terminated\n", pid);
        }
    }

    printf("[Parent] pid %d\n", getppid()); // just to show parent
    return 0;
}
