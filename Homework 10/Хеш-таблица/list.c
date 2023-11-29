#include "list.h"

typedef struct ListElement
{
    char* value;
    int frequency;
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

ErrorCode push(List* list, char* value, int frequency)
{
    ListElement* newElement = (ListElement*)calloc(1, sizeof(ListElement));

    if (newElement == NULL)
    {
        return MemoryAllocationError;
    }

    newElement->frequency = frequency;
    newElement->value = _strdup(value);

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

size_t getFrequency(const ListElement* const element)
{
    return element->frequency;
}

size_t listLength(const List* const list)
{
    return list == NULL ? 0 : list->length;
}

ErrorCode changeElement(ListElement* const element, const size_t const frequency)
{
    if (element == NULL)
    {
        return NULLPointerError;
    }
    element->frequency = frequency;
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
        printf("%s %d\n", head->value, head->frequency);
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
    printf("%s %d\n", list->head->value, list->head->frequency);
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