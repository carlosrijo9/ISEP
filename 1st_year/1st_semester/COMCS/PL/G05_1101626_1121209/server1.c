/********************************/
/*		ISEP MESCC COMCS		*/
/*                              */
/*  Group 5                     */
/*    -> Carlos Rijo - 1101626  */
/*    -> Eduardo Maia - 1121209 */
/*                              */
/********************************/

// Include Libraries
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <sys/msg.h>

// Define global variables
#define BUF_SIZE 300
#define SERVER_PORT "10998"
//#define SERVER_PORT "10997"
//#define SERVER_PORT "10996"

struct mesg_buffer {
    long mesg_type;
    char mesg_text[100];
} sharedMem;

int main(void)
{    
    // Define local variables
    struct KVStore
    {
        char mac[100];
        char key[100];
        char value[100];
    };
    char delim[] = "/";
    int f = 0;
    int count = 0;
    int number_of_keys = 10;
    int structureSize = 0;
    struct KVStore *kv = malloc(sizeof(struct KVStore) * number_of_keys);
    int mac_found = 0;

    struct messageStore
    {
        char mac[100];
        char key[100];
        char value[100];
    } message;

    if (kv == NULL)
    {
        perror("Malloc");
        exit(EXIT_FAILURE);
    }

    float averageTemp = 0;
    float sumTemp = 0;
    int nrSensors = 0;

    /******************/
    struct sockaddr_storage from;
    struct sockaddr_storage client;
    unsigned long num;
    int err, deviceSock, sock, res;
    unsigned int adl;
    char cliIPtext[BUF_SIZE], cliPortText[BUF_SIZE];
    struct addrinfo req, *list;
    bzero((char *)&req, sizeof(req));
    char line[BUF_SIZE], msg_rate[BUF_SIZE];
    // requesting an IPv4 type of communication
    req.ai_family = AF_INET;
    req.ai_socktype = SOCK_STREAM;
    req.ai_flags = AI_PASSIVE; // local address
    err = getaddrinfo(NULL, SERVER_PORT, &req, &list);
    
    if (err)
    {
        printf("Failed to get local address, error: %s\n", gai_strerror(err));
        exit(1);
    }

    sock = socket(list->ai_family, list->ai_socktype, list->ai_protocol);
    
    if (sock == -1)
    {
        perror("Failed to open socket");
        freeaddrinfo(list);
        exit(1);
    }

    if (bind(sock, (struct sockaddr *)list->ai_addr, list->ai_addrlen) == -1)
    {
        perror("Bind failed");
        close(sock);
        freeaddrinfo(list);
        exit(1);
    }

    freeaddrinfo(list);
    listen(sock, SOMAXCONN);
    puts("Accepting TCP connections (IPv6/IPv4). Use CTRL+C to terminate the server");
    adl = sizeof(from);
    for (;;)
    {
        deviceSock = accept(sock, (struct sockaddr *)&from, &adl);
        if (!fork())
        {
            close(sock);
            getnameinfo((struct sockaddr *)&from, adl, cliIPtext, BUF_SIZE,
                        cliPortText, BUF_SIZE, NI_NUMERICHOST | NI_NUMERICSERV);
            printf("New connection from %s, port number %s\n", cliIPtext, cliPortText);

            do
            {
                res = recvfrom(deviceSock, line, BUF_SIZE, 0, (struct sockaddr *)&client, &adl);
                line[res] = 0; /* NULL terminate the string */
                
                //printf("Message: %s\n", line);
                strcpy(message.key, "");
                strcpy(message.value, "");

                count = 0;
                char *p = strtok(line, delim);

                while (p != NULL)
                {
                    if (count == 0)
                    {
                        strcpy(message.mac, p);
                        p = strtok(NULL, delim);
                    }
                    else if (count == 1)
                    {
                        strcpy(message.key, p);
                        p = strtok(NULL, delim);
                    }
                    else if (count == 2)
                    {
                        strcpy(message.value, p);
                        p = strtok(NULL, delim);
                    }
                    count++;
                }
                // printf("message.mac: %s\n", message.mac);
                // printf("message.key: %s\n", message.key);
                // printf("message.value: %s\n", message.value);

                structureSize++;
                mac_found = 0;
                for (f = 0; f < structureSize; f++)
                {
                    if (strcmp(message.mac, kv[f].mac) == 0)
                    {
                        strcpy(kv[f].key, message.key);
                        strcpy(kv[f].value, message.value);
                        printf("Replaced at position %d\n", f);
                        printf("%s -> %s -> %s\n", kv[f].mac, kv[f].key, kv[f].value);
                        mac_found = 1;
                        structureSize--;
                    }
                }
                if (mac_found == 0)
                {
                    strcpy(kv[structureSize - 1].mac, message.mac);
                    strcpy(kv[structureSize - 1].key, message.key);
                    strcpy(kv[structureSize - 1].value, message.value);
                    printf("Added at position %d\n", f);
                    printf("%s -> %s -> %s\n", kv[structureSize - 1].mac, kv[structureSize - 1].key, kv[structureSize - 1].value);
                }

                // TODO
                // 1 - get shared memory from main
                // 2 - send to device 
                              
                // printf("data rate %s\n", sharedMem.mesg_text);
                // strcpy(msg_rate, sharedMem);
                // sendto(deviceSock, msg_rate, BUF_SIZE, 0, (struct sockaddr *)&client, adl);
                
                // Make average of Temperatures
                nrSensors = structureSize;
                for (f = 0; f < structureSize; f++)
                {
                    if (strcmp(kv[f].key, "none") == 0)
                    {
                        nrSensors--;
                    }
                    else if (strcmp(kv[f].key, "") == 0)
                    {
                        nrSensors--;
                    }
                    else
                    {
                        sumTemp += atof(kv[f].key);
                    }
                }
                if (nrSensors > 0)
                {
                    averageTemp = sumTemp / nrSensors;
                }
                else
                {
                    averageTemp = 0;
                }
                sumTemp = 0;

                // TODO
                // 1 - send shared memory to main

                // sprintf(sharedMem, "%.2f", averageTemp);

            } while (num);

            close(deviceSock);
            printf("Connection %s, port number %s closed\n", cliIPtext, cliPortText);
            exit(0);
        }
        close(deviceSock);
    }
    close(sock);
}