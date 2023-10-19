#include <stdlib.h>

#include "stack.h"

struct Stack
{
    int value;
    struct Stack* next;
};

ErrorCode push(struct Stack** head, const int value)
{
    struct Stack* next = malloc(sizeof(struct Stack));
    if (next == NULL)
    {
        return stackIsEmpty;
    }
    next->value = value;
    next->next = *head;
    *head = next;
    return ok;
}

int pop(struct Stack** head)
{
    if (*head == NULL)
    {
        return stackIsEmpty;
    }

    struct Stack* trash = *head;
    *head = (*head)->next;
    free(trash);
    return 0;
}

void freeStack(Stack** head)
{
    if (head == NULL || *head == NULL)
    {
        return;
    }
    Stack* next = (*head)->next;
    free(*head);
    while (next != NULL)
    {
        Stack* temp = next;
        next = next->next;
        free(temp);
    }
}

int top(Stack* head, ErrorCode* errorCode)
{
    if (head == NULL)
    {
        *errorCode = stackIsEmpty;
        return 404;
    }
    
    *errorCode = ok;
    return head->value;
}