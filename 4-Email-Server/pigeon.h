#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <errno.h>
#include <birchutils.h>

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;
typedef unsigned long long int int64;

#define $8 (int8 *) // here we are defining a macro that will be used to cast an int8 pointer
#define $6 (int16)
#define $2 (int 32)
#define $4 (int64)
#define $c (char *)
#define $i (int)

int main(int, char **);