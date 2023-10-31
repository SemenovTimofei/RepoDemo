#include <stdlib.h>
#include <stdbool.h>

#include "cycle.h"

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

int pop(List** head)
{
    if ((*head) == NULL)
    {
        return NULL;
    }

    List* temporary = (*head);
    while (temporary->next != (*head))
    {
        temporary = temporary->next;
    }

    temporary->next = (*head)->next;
    int value = (*head)->value;

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

int findSurvivor(const int size, const int step)
{
    List* head = NULL;

    for (int i = 0; i < size; ++i)
    {
        push(&head, i + 1);
    }

    int position = 1;
    int survivor = 0;
    moveHead(&head);

    while (position != NULL)
    {
        for (int i = 1; i < step; ++i)
        {
            moveHead(&head);
        }

        survivor = position;
        position = pop(&head);
    }

    free(head);
    return survivor;
}

bool testing()
{
    int size1 = 15;
    int step1 = 2;
    if (findSurvivor(size1, step1) != 15)
    {
        return false;
    }

    int size2 = 8;
    int step2 = 2;
    if (findSurvivor(size2, step2) != 1)
    {
        return false;
    }

    int size3 = 11;
    int step3 = 3;
    if (findSurvivor(size3, step3) != 7)
    {
        return false;
    }

    return true;
}