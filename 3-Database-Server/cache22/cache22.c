#include "cache22.h"

bool scontinuation; // global variable for the server continuation

void mainloop(int16 port)
{
    struct sockaddr_in sock;
    int s;

    sock.sin_family = AF_INET;              // setting the family of the socket
    sock.sin_port = htons(port);            // setting the port of the socket
    sock.sin_addr.s_addr = inet_addr(HOST); // setting the address of the socket

    s = socket(AF_INET, SOCK_STREAM, 0); // creating a socket
    if (s <= 0)
    {
        fprintf(stderr, "Socket creation failed: %s\n", strerror(errno));
        exit(1);
    }

    // binding the socket with the structure
    if (bind(s, (struct sockaddr *)&sock, sizeof(sock)) != 0)
    {
        fprintf(stderr, "Bind failed: %s\n", strerror(errno));
        close(s);
        exit(1);
    }

    if (listen(s, 20) != 0)
    {
        fprintf(stderr, "Listen failed: %s\n", strerror(errno));
        close(s);
        exit(1);
    }
}

int main(int argc, char *argv[])
{
    char *sport;
    int16 port; // port number
    if (argc < 2)
    {
        sport = PORT;
    }
    else
    {
        sport = argv[1]; // setting the port number
    }

    port = (int16)atoi(sport); // converting the port number to integer
    scontinuation = true;
    while (scontinuation)
    {
        mainloop(port);
    }
    return 0;
}