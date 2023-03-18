#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	int n_processes = 4;
	for (int i = 0; i < n_processes; i++) // loop will run 4 times
	{
		if (fork() == 0)
		{
			printf("[child] pid %d\n", getpid());
			exit(0); // exit child process
		}
	}
	printf("[Parent] pid %d\n", getppid()); // just to show parent
}
