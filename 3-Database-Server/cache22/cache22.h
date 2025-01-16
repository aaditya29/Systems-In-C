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
Here we are defining a macro with the name log and its parameters. Here, x is a mandatory parameter, and args... is a variadic parameter, meaning it can accept a variable number of arguments. The _VA_OPT_ is a predefined macro that is used to check if the variadic parameter is empty or not. If it is not empty, then it will add a comma before the next argument.
*/
#define log(x, args...) \
    prtinf(x _VA_OPT_(, ) args)

typedef unsigned int int32;       // defining the integer of 32 bits
typedef unsigned short int int16; // defining the integer of 16 bits
typedef unsigned char int8;       // defining the integer of 8 bits

void mainloop(int);    // main loop function
int initserver(int16); // server initialization function
int main(int, char **);

#endif