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

int parser(char *line)
{
    // the following function receives a string and returns an identifier to its representation
    // 0 – binary text (only has 0s and 1s)
    // 1 – normal text
    // 2 – operation
    int ret, ret2;
    regex_t regex, regex2;

    // to use regular expressions, first you need to compile the regular expression using regcomp that is stored in a regex_t type
    // the following regular expression ("[01]+$” represents all strings that are constituted only by 0s and 1s. “[01]” indicates that strings can only have 0s and 1s, + sign indicates that the empty string is not valid and $ tells the search to continue until the end of string (avoids cases like “0111023”).
    ret = regcomp(&regex, "[01]+$", REG_EXTENDED);
    if (ret)
    {
        fprintf(stderr, "Could not compile regex\n");
        exit(1);
    }
    // the following regular expression “[a-zA-Z]” represents all strings that have at least a letter
    ret2 = regcomp(&regex2, "[a-zA-Z]", REG_EXTENDED);
    if (ret2)
    {
        fprintf(stderr, "Could not compile regex\n");
        exit(1);
    }

    // after compiling the regex then you can use it in a regexec function to compare with the string that needs to be analysed
    ret = regexec(&regex, line, 0, NULL, 0);
    ret2 = regexec(&regex2, line, 0, NULL, 0);

    if (!ret)
    {
        return 0;
    }
    else if (ret == REG_NOMATCH && !ret2)
    {
        return 1;
    }
    return 2;
}

int main(void)
{
    struct sockaddr_storage client;
    int err, sock, res, i;

    int out;
    int bin_num, decimal_num, base = 1, rem;
    int result, num1, num2;
    char operator= '.';
    unsigned int adl;

    char delim[] = "/";

    char message = [3];
    char line[BUF_SIZE], line1[BUF_SIZE];
    char cliIPtext[BUF_SIZE], cliPortText[BUF_SIZE];
    struct addrinfo req, *list;
    bzero((char *)&req, sizeof(req));

    req.ai_family = AF_INET6; // request a IPv6 local address will allow both IPv4 and IPv6 clients to use it
    req.ai_socktype = SOCK_DGRAM;
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
    adl = sizeof(client);

    while (1)
    {
        res = recvfrom(sock, line, BUF_SIZE, 0, (struct sockaddr *)&client, &adl);
        line[res] = 0; /* NULL terminate the string */

        printf("Message: %s\n", line);
        // printf("Size: %d\n", res);
        // printf("Command: %s\n", cmd);
        // printf("Key: %s\n", key);
        // printf("Value: %s\n", value);

        unsigned count = 0;
        char *token = strtok(line, delim);
        printf("Command: %s\n", token);
        token = strtok(NULL, delim);
        printf("key: %s\n", token);
        token = strtok(NULL, delim);
        printf("value: %s\n", token);
        count++;

        while (token != NULL)
        {
            message[count] = token;
            //input_cmd = token;
            printf("Token no. %d : %s \n", count, token);
            token = strtok(NULL, delim);
            count++;
            printf("array: %s \n",message);
        }

        if (!getnameinfo((struct sockaddr *)&client, adl,
                         cliIPtext, BUF_SIZE, cliPortText, BUF_SIZE, NI_NUMERICHOST | NI_NUMERICSERV))
            ;
        // printf("Request from node %s, port number %s\n", cliIPtext, cliPortText);
        else
            puts("Got request, but failed to get client address");
        for (i = 0; i < res; i++)
            line1[res - 1 - i] = line[i]; // create a mirror of the text line
        sendto(sock, line1, res, 0, (struct sockaddr *)&client, adl);
    }

    close(sock);
    exit(0);
}

