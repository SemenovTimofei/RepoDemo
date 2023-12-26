#include "list.h"

typedef struct ListElement
{
    char* word;
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

int push(List* list, char* word)
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

int printList(List* list)
{
    if (list == NULL)
    {
        return 1;
    }
    ListElement* head = list->head;
    if (head != NULL)
    {
        printf("%s %zd\n", head->word, list->length);
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

size_t getLength(List* list)
{
    return list != NULL ? list->length : 0;
}