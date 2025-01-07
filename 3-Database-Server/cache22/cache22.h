#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#define HOST "127.0.0.1"
#define PORT 12000

typedef unsigned int int32;       // defining the integer of 32 bits
typedef unsigned short int int16; // defining the integer of 16 bits
typedef unsigned char int8;       // defining the integer of 8 bits

void mainloop(void);
int main(int, char **);