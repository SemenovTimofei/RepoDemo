#include "test.h"

bool testing()
{
    Node* head = NULL;

    head = push(head, 5, 5);
    if (head == NULL)
    {
        return false;
    }

    if (getHeadValue(head) != 5)
    {
        return false;
    }
    head = push(head, 2, 2);
    if (getHeadValue(head) != 2)
    {
        return false;
    }
    head = push(head, 3, 3);
    if (getHeadValue(head) != 2)
    {
        return false;
    }

    head = deleteByKey(head, 1);
    if (getHeadValue(head) != 2)
    {
        return false;
    }
    head = deleteByKey(head, 2);
    if (getHeadValue(head) != 3)
    {
            return false;
    }

    head = deleteByKey(head, 3);
    head = deleteByKey(head, 5);
    if (!isEmpty(head))
    {
        return false;
    }

    freeList(head);
    return true;
}