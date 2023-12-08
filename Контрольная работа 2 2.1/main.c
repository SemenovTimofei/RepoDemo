#include <stdio.h>

#include "list.h"

int main()
{
    List* list = createList();

    push(list, 1);
    push(list, 2);
    push(list, 3);

    printList(list);

}