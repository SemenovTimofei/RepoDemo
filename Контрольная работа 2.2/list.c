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
} List;

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
    newElement->next = list->head;
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

    free(trash->value);
    free(trash);

    return OK;
}

size_t listLength(const List* const list)
{
    return list == NULL ? 0 : list->length;
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

ErrorCode printHead(List* list)
{
    if (list == NULL)
    {
        return NULLPointerError;
    }
    printf("%d\n", list->head->value);
    return OK;
}

ListElement* findElement(const List* const list, const char* const value)
{
    if (list == NULL)
    {
        return NULL;
    }
    ListElement* current = list->head;
    while (current != NULL && strcmp(current->value, value) != 0)
    {
        current = current->next;
    }
    return current;
}

bool isPresent(const List* const list, const char* const value)
{
    if (list == NULL)
    {
        return false;
    }

    ListElement* current = list->head;

    while (current != NULL)
    {
        if (strcmp(current->value, value) == 0)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}