#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h> //for socket(), connect(), send(), recv(), close functions
#include <sys/types.h>  //
#include <arpa/inet.h>  //for sockaddr_in, inet_addr(), htons() functions
#include <netinet/in.h>

#define LISTENADDR "127.0.0.1" // IP Address of local host

int srv_init()
{
}

int main(int argc, char *argv[])
{
    int s;        // socket file descriptor
    char *port;   // port number
    if (argc < 2) // means we are just starting the program
    {
        fprintf(stderr, "Usage: %s <listening port>\n", argv[0]); // print error message with argv[0] as the name of executable
        return -1;
    }
    else
    {
        port = argv[1];
    }
    s = srv_init(atoi(port)); // convert port to integer and pass it to srv_init function
}