#include "test.h"

bool testing()
{
    // testing cyclic list module
    List* head = NULL;
    size_t number = 1000;

    for (size_t i = 0; i < number; ++i)
    {
        if (push(&head, i + 1) != 0)
        {
            while (pop(&head) != 0)
            {
                pop(&head);
            }
            free(head);
            return false;
        }
    }
    for (size_t i = 0; i < number; ++i)
    {
        if (pop(&head) == 0)
        {
            free(head);
            return false;
        }
    }
    if (pop(&head) != 0)
    {
        while (pop(&head) != 0)
        {
            pop(&head);
        }
        free(head);
        return false;
    }
    free(head);

    // testing counting module
    size_t size1 = 15;
    size_t step1 = 2;
    if (findSurvivor(size1, step1) != 15)
    {
        return false;
    }

    size_t size2 = 8;
    size_t step2 = 2;
    if (findSurvivor(size2, step2) != 1)
    {
        return false;
    }

    size_t size3 = 11;
    size_t step3 = 3;
    if (findSurvivor(size3, step3) != 7)
    {
        return false;
    }

    return true;
}