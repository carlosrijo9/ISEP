#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
    int x = 0;
    pid_t p = fork();
    if (p == 0) // Child run
    {
        x = x + 2;
        printf("Step 1. x = %d\n", x);
    }
    else // Parent Run
    {
        x = x - 2;
        printf("Step 2. x = %d\n", x);
    }
    printf("Step 3. %d; x = %d\n", p, x);
}