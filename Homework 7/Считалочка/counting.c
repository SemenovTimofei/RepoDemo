#include "counting.h"

size_t findSurvivor(size_t number, size_t step)
{
    List* head = NULL;

    for (size_t i = 0; i < number; ++i)
    {
        push(&head, i + 1);
    }

    size_t position = 1;
    size_t survivor = 0;
    moveHead(&head);

    while (position != NULL)
    {
        for (size_t i = 1; i < step; ++i)
        {
            moveHead(&head);
        }

        survivor = position;
        position = pop(&head);
    }

    free(head);
    return survivor;
}