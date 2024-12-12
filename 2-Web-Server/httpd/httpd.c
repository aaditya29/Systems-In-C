#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h> //for socket(), connect(), send(), recv(), close functions
#include <sys/types.h>  //
#include <arpa/inet.h>  //for sockaddr_in, inet_addr(), htons() functions
#include <netinet/in.h>

#define LISTENADDR "127.0.0.1" // IP Address of local host
