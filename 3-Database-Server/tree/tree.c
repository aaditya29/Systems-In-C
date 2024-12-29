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
    size = sizeof(struct s_node);  // Calculating the size of the structure 's_node' in bytes
    n = (Node *)malloc((int)size); // Allocating memory for the structure 's_node'
    zero((int8 *)n, size);         // Setting the memory to zero
    // linking  up
    parent->west = n;                            // setting the parent's west to the new node structure
    n->tag = TagNode;                            // setting the tag to node
    n->north = parent;                           // setting the north to the parent
    strncpy((char *)n->path, (char *)path, 255); // copying the path to the node

    return n; // returning the node
}

// Creating leaves
Leaf *create_leaf(int8 *key, int16 size)
{
    Leaf *l;         // creating a leaf
    int16 leaf_size; // size of the leaf
    // allocation of memory
    leaf_size = sizeof(struct s_leaf);  // Calculating the size of the structure 's_leaf' in bytes
    l = (Leaf *)malloc((int)leaf_size); // Allocating memory for thestructure 's_leaf'
    zero((int8 *)l, leaf_size);         // Setting the memory to zero
    // linking up
    l->tag = TagLeaf;                           // setting the tag to leaf
    strncpy((char *)l->key, (char *)key, size); // copying the key to the leaf
    return l;                                   // returning the leaf
}

int main()
{
    Node *n, *n2;                                      // creating nodes
    n = create_node((Node *)&root, (int8 *)"/Users/"); // creating a node with the path '/Users/' and parent
    assert(n);                                         // checking if the node is not null
    n2 = create_node(n, (int8 *)"/Users/login");       // creating a node with the path '/Users/login'
    assert(n2);                                        // checking if the node is not null
    // printing addresses of these pointers
    printf("%p %p\n", n, n2);
    // freeing the memory
    free(n2);
    free(n);
    return 0;
}
