#include "stack.h"

typedef struct Stack
{
    int value;
    Stack* next;
} Stack;

int push(Stack** head, const int value)
{
    Stack* next = malloc(sizeof(Stack));
    if (next == NULL)
    {
        return 1;
    }
    next->value = value;
    next->next = *head;
    *head = next;

    return 0;
}

int pop(Stack** head)
{
    if (*head == NULL)
    {
        return 0;
    }

    Stack* trash = *head;
    *head = (*head)->next;
    int value = trash->value;

    free(trash);
    return value;
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

int top(Stack* head)
{
    if (head == NULL)
    {
        return 0; 
    }

    return head->value;
}

bool isEnd(Stack* head)
{
    return head->next == NULL;
}