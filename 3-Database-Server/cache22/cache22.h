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

// network header files
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define HOST "127.0.0.1"
#define PORT 12049

typedef unsigned int int32;       // defining the integer of 32 bits
typedef unsigned short int int16; // defining the integer of 16 bits
typedef unsigned char int8;       // defining the integer of 8 bits

void mainloop(int16); // main loop function
int main(int, char **);

#endif