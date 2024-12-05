#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>   //for socket(), connect(), send(), recv(), close functions
#include <arpa/inet.h>    //for sockaddr_in, inet_addr(), htons() functions
#include <netinet/in.h>   //for sockaddr_in, inet_addr()
#define PROXY "127.0.0.1" // IP Address of local host
#define PROXYPORT 9050    // default proxy port

// making specific data types for the port, ip addresses and other variables
typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;

// refer https://www.openssh.com/txt/socks4.protocol for the protocol format
struct proxy_request
{
    int8 vn;                 // vn is the socks protocol version number
    int8 cd;                 // cd is the SOCKS command code
    int16 dstport;           // dstport is the port number of the destination host
    int32 dstip;             // dstip is the IP address of the destination host
    unsigned char userid[8]; // userid is the user ID string
};

typedef struct proxy_request Req;
struct proxy_response
{
    int8 vn;
    int8 cd;
    int16 _;
    int32 __;
};
typedef struct proxy_response Res;

Req *request(const char *, const int);
int main(int, char **);