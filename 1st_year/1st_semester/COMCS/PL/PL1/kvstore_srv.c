#include <strings.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <regex.h>
#include <math.h>
#include <string.h>

#define BUF_SIZE 300
#define SERVER_PORT "10999"

int main(void)
{
    struct sockaddr_storage client;
    int err, sock, res;
    int count = 0;
    unsigned int adl;
    char line[BUF_SIZE];
    char cliIPtext[BUF_SIZE], cliPortText[BUF_SIZE];
    struct addrinfo req, *list;
    bzero((char *)&req, sizeof(req));

    req.ai_family = AF_INET6; // request a IPv6 local address will allow both IPv4 and IPv6 clients to use it
    req.ai_socktype = SOCK_DGRAM;
    req.ai_flags = AI_PASSIVE; // local address
    err = getaddrinfo(NULL, SERVER_PORT, &req, &list);

    struct KVStore
    {
        char key[100];
        char value[100];
    };
    char delim[] = "/";
    // char *message [3] = malloc();
    int f = 0;
    int number_of_keys = 10;
    int structureSize = 0;
    struct KVStore *kv = malloc(sizeof(struct KVStore) * number_of_keys);

    struct messageStore
    {
        char command[100];
        char key[100];
        char value[100];
    } message;

    // if (kv == NULL) {
    //     perror("Malloc");
    //     exit(EXIT_FAILURE);
    // }

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
    adl = sizeof(client);

    while (1)
    {
        res = recvfrom(sock, line, BUF_SIZE, 0, (struct sockaddr *)&client, &adl);
        line[res] = 0; /* NULL terminate the string */

        printf("Message Received: %s\n", line);

        count = 0;
        char *p = strtok(line, delim);

        while (p != NULL)
        {
            if (count == 0)
            {
                strcpy(message.command, p);
                p = strtok(NULL, "/");
            }
            else if (count == 1)
            {
                strcpy(message.key, p);
                p = strtok(NULL, "/");
            }
            else if (count == 2)
            {
                strcpy(message.value, p);
                p = strtok(NULL, "/");
            }
            count++;
        }

        // printf("Command: %s\n", message.command);
        // printf("Key: %s\n", message.key);
        // printf("Value: %s\n", message.value);

        if (strcmp(message.command, "insert") == 0)
        {
            for (f = 0; f < structureSize; f++)
            {
                if (strcmp(message.key, kv[f].key) == 0)
                {
                    strcpy(kv[structureSize].value, message.value);
                    printf("Key %s with value %s added at position %d\n", kv[structureSize].key, kv[structureSize].value, f);
                    // sendto(sock, kv[f].key, res, 0, (struct sockaddr *)&client, adl);
                    // sendto(sock, kv[f].value, res, 0, (struct sockaddr *)&client, adl);
                }
                else
                {
                    strcpy(kv[structureSize].key, message.key);
                    strcpy(kv[structureSize].value, message.value);
                    printf("Key %s with value %s added at position %d\n", kv[structureSize].key, kv[structureSize].value, structureSize);
                }
            }

            // strcpy(kv[structureSize].key, message.key);
            // strcpy(kv[structureSize].value, message.value);
            structureSize++;
            sendto(sock, "Success", res, 0, (struct sockaddr *)&client, adl);
        }
        else if (strcmp(message.command, "get") == 0)
        {
            for (f = 0; f < structureSize; f++)
            {
                if (strcmp(message.key, kv[f].key) == 0)
                {
                    printf("Key: %s\n", kv[f].key);
                    printf("Value: %s\n", kv[f].value);
                    sendto(sock, kv[f].key, res, 0, (struct sockaddr *)&client, adl);
                    sendto(sock, kv[f].value, res, 0, (struct sockaddr *)&client, adl);
                }
                else if (strcmp(message.key, "all") == 0)
                {
                    printf("Key %s with value %s added at position %d\n", kv[f].key, kv[f].value, f);
                }
            }
            
        }
        else if (strcmp(message.command, "delete") == 0)
        {
            printf("delete aa\n");
        }
        else
            printf("wrong command\n");

        if (!getnameinfo((struct sockaddr *)&client, adl,
                         cliIPtext, BUF_SIZE, cliPortText, BUF_SIZE, NI_NUMERICHOST | NI_NUMERICSERV))
            ;
        // printf("Request from node %s, port number %s\n", cliIPtext, cliPortText);
        else
            puts("Got request, but failed to get client address");
        // for (i = 0; i < res; i++)
        //     line1[res - 1 - i] = line[i]; // create a mirror of the text line
        // sendto(sock, line1, res, 0, (struct sockaddr *)&client, adl);
    }

    free(kv);
    close(sock);
    exit(0);
}
