#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <assert.h>
#include <errno.h>

#define TagRoot 1 // in binary 00 01
#define TagNode 2 // in binary 00 10
#define TagLeaf 4 // in binary 01 00

#define NoError 0 // no error

#define nullptr NULL

#define find_last(x) find_last_linear(x)
#define reterr(x) \
  errno = (x);    \
  return nullptr

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
typedef unsigned char Tag;
struct s_node
{
  Tag tag;
  struct s_node *north; // for pointing upwards and if on top will point to itself
  struct s_node *west;  // for pointing to the left
  struct s_leaf *east;  // for pointing to the right
  int8 path[256];
};
typedef struct s_node Node;

struct s_leaf
{
  Tag tag;
  union u_tree *west;  // for pointing to the left
  struct s_leaf *east; // for pointing to the right
  int8 key[128];       // for storing the key
  int8 *value;         // for storing the value
  int16 size;          // for storing the size of the value
};
typedef struct s_leaf Leaf;

// Creating tree structre
union u_tree
{
  // we can have either one node or one leaf at a time
  Node n;
  Leaf l;
};
typedef union u_tree Tree;