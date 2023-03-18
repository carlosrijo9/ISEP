#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdint.h>

int main(void)
{
    // Declare an array of 500 unsigned 8-bit integers since the range is [0,255] in order to save memory
    uint8_t array[500];

    // Iterate through the array and assign each element a random value in the range of [0, 255]
    for (int i = 0; i < sizeof(array); i++)
    {
        array[i] = rand() % 256; // Assign a random value to the current element
        //printf("%d \n", array[i]);
    }
    return 0;
}
