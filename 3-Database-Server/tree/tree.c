#include "tree.h"

// defining the root
Tree root = {
    .tag = (TagRoot | TagNode), // either root or node
    .north = (Tree *)&root,     // if points to itself then it is root
    .west = 0,                  // initialise to 0
    .east = 0,
    .path = "/",
};

int main()
{
    printf("%p\n", &root);
    return 0;
}
