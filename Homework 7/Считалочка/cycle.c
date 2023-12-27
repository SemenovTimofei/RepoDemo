#include "cycle.h"

typedef struct List
{
    size_t value;
    List* next;
} List;

size_t push(List** head, size_t value)
{
    List* temporary = calloc(1, sizeof(List));
    if (temporary == NULL)
    {
        return 1;
    }

    temporary->value = value;

    if ((*head) == NULL)
    {
        temporary->next = temporary;
        (*head) = temporary;
        return 0;
    }

    List* nextElement = (*head)->next;
    (*head)->next = temporary;
    temporary->next = nextElement;
    (*head) = temporary;

    return 0;
}

size_t pop(List** head)
{
    if ((*head) == NULL)
    {
        return 0;
    }

    List* temporary = (*head);
    while (temporary->next != (*head))
    {
        temporary = temporary->next;
    }

    temporary->next = (*head)->next;
    size_t value = (*head)->value;

    if ((*head) == temporary)
    {
        free(*head);
        *head = NULL;

        return value;
    }

    free(*head);
    *head = temporary->next;
    
    return value;
}

void moveHead(List** head)
{
    if ((*head) == NULL)
    {
        return;
    }

    (*head) = (*head)->next;
}