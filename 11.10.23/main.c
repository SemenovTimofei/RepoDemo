#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int main()
{
    struct Stack* head = NULL;

    ErrorCode result = push(&head, 1);

    if (result != ok)
    {
        printf("ololo");
    }

    printf("%d", top(head, &result));

    freeStack(&head);
    return 0;
}