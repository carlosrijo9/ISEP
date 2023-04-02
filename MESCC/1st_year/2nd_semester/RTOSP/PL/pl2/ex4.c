#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define NR_CLIENTS 100
#define NR_THREADS 3

// define a struct for the client information
typedef struct
{
    int number;
    char name[20];
    int balance;
} Client;

// define global variables for the client array and the signals
Client clients[NR_CLIENTS];
int signals[NR_CLIENTS];

// function to initialize the client array with random data
void initClients()
{
    time_t t;
    srand((unsigned)time(&t));
    for (int i = 0; i < NR_CLIENTS; i++)
    {
        clients[i].number = i + 1;
        sprintf(clients[i].name, "Client %d", i + 1);
        clients[i].balance = rand() % 201 - 100; // generate balance between -100 and 100
    }
}

// function to check for negative balances and signal each client
void *checkNegativeBalances(void *args)
{
    // loop over the clients array
    for (int i = 0; i < NR_CLIENTS; i++)
    {
        if (clients[i].balance < 0)
        {
            // set the corresponding signal to 1
            signals[i] = 1;
        }
    }

    // exit the thread
    pthread_exit(NULL);
}

// function to print the information of clients with negative balance
void *printNegativeClients(void *args)
{
    // loop over the clients array
    for (int i = 0; i < NR_CLIENTS; i++)
    {
        if (signals[i] == 1)
        {
            // print the client information
            printf("Client number: %d, name: %s, balance: %d\n", clients[i].number, clients[i].name, clients[i].balance);
        }
    }

    // exit the thread
    pthread_exit(NULL);
}

// function to eliminate negative balances
void *eliminateNegativeBalances(void *args)
{
    // loop over the clients array
    for (int i = 0; i < NR_CLIENTS; i++)
    {
        if (clients[i].balance < 0)
        {
            // set the balance to zero
            clients[i].balance = 0;
        }
    }

    // print statement of success
    printf("Negative balances eliminated. Program completed successfully.\n");

    // exit the thread
    pthread_exit(NULL);
}

// function to compute the average balance of all clients
void *computeAverageBalance(void *args)
{
    // declare variables for the sum and the count
    int sum = 0;
    int count = 0;

    // loop over the clients array
    for (int i = 0; i < NR_CLIENTS; i++)
    {
        sum += clients[i].balance;
        count++;
    }

    // compute the average balance
    float average = (float)sum / count;

    // check if the average is negative
    if (average < 0)
    {
        // create another thread to eliminate negative balances
        pthread_t eliminate_thread;
        pthread_create(&eliminate_thread, NULL, eliminateNegativeBalances, NULL);
        pthread_join(eliminate_thread, NULL);
    }
    else
    {
        // print statement of conformity and exit main thread
        printf("All clients have positive balance. Program completed successfully.\n");
        pthread_exit(NULL);
    }
}

int main()
{
    // initialize the client array with random data
    initClients();

    // initialize the signals array to zero
    for (int i = 0; i < NR_CLIENTS; i++)
    {
        signals[i] = 0;
    }
    // three threads
    pthread_t check_thread;
    pthread_t print_thread;
    pthread_t average_thread;

    // create the check thread
    pthread_create(&check_thread, NULL, checkNegativeBalances, NULL);

    // create the print thread
    pthread_create(&print_thread, NULL, printNegativeClients, NULL);

    // create the average thread
    pthread_create(&average_thread, NULL, computeAverageBalance, NULL);

    // join the three threads
    pthread_join(check_thread, NULL);
    pthread_join(print_thread, NULL);
    pthread_join(average_thread, NULL);

    // exit the program
    return 0;
}