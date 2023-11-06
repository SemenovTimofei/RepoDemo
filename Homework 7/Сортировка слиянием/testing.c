#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "mergeSort.h"
#include "list.h"
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

    // test openning and sorting empty text file
    Node* test1 = NULL;

    openFileErrorCode = loadData(&test1, "test1.txt");
    if (openFileErrorCode)
    {
        return testErrorOpenningFile;
    }

    mergeSort(&test1, 0);
    if (test1 != NULL)
    {
        return testErrorCode1;
    }

    // test sorting by phone number
    Node* test2 = NULL;
    Node* result2 = NULL;
    push(&result2, "DEF", "123");
    push(&result2, "ABC", "456");
    push(&result2, "GHI", "789");

    openFileErrorCode = loadData(&test2, "test2.txt");
    if (openFileErrorCode)
    {
        return testErrorOpenningFile;
    }

    mergeSort(&test2, 0);
    if (!isSame(test2, result2, 0))
    {
        return testErrorCode2;
    }
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
        return testErrorOpenningFile;
    }

    mergeSort(&test3, 1);
    if (!isSame(test3, result3, 1))
    {
        return testErrorCode3;
    }
    freeList(&result3);

    return testsPassed;
}