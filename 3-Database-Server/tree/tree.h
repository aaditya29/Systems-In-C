#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <assert.h>
#include <errno.h>

/*
Rough structure of the tree:

        /Root
          /Users/
          /Users/User1
          /Users/User2

            /Users/Login/

We will have:
Tree
  Node
  Leaf
*/

typedef unsigned int int32;
typedef unsigned short int int16;
typedef unsigned char int8;
struct s_node
{
    struct u_tree *north; // for pointing upwards and if on top will point to itself
    struct s_node *west;  // for pointing to the left
    struct s_leaf *east;  // for pointing to the right
    int8 path[256];
};
typedef struct s_node Node;