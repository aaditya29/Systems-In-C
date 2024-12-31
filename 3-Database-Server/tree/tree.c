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
    Node *n;    // creating a node
    int16 size; // size of the path

    errno = NoError;

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

Leaf *find_last_linear(Node *parent)
{
    Leaf *l;         // creating a leaf
    errno = NoError; // setting the error to no error
    assert(parent);  //  checking if the parent is not null
    if (!parent->east)
    {
        reterr(NoError);
    }
    for (l = parent->east; l->east; l = l->east)
        ; // iterating through the east
    assert(l);
    return l;
}

// Creating leaves
Leaf *create_leaf(Node *parent, int8 *key, int8 *value, int16 count)
{
    Leaf *l, *new;         // creating a leaf and a new leaf
    int16 size;            // size of the leaf
    assert(parent);        // checking if the parent is not `
    l = find_last(parent); // finding the last leaf

    size = sizeof(struct s_leaf); // Calculating the size of the structure 's_leaf' in bytes
    new = (Leaf *)malloc(size);   // Allocating memory for the structure 's_leaf'

    if (!l)
    {
        parent->east = new; // setting the parent's east to the new leaf
    }
    else
    {
        l->east = new; // setting the last leaf's east to the new leaf
    }
    zero((int8 *)new, size);                            // setting the memory to zero
    new->tag = TagLeaf;                                 // setting the tag to leaf
    new->west = (!l) ? (Tree *)parent : (Tree *)l;      // setting the west to the parent or the last leaf
    strncpy((char *)new->key, (char *)key, 127);        // copying the key to the leaf
    new->value = (int8 *)malloc(count);                 // allocating memory for the value
    zero(new->value, count);                            // setting the memory to zero
    assert(new->value);                                 // checking if the value is not null
    strncpy((char *)new->value, (char *)&value, count); // copying the value to the leaf
    new->size = count;                                  // setting the size of the value
    return new;                                         // returning the leaf
}

int main()
{
    Node *n, *n2;                                      // creating nodes
    Leaf *l1;                                          // creating leaves
    int8 *key, *value;                                 // creating key and value
    int16 size;                                        // size of the value
    n = create_node((Node *)&root, (int8 *)"/Users/"); // creating a node with the path '/Users/' and parent
    assert(n);                                         // checking if the node is not null
    n2 = create_node(n, (int8 *)"/Users/login");       // creating a node with the path '/Users/login'
    assert(n2);                                        // checking if the node is not null

    key = (int8 *)"aaditya";
    value = (int8 *)"password";          // setting the key and value
    size = (int16)strlen((char *)value); // setting the size of the value
    l1 = create_leaf(n2, key, value, size);
    assert(l1);                // checking if the leaf is not null
    printf("%s\n", l1->value); // printing the value

    // printing addresses of these pointers
    printf("%p %p\n", n, n2);
    // freeing the memory
    free(n2);
    free(n);
    return 0;
}
