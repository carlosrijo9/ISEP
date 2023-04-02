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
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>
#include <fcntl.h>
#include <sys/wait.h>

// Define global variables
#define BUF_SIZE 300
#define SERVER_PORT "10998"
// #define SERVER_PORT "10997"
// #define SERVER_PORT "10996"

int main(void)
{
    // Define local variables
    char(*global_message)[100];
    global_message = mmap(NULL, sizeof *global_message, PROT_READ | PROT_WRITE,
                          MAP_SHARED | MAP_ANONYMOUS, -1, 0);

    int fd_toMain;
    int fd_fromMain;

    // FIFO file path
    char *server_to_main = "/tmp/server_to_main";
    char *main_to_server = "/tmp/main_to_server";

    // Creating the named file(FIFO) (<pathname>, <permission>)
    mkfifo(server_to_main, 0666);
    mkfifo(main_to_server, 0666);

    char arr1[BUF_SIZE];

    struct KVStore
    {
        char mac[100];
        char key[100];
        char value[100];
    };
    char delim[] = "/";
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
    int err, deviceSock, sock, res;
    unsigned int adl;
    char cliIPtext[BUF_SIZE], cliPortText[BUF_SIZE];
    struct addrinfo req, *list;
    bzero((char *)&req, sizeof(req));
    char line[BUF_SIZE], msg_rate[BUF_SIZE];
    char sh_mem_cmd[BUF_SIZE];
    char msg_rcv[BUF_SIZE];
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
    puts("Accepting TCP IPv4 connections. Use CTRL+C to terminate the server");
    adl = sizeof(from);
    for (;;)
    {
        deviceSock = accept(sock, (struct sockaddr *)&from, &adl);
        if (!fork())
        {
            close(sock);
            getnameinfo((struct sockaddr *)&from, adl, cliIPtext, BUF_SIZE,
                        cliPortText, BUF_SIZE, NI_NUMERICHOST | NI_NUMERICSERV);
            printf("Connection with %s:%s Opened\n", cliIPtext, cliPortText);

            res = recvfrom(deviceSock, line, BUF_SIZE, 0, (struct sockaddr *)&client, &adl);
            line[res] = 0; /* NULL terminate the string */

            strcpy(*global_message, line);

            close(deviceSock);
            printf("Connection with %s:%s Closed\n", cliIPtext, cliPortText);
            exit(0);
        }

        wait(NULL);
        strcpy(msg_rcv, *global_message);
        // printf("Message: %s\n", msg_rcv);
        strcpy(message.key, "");
        strcpy(message.value, "");

        count = 0;
        char *p = strtok(msg_rcv, delim);

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
        if (strcmp(message.key, "") == 0)
            ;
        else
        {
            mac_found = 0;
            for (int f = 0; f < structureSize; f++)
            {
                if (strcmp(message.mac, kv[f].mac) == 0)
                {
                    strcpy(kv[f].key, message.key);
                    strcpy(kv[f].value, message.value);
                    // printf("Replaced at position %d\n", f);
                    // printf("%s -> %s -> %s\n", kv[f].mac, kv[f].key, kv[f].value);
                    mac_found = 1;
                    structureSize--;
                }
            }
            if (mac_found == 0)
            {
                strcpy(kv[structureSize - 1].mac, message.mac);
                strcpy(kv[structureSize - 1].key, message.key);
                strcpy(kv[structureSize - 1].value, message.value);
                // printf("Added at position %d\n", structureSize - 1);
                // printf("%s -> %s -> %s\n", kv[structureSize - 1].mac, kv[structureSize - 1].key, kv[structureSize - 1].value);
            }
        }

        // Make average of Temperatures
        nrSensors = structureSize;
        for (int g = 0; g < structureSize; g++)
        {
            if (strcmp(kv[g].key, "none") == 0)
            {
                nrSensors--;
            }
            else
            {
                sumTemp += atof(kv[g].key);
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

        // Share with Main Server
        sprintf(arr1, "%.2f", averageTemp);
        fd_toMain = open(server_to_main, O_WRONLY | O_NONBLOCK);
        write(fd_toMain, arr1, strlen(arr1) + 1);
        close(fd_toMain);

        fd_fromMain = open(main_to_server, O_RDONLY | O_NONBLOCK);
        read(fd_fromMain, msg_rate, 80);
        close(fd_fromMain);

        close(deviceSock);
    }
    free(kv);
    close(sock);
    exit(0);
}
