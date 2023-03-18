#include <stdio.h>
#include <unistd.h>

int main(void)
{
    fork();
    fork();
    printf("MESCC 1\n");
    fork();
    printf("MESCC 2\n");
}
