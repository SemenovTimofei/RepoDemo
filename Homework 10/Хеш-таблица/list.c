#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

typedef struct ListElement
{
    char* charValue;
    int intValue;
    ListElement* next;
} ListElement;

typedef struct List
{
    ListElement* head;
} List;

List* createList()
{
    return (List*)calloc(1, sizeof(List));
}

ErrorCode push(List* list, char* charValue, int intValue)
{
    ListElement* newElement = (ListElement*)calloc(1, sizeof(ListElement));

    if (newElement == NULL)
    {
        return MemoryAllocationError;
    }

    newElement->intValue = intValue;
    newElement->charValue = _strdup(charValue); // change ???

    newElement->next = list->head;
    list->head = newElement;

    return OK;
}

ErrorCode pop(List* list)
{
    if (list->head == NULL)
    {
        return NULLPointerError;
    }

    ListElement* trash = list->head;
    list->head = list->head->next;

    free(trash->charValue);
    free(trash);

    return OK;
}

ErrorCode getPop(List* list, char* charValue, int* intValue) // doesnt work with char !!!
{
    if (list->head == NULL)
    {
        return NULLPointerError;
    }

    ListElement* trash = list->head;
    list->head = list->head->next;
    charValue = _strdup(trash->charValue);
    *intValue = trash->intValue;

    free(trash->charValue);
    free(trash);

    return OK;
}

ErrorCode freeList(List* list)
{
    if (list == NULL)
    {
        return NULLPointerError;
    }

    while (list->head != NULL)
    {
        ListElement* trash = list->head;
        list->head = list->head->next;

        free(trash->charValue);
        free(trash);
    }

    free(list);

    return OK;
}

ErrorCode printList(List* list)
{
    if (list == NULL)
    {
        return NULLPointerError;
    }

    ListElement* head = list->head;
    while (head != NULL)
    {
        printf("%s %d\n", head->charValue, head->intValue);
        head = head->next;
    }
}

size_t listSize(List* list)
{
    if (list == NULL)
    {
        return 0;
    }
    
    size_t size = 0;
    ListElement* head = list->head;
    while (head != NULL)
    {
        ++size;
        head = head->next;
    }

    return size;
}

ErrorCode deleteElement(List* list, size_t index)
{
    if (list == NULL)
    {
        return NULLPointerError;
    }

    size_t current = 0;
    ListElement* head = list->head;

    while (current != index && head != NULL) // is this enough checking for empty element ???
    {
        head = head->next;
        ++current;
    }

    pop(head);

    return OK;
}