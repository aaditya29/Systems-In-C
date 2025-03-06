#ifndef CACHE22
#define CACHE22

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <assert.h>
#include <errno.h>
#include <stddef.h>
#include <stdarg.h>

// network header files
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define HOST "127.0.0.1"
#define PORT "12049"

typedef unsigned int int32;       // defining the integer of 32 bits
typedef unsigned short int int16; // defining the integer of 16 bits
typedef unsigned char int8;       // defining the integer of 8 bits

struct s_client
{
    int s;       // socket for the client
    char ip[16]; // ip address of the client
    int16 port;  // port number of the client
};
typedef struct s_client Client;

void mainloop(int);    // main loop function
int initserver(int16); // server initialization function
int main(int, char **);

#endif