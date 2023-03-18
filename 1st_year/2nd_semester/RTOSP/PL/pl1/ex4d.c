#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef struct {
    pid_t pid;
    int order;
} child_pid;

int main()
{
    int n_processes = 4;
    child_pid child_processes[n_processes];

    for (int i = 0; i < n_processes; i++) {
        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(1);
        }
        else if (pid == 0) {
            printf("[child] pid %d, order %d\n", getpid(), i + 1);
            exit(i + 1);
        }
        else {
            child_processes[i].pid = pid;
            child_processes[i].order = i + 1;
        }
    }

    // Wait for all child processes to terminate and print their PID and creation order
    for (int i = 0; i < n_processes; i++) {
        int status;
        pid_t pid = wait(&status);
        if (pid != -1) {
            int order = WEXITSTATUS(status);
            for (int j = 0; j < n_processes; j++) {
                if (child_processes[j].pid == pid) {
                    printf("Child process with order %d and PID %d has terminated\n", child_processes[j].order, pid);
                    break;
                }
            }
        }
    }

    printf("[Parent] pid %d\n", getppid()); // just to show parent
    return 0;
}
