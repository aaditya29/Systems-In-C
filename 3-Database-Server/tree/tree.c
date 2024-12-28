#include "tree.h"

// defining the root
Tree root = {.n = {
                 .tag = (TagRoot | TagNode), // either root or node
                 .north = (Node *)&root,     // if points to itself then it is root
                 .west = 0,                  // initialise to 0
                 .east = 0,                  // initialise to 0
                 .path = "/",                // root path
             }};

// function to set the value to zero
void zero(int8 *str, int16 size)
{
    int8 *p;
    int16 n;
    for (n = 0, p = str; n < size; p++, n++)
    {
        *p = 0;
    }
    return;
}
Node *create_node(Node *parent, int8 *path)
{
    Node *n;        // creating a node
    int16 size;     // size of the path
    assert(parent); // check if parent is not null
    // allocation of memory
}

int main()
{
    printf("%p\n", (void *)&root);
    return 0;
}
