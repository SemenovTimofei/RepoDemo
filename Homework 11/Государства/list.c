#include "list.h"
#include <stdlib.h>

typedef struct ListElement
{
    int getCity;
    size_t distance;
    struct ListElement* next;
} ListElement;

typedef struct List
{
    ListElement* head;
    ListElement* current;
    ListElement* tail;
    size_t index;
    size_t size;
} List;

ListElement* head(List* const list)
{
    return list != NULL ? list->head : NULL;
}

List* createList()
{
    return (List*)calloc(1, sizeof(List));
}

void freeList(List** const list)
{
    for (ListElement* current = head(*list); current != NULL;)
    {
        ListElement* next = current->next;
        free(current);
        current = next;
    }
    free(*list);
    *list = NULL;
}

ListElement* createElement(const int const getCity, const size_t const distance)
{
    ListElement* element = (ListElement*)malloc(sizeof(ListElement));
    if (element == NULL)
    {
        return NULL;
    }
    element->getCity = getCity;
    element->distance = distance;
    element->next = NULL;
    return element;
}

int push(List* const list, const int getCity, const int const distance)
{
    ListElement* element = createElement(getCity, distance);
    if (element == NULL)
    {
        return 1;
    }
    if (list->head == NULL)
    {
        list->head = element;
        list->current = element;
    }
    else
    {
        list->tail->next = element;
    }
    list->tail = element;
    ++list->size;
    return 0;
}

void setCurrent(List* const list)
{
    list->current = list->head;
    list->index = 0;
}

ListElement* getElement(List* const list, const size_t index)
{
    if (index < list->index)
    {
        setCurrent(list);
    }
    for (ListElement** current = &list->current; *current != NULL; *current = (*current)->next)
    {
        if (list->index == index)
        {
            return *current;
        }
        ++list->index;
    }
    return NULL;
}

int getCity(List* const list, const size_t index)
{
    ListElement* element = getElement(list, index);
    return element != NULL ? element->getCity : 0;
}

size_t distance(List* const list, const size_t index)
{
    ListElement* element = getElement(list, index);
    return element != NULL ? element->distance : 0;
}

size_t listSize(List* const list)
{
    return list != NULL ? list->size : 0;
}

void printList(List* const list)
{
    for (ListElement* current = head(list); current != NULL; current = current->next)
    {
        printf("%d ", current->getCity);
    }
}

int arrayIsEqual(List* const list, const int* const array, const size_t length)
{
    if (listSize(list) != length)
    {
        return 0;
    }
    for (size_t i = 0; i < length; ++i)
    {
        if (getElement(list, i)->getCity != array[i])
        {
            return 0;
        }
    }
    return 1;
}