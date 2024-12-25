#include "tree.h"
int main()
{
    Tree *root = (Tree *)malloc(sizeof(Tree));
    root->n.north = &root->n;
    root->n.west = NULL;
    root->n.east = NULL;
    strcpy(root->n.path, "Root");
    printf("Root: %s\n", root->n.path);
    return 0;
}