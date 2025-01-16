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

/*
Here we are defining a macro with the name log and its parameters. Here, x is a mandatory parameter, and args... is a variadic parameter, meaning it can accept a variable number of arguments. The macro is defined to call the function prtinf with the parameters x and args.
*/
#define log(x, args...) \
    printf(x, args)

typedef unsigned int int32;       // defining the integer of 32 bits
typedef unsigned short int int16; // defining the integer of 16 bits
typedef unsigned char int8;       // defining the integer of 8 bits

void mainloop(int);    // main loop function
int initserver(int16); // server initialization function
int main(int, char **);

#endif