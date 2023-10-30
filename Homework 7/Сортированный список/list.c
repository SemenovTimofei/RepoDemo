#include <stdlib.h>
#include <stdbool.h>

#include "list.h"

typedef struct List
{
    int value;
    List* next;

} List;

int push(List** head, int value)
{
    List* temporary = calloc(1, sizeof(List));

    if (temporary == NULL)
    {
        return -1;
    }

    temporary->value = value;
    List* node = (*head);
    List* previous = NULL;
    if ((*head) == NULL)
    {
        temporary->next = (*head);
        (*head) = temporary;
        return 0;
    }

    while (value > node->value)
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
    int temporary = trash->value;
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

    int temporaryorary = element->value;
    previous->next = element->next;

    free(element);
    return temporaryorary;
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
        printf("%d ", head->value);
        head = head->next;
    }

    printf("\n");
}

bool testing()
{
    List* list = NULL;


}