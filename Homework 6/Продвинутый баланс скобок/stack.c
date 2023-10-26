#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "stack.h"

struct Stack
{
    char value;
    int size;
    struct Stack* next;
};

int push(struct Stack** head, const char value)
{
    struct Stack* next = malloc(sizeof(struct Stack));
    if (next == NULL)
    {
        return 1;
    }
    next->value = value;
    next->next = *head;
    next->size = (*head == NULL) ? 1 : (*head)->size + 1;
    *head = next;
    return 0;
}

int stackSize(Stack* head)
{
    if (head == NULL)
    {
        return 0;
    }
    return head->size;
}

char pop(struct Stack** head)
{
    if (*head == NULL)
    {
        return 1;
    }

    struct Stack* trash = *head;
    *head = (*head)->next;
    char value = trash->value;

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

char top(Stack* head)
{
    if (head == NULL)
    {
        return 0;
    }

    return head->value;
}

char findPair(char bracket)
{
    if (bracket == ')')
    {
        return '(';
    }
    if (bracket == '}')
    {
        return '{';
    }
    if (bracket == ']')
    {
        return '[';
    }
    if (bracket == '(')
    {
        return ')';
    }
    if (bracket == '{')
    {
        return '}';
    }
    if (bracket == '[')
    {
        return ']';
    }
}

bool bracketCheck(char* text) //)(
{
    Stack* head = NULL;

    for (int i = 0; i < strlen(text); ++i)
    {
        if (strchr("({[", text[i]))
        {
            push(&head, text[i]);
        }
        else if (strchr(")}]", text[i]))
        {
            if (stackSize(head) == 0)
            {
                return false;
            }

            if (!(top(head) == findPair(text[i])))
            {
                freeStack(&head);
                return false;
            }

            pop(&head);
        }
    }

    if (stackSize(head) > 0)
    {
        freeStack(&head);
        return false;
    }

    freeStack(&head);
    return true;
}