#include "cache22.h"

bool scontinuation; // global variable for the server continuation

void mainloop(void)
{
    struct sockaddr_in sock;
    int s;

    sock.sin_family = AF_INET;              // setting the family of the socket
    sock.sin_port = htons(PORT);            // setting the port of the socket
    sock.sin_addr.s_addr = inet_addr(HOST); // setting the address of the socket

    s = socket(AF_INET, SOCK_STREAM, 0); // creating a socket
    assert(s > 0);

    // binding the socket with the structure
    if (bind(s, (struct sockaddr *)&sock, sizeof(sock)))
    {
        assert_perror(errno); // checking if there is an error
    }
    listen(s, 20); // listening to the socket making 20 connection
}

int main(int argc, char *argv[])
{
    scontinuation = true;
    while (scontinuation)
    {
        mainloop();
    }
    return 0;
}