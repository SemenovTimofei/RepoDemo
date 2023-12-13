#include "test.h"

bool testing()
{
    List* list = NULL;

    enqueue(&list, 5, 5);
    enqueue(&list, 1, 1);
    enqueue(&list, 100, 100);
    enqueue(&list, -100, 100);

    int check1[] = { -100, 1, 5, 100 };
    for (int i = 0; i < 4; ++i)
    {
        if ((getElement(list, i))->key != check1[i])
        {
            return false;
        }
    }

    deleteElement(&list, 1);
    deleteElement(&list, 1);

    int check2[] = { -100, 100 };

    for (int i = 0; i < 2; ++i)
    {
        if ((getElement(list, i))->key != check2[i])
        {
            return false;
        }
    }

    deleteList(&list);
    return true;
}