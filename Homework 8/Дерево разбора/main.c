#include "tree.h"

int main()
{
    Tree* tree = NULL;
    createTree(&tree, "text.txt");
    
    printTree(tree);
}