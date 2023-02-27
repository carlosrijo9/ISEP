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
#define SERVER_PORT "10999"

int main(void)
{
    // Define local variables
    int fd_fromServer;
    int fd_toServer;

    // FIFO file path
    char *server_to_main = "/tmp/server_to_main";
    char *main_to_server = "/tmp/main_to_server";

    // Creating the named file(FIFO) (<pathname>, <permission>)
    mkfifo(server_to_main, 0666);
    mkfifo(main_to_server, 0666);

    struct sockaddr_storage client;
    char delim[] = " /";
    int count = 0;
    char msgCommand[BUF_SIZE] = "";
    char msgType[BUF_SIZE] = "2000";
    char msgVersion[BUF_SIZE] = "";
    char tempVAl[BUF_SIZE] = "0";

    struct sockaddr_storage from;
    int err, clientSock, sock, res;
    char line[BUF_SIZE];
    unsigned int adl;
    char cliIPtext[BUF_SIZE], cliPortText[BUF_SIZE];
    struct addrinfo req, *list;

    bzero((char *)&req, sizeof(req));
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
    // puts("Accepting TCP connections (IPv6/IPv4). Use CTRL+C to terminate the server");
    adl = sizeof(from);

    for (;;)
    {
        clientSock = accept(sock, (struct sockaddr *)&from, &adl);
        if (!fork())
        {
            close(sock);
            getnameinfo((struct sockaddr *)&from, adl, cliIPtext, BUF_SIZE,
                        cliPortText, BUF_SIZE, NI_NUMERICHOST | NI_NUMERICSERV);
            printf("New connection from %s, port number %s\n", cliIPtext, cliPortText);
            res = recvfrom(clientSock, line, BUF_SIZE, 0, (struct sockaddr *)&client, &adl);
            line[res] = 0; /* NULL terminate the string */
            printf("Message: %s\n", line);
            count = 0;
            char *p = strtok(line, delim);

            while (p != NULL)
            {
                if (count == 0)
                {
                    strcpy(msgCommand, p);
                    p = strtok(NULL, " ");
                }
                else if (count == 1)
                {
                    strcpy(msgType, p);
                    p = strtok(NULL, " ");
                }
                else if (count == 2)
                {
                    strcpy(msgVersion, p);
                    p = strtok(NULL, " ");
                }
                count++;
            }

            // printf("msgCommand: %s\n", msgCommand);
            // printf("msgType: %s\n", msgType);
            // printf("msgVersion: %s\n", msgVersion);

            if (strcasecmp(msgCommand, "CHECK") == 0)
                ;
            else if (strcasecmp(msgCommand, "GET") == 0)
            {
                fd_fromServer = open(server_to_main, O_RDONLY);
                read(fd_fromServer, tempVAl, 80);
                close(fd_fromServer);

                //printf("Temp: %s C\n", tempVAl);
                sendto(clientSock, tempVAl, BUF_SIZE, 0, (struct sockaddr *)&client, adl);
            }
            else if (strcasecmp(msgCommand, "PUT") == 0)
            {
                memmove(msgType, msgType + 1, strlen(msgType));
                printf("data rate %s\n", msgType);
                fd_toServer = open(main_to_server, O_WRONLY | O_NONBLOCK);
                write(fd_toServer, msgType, strlen(msgType) + 1);
                close(fd_toServer);
            }
            close(clientSock);
            printf("Connection %s, port number %s closed\n", cliIPtext, cliPortText);
            exit(0);
        }
        close(clientSock);
    }
    close(sock);
}