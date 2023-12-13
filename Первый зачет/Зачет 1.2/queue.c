#include <stdlib.h>
#include <stdbool.h>

#include "queue.h"

typedef struct List
{
    int key;
    int value;
    List* next;

} List;

int enqueue(List** head, int key, int value)
{
    List* temporary = calloc(1, sizeof(List));

    if (temporary == NULL)
    {
        return -1;
    }

    temporary->key = key;
    temporary->value = value;
    List* node = (*head);
    List* previous = NULL;
    if ((*head) == NULL)
    {
        temporary->next = (*head);
        (*head) = temporary;
        return 0;
    }

    while (key > node->key)
    {
        previous = node;
        node = node->next;
        if (node == NULL)
        {
            previous->next = temporary;
            temporary->next = NULL;
            return 0;
        }
    }

    if (previous == NULL)
    {
        temporary->next = (*head);
        (*head) = temporary;
        return 0;
    }

    temporary->next = node;
    previous->next = temporary;

    return 0;
}

int pop(List** head)
{
    if ((*head) == NULL)
    {
        return NULL;
    }

    List* trash = (*head);
    (*head) = (*head)->next;
    int temporary = trash->key;
    free(temporary);

    return trash;
}

List* getElement(List* head, size_t index)
{
    while (head != NULL && index > 0)
    {
        head = head->next;
        --index;
    }

    return head;
}

int deleteElement(List** head, size_t index)
{
    if (index == 0)
    {
        return pop(head);
    }
    List* previous = getElement(*head, index - 1);
    List* element = previous->next;
    if (element == NULL)
    {
        return NULL;
    }

    int temporary = element->key;
    previous->next = element->next;

    free(element);
    return temporary;
}

void deleteList(List** head)
{
    List* previous = NULL;
    while ((*head)->next)
    {
        previous = (*head);
        *head = (*head)->next;
        free(previous);
    }
    free(*head);
}

void printList(const List* head)
{
    while (head)
    {
        printf("%d %d\n", head->key, head->value);
        head = head->next;
    }
}