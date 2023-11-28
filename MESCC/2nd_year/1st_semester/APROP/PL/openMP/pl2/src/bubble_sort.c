#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <omp.h>

#define DEFAULT_NUM_THREADS 4
#define ARR_LEN 25000		 // The length of the array
#define MIN_VAL 0			 // Minimum value of the array elements
#define MAX_VAL ARR_LEN * 10 // Maximum value of the array elements

int  generate_random(int min, int max); // Generates a random integer within a specified range
void copy(int from[], int to[], int size); // Copies the contents of one array to another
void assert(int expected[], int result[], int size); // Compares two arrays to ensure they match, indicating whether the sorting algorithm produced the correct result
void print(int x[], int size);


/*
	Function to perform sequential bubble sort:
		Bubble sort repeatedly compares adjacent elements in the array and swaps them if they are out of order. This process continues until no more swaps
		are needed, indicating that the array is sorted.
*/
void sort_seq(int x[], int size)
{
	int i, changes = 1;
	while (changes)
	{
		changes = 0;
		for (i = 0; i < ARR_LEN - 1; i = i + 1)
		{
			if (x[i] > x[i + 1])
			{
				int tmp;
				tmp = x[i];
				x[i] = x[i + 1];
				x[i + 1] = tmp;
				++changes;
			}
		}
	}
}

/*
	Function to perform parallel bubble sort using OpenMP:
	    Inside the parallel for loop, each thread works on a separate portion of the array.
		The 'private(i)' clause ensures that each thread has its own 'i' variable.
		This parallelization allows multiple threads to perform bubble sort concurrently,potentially improving sorting performance on multi-core CPUs.
*/
void sort_par(int x[], int size, int num_threads)
{
	int i, changes = 1;
	while (changes)
	{
		changes = 0; // Reset the changes flag at the beginning of each pass.
		
		//Beginning of the parallel region with a parallelized for loop, where each thread will have a private copy of the loop variable 'i'
		#pragma omp parallel for private(i)
		for (i = 0; i < ARR_LEN - 1; i++) // Compare the current element with the next element.
		{
			/*
				If the current element is greater than the next element, swap them.
        		Swapping is done independently by each thread, avoiding conflicts.
			*/
			if (x[i] > x[i + 1])
			{
                int tmp = x[i];   // Temporary variable to hold the current element.
                x[i] = x[i + 1];  // Swap the current element with the next element.
                x[i + 1] = tmp;   // Update the next element with the temporary value.
                ++changes;        // Increment the changes flag to indicate a swap.
			}
		}
	}
}

/*
	These are global arrays declared outside of the main function to make them accessible throughout the code.
		original: Stores the original array of random integers before sorting.
    	x: Stores the array to be sorted.
    	expected: Stores the expected sorted result for comparison.
*/

// using globals to allow large arrays
int expected[ARR_LEN];
int original[ARR_LEN];
int x[ARR_LEN];
int main(int argc, char *argv[])
{
	srand(time(0)); // Seeds the random number generator based on the current time to ensure different random sequences each time the program runs.
	int num_threads = DEFAULT_NUM_THREADS;
	if (argc < 2)
	{
		printf("Number of threads was not specified. Will use default value: %d\n", DEFAULT_NUM_THREADS);
	}
	else
	{
		num_threads = atoi(argv[1]); // Generate random integers and store them in the 'original' array
	}
	printf("Working with %d threads to sort an array of size %d\n", num_threads, ARR_LEN);
	for (int i = 0; i < ARR_LEN; ++i)
	{
		original[i] = generate_random(MIN_VAL, MAX_VAL);
	}

	//-----Sequential sorting------------------------------------------------------------------------------
	copy(original, x, ARR_LEN); 				// Make a copy of the original array for sequential sorting
	printf("Sequential... ");
	double begin = omp_get_wtime();				// Record the start time
	sort_seq(x, ARR_LEN);						// Perform sequential sorting
	double end = omp_get_wtime();				// Record the end time
	double seq_time = (double)(end - begin);	// Calculate the time taken for sequential sorting
	printf("done.\n");
	copy(x, expected, ARR_LEN);					// Copy the sorted result to the 'expected' array

    //-----Parallel sorting--------------------------------------------------------------------------------
	copy(original, x, ARR_LEN);					// Reset the 'x' array to the original unsorted data
	printf("Parallel... ");
	begin = omp_get_wtime();					// Record the start time
	sort_par(x, ARR_LEN, num_threads);			// Perform parallel sorting
	end = omp_get_wtime();						// Record the end time
	double par_time = (double)(end - begin);	// Calculate the time taken for parallel sorting
	printf("done.\n");

	// Check if the results from sequential and parallel sorting match
	assert(x, expected, ARR_LEN);

	printf("\n- ==== Performance ==== -\n");
	printf("Sequential time: %fs\n", seq_time);
	printf("Parallel   time: %fs\n", par_time);

	return 0;
}

/****** Util. Functions *****************************************************/

/*----- Generate a random number ---------------------------------------*/
int generate_random(int min, int max)
{
	/* Generate a random number between min and max */
	return (rand() % (max - min + 1)) + min;
}

/*----- Function to copy an array from 'from' to 'to' ------------------*/
void copy(int from[], int to[], int size)
{
	for (int i = 0; i < size; i++)
	{
		to[i] = from[i];
	}
}

/*----- Function to compare two arrays and check for correctness -------*/
void assert(int expected[], int result[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (expected[i] != result[i])
		{
			printf("[ERROR]Bad result in position %d: expect %d, but %d was found.\n", i, expected[i], result[i]);
			exit(1);
		}
	}
}
/*----- Function to Print an Array -------------------------------------*/
void print(int x[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf(" %d", x[i]);
	}
	printf("\n");
}