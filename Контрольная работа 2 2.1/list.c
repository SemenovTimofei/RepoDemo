#include "list.h"

typedef struct ListElement
{
    int value;
    ListElement* next;
} ListElement;

typedef struct List
{
    ListElement* head;
    size_t length;
};

List* createList()
{
    return (List*)calloc(1, sizeof(List));
}

ErrorCode push(List* list, int value)
{
    ListElement* newElement = (ListElement*)calloc(1, sizeof(ListElement));

    if (newElement == NULL)
    {
        return MemoryAllocationError;
    }

    newElement->value = value;
    list->head = newElement;
    ++list->length;

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
    --list->length;

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
        printf("%d\n", head->value);
        head = head->next;
    }
    return OK;
}