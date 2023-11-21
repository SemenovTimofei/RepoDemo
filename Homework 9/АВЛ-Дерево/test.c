#include <stdbool.h>

#include "test.h"

bool testing()
{
    AVLTree* tree = createAVLTree();

    char key2[] = "key2";
    char value2[] = "value2";
    addValue(tree, key2, value2);

    char key1[] = "key1";
    char value1[] = "value1";
    addValue(tree, key1, value1);

    char key3[] = "key3";
    char value3[] = "value3";
    addValue(tree, key3, value3);

    if (!isPresent(tree, key1) || !isPresent(tree, key2) || !isPresent(tree, key3))
    {
        return false;
    }

    if (!getValue(tree, key1) == "value1" || !getValue(tree, key2) == "value2" || !getValue(tree, key3) == "value3")
    {
        return false;
    }

    deleteValue(tree, key2);
    if (isPresent(tree, key2))
    {
        return false;
    }

    return true;
}