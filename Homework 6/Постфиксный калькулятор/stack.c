#include <stdlib.h>
#include <stdbool.h>

#include "stack.h"

struct Stack
{
    int value;
    int size;
    struct Stack* next;
};

int push(struct Stack** head, const int value)
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
    return head->size;
}

int pop(struct Stack** head)
{
    if (*head == NULL)
    {
        return 1;
    }

    struct Stack* trash = *head;
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

int calculatePostfix(char* text)
{
    Stack* head = NULL;
    int firstValue = 0;
    int secondValue = 0;
    int result = 0;

    int i = 0;
    while (text[i] != '\0')
    {
        char symbol = text[i];
        ++i;

        if (symbol == ' ' || symbol == '\n')
        {
            continue;
        }

        if (symbol >= '0' && symbol <= '9')
        {
            push(&head, symbol - '0');
        }
        else
        {
            secondValue = pop(&head);
            firstValue = pop(&head);

            switch (symbol)
            {
            case '+':
            {
                result = firstValue + secondValue;
                break;
            }
            case '-':
            {
                result = firstValue - secondValue;
                break;
            }
            case '*':
            {
                result = firstValue * secondValue;
                break;
            }
            case '/':
            {
                result = firstValue / secondValue;
                break;
            }

            default:
                break;
            }

            push(&head, result);
        }
    }

    while (stackSize(head) > 1)
    {
        secondValue = pop(&head);
        firstValue = pop(&head);
        result = firstValue * secondValue;
        push(&head, result);
    }

    result = top(head);
    freeStack(&head);

    return result;
}

bool testing()
{
    bool flag = true;
    
    if (!(calculatePostfix("1 2 + 3 + 4 +") == 10))
    {
        flag = false;
    }
    if (!(calculatePostfix("4 5 * 6 *") == 120))
    {
        flag = false;
    }
    if (!(calculatePostfix("5") == 5))
    {
        flag = false;
    }
    if (!(calculatePostfix("9 3 /") == 3))
    {
        flag = false;
    }
    if (!(calculatePostfix("1 4 -") == -3))
    {
        flag = false;
    }
    if (!(calculatePostfix("9 3 + 4 * 4 - 4 /") == 11))
    {
        flag = false;
    }

    return flag;
}