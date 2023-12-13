#include <stdlib.h>
#include <stdbool.h>

#include "queue.h"

typedef struct List
{
    int key;
    int value;
    List* next;
} List;

int enqueue(List** head, int value, int key)
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

int dequeue(List** head)
{
    if ((*head) == NULL)
    {
        return -1;
    }

    while ((*head)->next != NULL)
    {
        (*head) = (*head)->next;
    }

    List* trash = (*head);
    (*head) = (*head)->next;
    int value = trash->value;
    free(trash);

    return value;
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
    while (head != 0)
    {
        printf("%d %d\n", head->value, head->key);
        head = head->next;
    }
}