#include "cache22.h"

bool scontinuation; // global variable for the server continuation

int main(int argc, char *argv[])
{
    scontinuation = true;
    while (scontinuation)
    {
        mainloop();
    }
    return 0;
}