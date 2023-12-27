#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "mergeSort.h"
#include "list.h"

void splitList(Node* list, Node** left, Node** right)
{
    ListErrorCode errorCode = noErrors;

    Node* fast = NULL;
    Node* slow = NULL;

    slow = list;
    fast = getNextNode(list, &errorCode);

    while (fast != NULL)
    {
        fast = getNextNode(fast, &errorCode);
        if (fast != NULL)
        {
            fast = getNextNode(fast, &errorCode);
            slow = getNextNode(slow, &errorCode);
        }
    }

    (*left) = list;
    (*right) = getNextNode(slow, &errorCode);
    changeNextNode(&slow, NULL);
}

Node* mergeList(Node* left, Node* right, const int sortBy)
{
    if (left == NULL)
    {
        return right;
    }

    if (right == NULL)
    {
        return left;
    }

    ListErrorCode errorCode = noErrors;
    Node* mergedList = NULL;

    if (strcmp(currentValue(left, sortBy), currentValue(right, sortBy)) <= 0)
    {
        mergedList = left;
        changeNextNode(&mergedList, mergeList(getNextNode(left, &errorCode), right, sortBy));
    }
    else
    {
        mergedList = right;
        changeNextNode(&mergedList, mergeList(left, getNextNode(right, &errorCode), sortBy));
    }

    return mergedList;
}

ListErrorCode mergeSort(Node** list, const int sortBy)
{
    Node* head = *list;
    Node* left = NULL;
    Node* right = NULL;

    // check whether the list is empty
    ListErrorCode empty = noErrors;
    Node* nextNode = getNextNode(*list, &empty);
    if (empty || nextNode == NULL)
    {
        return listIsEmpty;
    }

    splitList(head, &left, &right);

    mergeSort(&right, sortBy);
    mergeSort(&left, sortBy);

    *list = mergeList(left, right, sortBy);
    return noErrors;
}