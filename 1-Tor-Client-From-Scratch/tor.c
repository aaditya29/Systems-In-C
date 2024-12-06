#include "tor.h"

// packet that initialised proxy connection
Req *request(const char *dstip, const int dstport)
{
    // allocasting memory for the structure and reference the length of structure
    Req *req;

    // allocating memory for the structure
    req = malloc(reqsize);

    // allocating memory according to the protocol
    req->vn = 4;
    req->cd = 1;
    req->dstport = htons(dstport);
    req->dstip = inet_addr(dstip);
    strncpy(req->userid, USERNAME, 7);

    return req;
}

int main(int argc, char *argv[])
{
    char *host; // host is server we wanna connnect to
    int port;   // for port number
    int s;
    struct sockaddr_in sock; // struct to hold ip addresses
    Req *req;
    Res *res;
    char buf[ressize];
    int success; // making predicate or boolean operation for true or false

    if (argc < 3)
    {
        /*
        ./tor is argv[0]
        1.2.3.4 is the host
        80 is the port
        */
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return -1; // for the error
    }

    host = argv[1];       // pointing host at argv[1]
    port = atoi(argv[2]); // pointing port at argv[2] using atoi for the string

    s = socket(AF_INET, SOCK_STREAM, 0); // creating a socket with IPv4 addressing, TCP protocol, and default protocol
    if (s < 0)
    {
        perror("socket"); // specifying function which produced the error

        return -1;
    }

    /*
    Below we areconfiguring a `sockaddr_in` structure which is used to specify an address to which to connect a socket.

    sock.sin_family = AF_INET; //`sock.sin_family` is being set to `AF_INET`, which indicates that the address family is IPv4.
    This is necessary for the socket to understand that it will be communicating over an IPv4 network.

    sock.sin_port = htons(PROXYPORT);//`sock.sin_port` is being set to the port number, which is converted to network byte order using the `htons` function.
    `htons` stands for "host to network short" and ensures that the port number is in the correct byte order for network communication.

    sock.sin_addr.s_addr = inet_addr(PROXY);// `sock.sin_addr.s_addr` is being set to the IP address, which is converted from a string format to a network address using the `inet_addr` function.
    `PROXY` is expected to be a string containing the IP address (e.g., "192.168.1.1").

    this code is preparing a `sockaddr_in` structure with the necessary details (address family, port number, and IP address) to
    establish a network connection using a socket.
    */

    sock.sin_family = AF_INET;               // setting the address family to IPv4
    sock.sin_port = htons(PROXYPORT);        // setting the port number
    sock.sin_addr.s_addr = inet_addr(PROXY); // setting the IP address

    // Initialising actual connection
    if (connect(s, (struct sockaddr *)&sock, sizeof(sock)))
    {
        perror("connect");
        return -1;
    } // connecting to the server

    printf("Connected to proxy\n");
    req = request(host, port); // making a request to the server
    write(s, req, reqsize);    // writing the request to the server
    // making sure buffer is empty
    memset(buf, 0, ressize);
    read(s, buf, ressize); // reading the response from the server
    // if read operation fails
    if (read(s, buf, ressize) < 1)
    {
        perror("read");
        free(req);
        close(s);

        return -1;
    }
    res = buf;                 // to access proxy response
    success = (res->cd == 90); // if cd == 90 then success is true else false
    if (!success)
    {
        fprintf(stderr, "Unable to establish the connection and traverse the proxy."
                        "Error code: %d\n",
                res->cd);
        close(s);
        free(req);

        return -1;
    }

    printf("Successfully connected through PROXY to %s:%d\n", host, port);
    close(s);  // closing the socket
    free(req); // freeing the memory
    return 0;
}