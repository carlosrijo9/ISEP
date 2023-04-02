#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdint.h>

// Find the local maximum value of a part of the array
uint8_t find_local_max(uint8_t *array, int start_index, int end_index)
{
    uint8_t local_max = 0;
    for (int i = start_index; i < end_index; i++)
    {
        if (array[i] > local_max)
        {
            local_max = array[i];
        }
    }
    return local_max;
}

int main(void)
{
    // Declare an array of 500 unsigned 8-bit integers since the range is [0,255] in order to save memory
    uint8_t array[500];
    int NUM_CHILDREN = 5;

    // Iterate through the array and assign each element a random value in the range of [0, 255]
    for (int i = 0; i < sizeof(array); i++)
    {
        array[i] = rand() % 256; // Assign a random value to the current element
        // printf("%d \n", array[i]);
    }

    // Fork child processes
    int i;
    for (i = 0; i < NUM_CHILDREN; i++)
    {
        pid_t pid = fork();
        if (pid == -1)
        {
            perror("fork");
            return 1;
        }
        else if (pid == 0)
        { // Child process
            int start_index = i * (sizeof(array) / NUM_CHILDREN);
            int end_index = (i + 1) * (sizeof(array) / NUM_CHILDREN);
            uint8_t local_max = find_local_max(array, start_index, end_index);
            printf("Child %d local max value: %d\n", i, local_max);
            return local_max;
        }
    }

    // Wait for child processes to finish and collect local max values
    uint8_t local_max_vals[NUM_CHILDREN];
    for (i = 0; i < NUM_CHILDREN; i++)
    {
        int status;
        wait(&status);
        local_max_vals[i] = WEXITSTATUS(status);
    }

    // Find global maximum value
    uint8_t global_max_val = 0;
    for (i = 0; i < NUM_CHILDREN; i++)
    {
        if (local_max_vals[i] > global_max_val)
        {
            global_max_val = local_max_vals[i];
        }
    }

    // Print the global maximum value
    printf("Global max value: %d\n", global_max_val);

    return 0;
}
