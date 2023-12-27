#include <stdbool.h>

#include "tree.h"

bool testing()
{
    Node* root = createNode();
    push(root, 5, "five");
    for (int i = -1000; i < 1000; ++i)
    {
        if (i != 5 && isPresent(root, i))
        {
            deleteTree(root);
            return false;
        }
    }

    deleteNode(root, 5);
    for (int i = -1000; i < 1000; ++i)
    {
        if (isPresent(root, i))
        {
            return false;
        }
    }

    push(root, 2, "two");
    push(root, 1, "one");
    push(root, 3, "three");
    push(root, 4, "four");

    if (strcmp(search(root, 1), "one") != 0 || strcmp(search(root, 2), "two") != 0 || strcmp(search(root, 3), "three") != 0 || strcmp(search(root, 4), "four") != 0)
    {
        return false;
    }
    deleteNode(root, 3);
    if (isPresent(root, 3))
    {
        return false;
    }
    if (strcmp(search(root, 1), "one") != 0 || strcmp(search(root, 2), "two") != 0 || strcmp(search(root, 4), "four") != 0)
    {
        return false;
    }
    deleteNode(root, 2);
    if (isPresent(root, 2))
    {
        return false;
    }
    if (strcmp(search(root, 1), "one") != 0 || strcmp(search(root, 4), "four") != 0)
    {
        printf("check");
        return false;
    }

    return true;
}