#include "tor.h"

int main(int argc, char *argv[])
{
    char *host; // host is server we wanna connnect to
    int port;   // for port number

    if (argc < 3)
    {
        /*
        ./tor is argv[0]
        1.2.3.4 is the host
        80 is the port
        */
        printf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return -1; // for the error
    }

    host = argv[1];       // pointing host at argv[1]
    port = atoi(argv[2]); // pointing port at argv[2] using atoi for the string
}