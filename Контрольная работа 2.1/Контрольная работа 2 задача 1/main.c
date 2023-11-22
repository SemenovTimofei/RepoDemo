#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main()
{
    List* head = NULL;
    
    for (size_t i = 0; i < 10; ++i)
    {
        push(&head, i);
    }

    printList(head);
    deleteOddElements(&head);
    printList(head);
}