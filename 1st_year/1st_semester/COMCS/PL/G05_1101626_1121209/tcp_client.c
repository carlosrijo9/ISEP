/********************************/
/*		ISEP MESCC COMCS		*/
/*                              */
/*  Group 5                     */
/*    -> Carlos Rijo - 1101626  */
/*    -> Eduardo Maia - 1121209 */
/*                              */
/********************************/

// Include Libraries
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

// Define global variables
#define BUF_SIZE 100
#define SERVER_PORT "10999"
#define SEPARATOR ' '

// Read a string from stdin protecting buffer overflow
#define GETS(B, S)              \
	{                           \
		fgets(B, S - 2, stdin); \
		B[strlen(B) - 1] = 0;   \
	}

int main(int argc, char **argv)
{
	// Define local variables
	char cmd[BUF_SIZE];
	char msg_rate[BUF_SIZE];
	int err, sock, res = 0, i;
	unsigned int srv_addr_len;
	char line[BUF_SIZE], message[200];
	struct sockaddr_storage *srv_addr;
	struct addrinfo req, *list, *p;
	socklen_t *srv_addr_len_ptr = &srv_addr_len;

	char *get_msg = "GET /temperature HTTP/1.0";
	//char *put_msg = "PUT /%s HTTP/1.0";

	memset(&req, 0, sizeof(req));

	// Let getaddrinfo set the family depending on the supplied server address
	req.ai_family = AF_UNSPEC;
	req.ai_socktype = SOCK_STREAM;
	req.ai_protocol = IPPROTO_TCP;

	err = getaddrinfo(argv[1], argv[2], &req, &list);

	if (err)
	{
		printf("Failed to get server address, error: %s\n", gai_strerror(err));
		exit(1);
	}

	for (p = list; p != 0; p = p->ai_next)
	{
		// Initialize socket
		sock = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
		if (sock < 0)
			continue;
		// Initialize connection
		err = connect(sock, p->ai_addr, (socklen_t)p->ai_addrlen);
		if (err == 0)
			break;
		close(sock);
		sock = -1;
	}

	if (sock < 0)
	{ // Error creating/connecting socket
		perror("Error creating/connecting socket");
		exit(1);
	}

	// Store the server address for later use when sending requests
	srv_addr_len = list->ai_addrlen;
	memcpy(&srv_addr, list->ai_addr, srv_addr_len);
	freeaddrinfo(list);

	// Get command from GUI
	strncpy(cmd, argv[3], 5);

	// Check command
	if (strcmp(cmd, "check") == 0)
	{
		exit(0);
	}
	else if (strcmp(cmd, "get") == 0)
	{
		// Send GET message
		sendto(sock, get_msg, strlen(get_msg), 0, (struct sockaddr *)&srv_addr, srv_addr_len);
		
		for (i = 0; i < BUF_SIZE; i++)
			line[i] = 0;
		res = recvfrom(sock, line, BUF_SIZE, 0, (struct sockaddr *)&srv_addr, srv_addr_len_ptr);
		if (res < 0)
			printf("No Value");
		else
		{
			line[res] = 0; /* NULL terminate the string */
			printf("%s", line);
		}
		exit(0);
	}
	else if (strcmp(cmd, "set") == 0)
	{
		// Send PULL message
		strncpy(msg_rate, argv[4], 15);
		sprintf(message, "PUT /%s HTTP/1.0", msg_rate);
		sendto(sock, message, strlen(message), 0, (struct sockaddr *)&srv_addr, srv_addr_len);
	}

	close(sock);
}
