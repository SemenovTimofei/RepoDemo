#include <stdio.h>

#include "list.h"

int main()
{
    List* list = createList();
    push(list, "egor1", 1);
    push(list, "egor2", 2);
    push(list, "egor3", 3);
    printList(list);

    deleteElement(list, 1);
    printList(list);
}