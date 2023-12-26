#include "list.h"

typedef struct ListElement
{
    char* word;
    size_t frequency;
    ListElement* next;
} ListElement;

typedef struct List
{
    ListElement* head;
    size_t length;
} List;

List* initializeList()
{
    return (List*)calloc(1, sizeof(List));
}

ListElement* initializeListElement()
{
    return (ListElement*)calloc(1, sizeof(ListElement));
}

int push(List* list, char* word, size_t frequency)
{
    ListElement* newElement = (ListElement*)calloc(1, sizeof(ListElement));
    if (newElement == NULL)
    {
        return 1;
    }
    newElement->word = _strdup(word);
    newElement->next = list->head;
    list->head = newElement;
    ++list->length;
    return 0;
}

int freeList(List* list)
{
    if (list == NULL)
    {
        return 1;
    }
    while (list->head != NULL)
    {
        ListElement* trash = list->head;
        list->head = list->head->next;
        free(trash->word);
        free(trash);
    }
    free(list);
    return 0;
}

int changeFrequency(ListElement* element, size_t frequency)
{
    if (element == NULL)
    {
        return 1;
    }
    element->frequency = frequency;
    return 0;
}

int printList(List* list)
{
    if (list == NULL)
    {
        return 1;
    }
    ListElement* head = list->head;
    while (head != NULL)
    {
        printf("%s %d\n", head->word, head->frequency);
        head = head->next;
    }
    return 0;
}

ListElement* findElement(List* list, char word[])
{
    if (list == NULL)
    {
        return NULL;
    }
    ListElement* head = list->head;
    while (head != NULL && strcmp(head->word, word) != 0)
    {
        head = head->next;
    }
    return head;
}