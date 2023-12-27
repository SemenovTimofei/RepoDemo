#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "testing.h"

bool isSame(Node* list, Node* expectedList, int valueType)
{
    while (list != NULL)
    {
        if (strcmp(currentValue(list, valueType), currentValue(expectedList, valueType)) != 0 || strcmp(currentValue(list, !valueType), currentValue(expectedList, !valueType)) != 0)
        {
            return false;
        }

        ListErrorCode listErrorCode = noErrors;
        list = getNextNode(list, &listErrorCode);
        expectedList = getNextNode(expectedList, &listErrorCode);
    }

    return true;
}

TestErrorCode testing()
{
    ListErrorCode openFileErrorCode = noErrors;

    // test opening and sorting empty text file
    Node* test1 = NULL;

    openFileErrorCode = loadData(&test1, "test1.txt");
    if (openFileErrorCode)
    {
        return testErrorOpenningFile;
    }

    mergeSort(&test1, 0);
    if (test1 != NULL)
    {
        freeList(&test1);
        return testErrorCode1;
    }
    freeList(&test1);

    // test sorting by phone number
    Node* test2 = NULL;
    Node* result2 = NULL;
    push(&result2, "DEF", "123");
    push(&result2, "ABC", "456");
    push(&result2, "GHI", "789");

    openFileErrorCode = loadData(&test2, "test2.txt");
    if (openFileErrorCode)
    {
        freeList(&test2);
        freeList(&result2);
        return testErrorOpenningFile;
    }

    mergeSort(&test2, 0);
    if (!isSame(test2, result2, 0))
    {
        freeList(&test2);
        freeList(&result2);
        return testErrorCode2;
    }
    freeList(&test2);
    freeList(&result2);

    // test sorting by name
    Node* test3 = NULL;
    Node* result3 = NULL;
    push(&result3, "ABC", "456");
    push(&result3, "DEF", "123");
    push(&result3, "GHI", "789");

    openFileErrorCode = loadData(&test3, "test3.txt");
    if (openFileErrorCode)
    {
        freeList(&test3);
        freeList(&result3);
        return testErrorOpenningFile;
    }

    mergeSort(&test3, 1);
    if (!isSame(test3, result3, 1))
    {
        freeList(&test3);
        freeList(&result3);
        return testErrorCode3;
    }

    freeList(&test3);
    freeList(&result3);

    return testsPassed;
}