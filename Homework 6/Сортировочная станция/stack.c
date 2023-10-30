#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "stack.h"

struct Stack
{
    char value;
    int size;
    struct Stack* next;
};

Stack* initializeStack()
{
    Stack* stack = calloc(1, sizeof(Stack));
    return stack;
}

int push(struct Stack** head, const int value)
{
    struct Stack* next = malloc(sizeof(struct Stack));
    if (next == NULL)
    {
        return 1;
    }

    next->value = value;
    next->size = (*head == NULL) ? 1 : (*head)->size + 1;
    next->next = *head;
    *head = next;

    return 0;
}

int stackSize(Stack* head)
{
    return head->size;
}

char pop(struct Stack** head)
{
    if (*head == NULL)
    {
        return NULL;
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
        return NULL;
    }

    return head->value;
}

int priority(char operation)
{
    switch (operation)
    {
    case '*':
    case '/':
    case '%':
        return 2;
    case '+':
    case '-':
        return 1;
    }

    return 0;
}

char* infixToPostfix(char* text)
{
    Stack* input = initializeStack();
    Stack* output = initializeStack();
    size_t length = strlen(text);

    for (int i = 0; i < length; ++i)
    {
        if ('0' <= text[i] && text[i] <= '9')
        {
            push(&output, text[i]);
        }
        else if (text[i] == '(')
        {
            push(&input, text[i]);
        }
        else if (text[i] == ')')
        {
            char element = pop(&input);
            while (element != '(')
            {
                push(&output, element);
                element = pop(&input);
            }
        }
        else if (strchr("*-+/", text[i]))
        {
            while (priority(text[i]) <= priority(top(input)))
            {
                push(&output, pop(&input));
            }
            push(&input, text[i]);
        }

        text[i] = 0;
    }

    while (stackSize(input) != 0)
    {
        push(&output, pop(&input));
    }

    for (int i = (stackSize(output) - 1) * 2; i > 0; i -= 2)
    {
        text[i] = pop(&output);
        text[i - 1] = ' ';
    }

    text[0] = pop(&output);

    freeStack(&input);
    freeStack(&output);
}

bool testing()
{
    char test1[] = "(2 + 2 * 2) / 2";
    char result1[] = "2 2 2 * + 2 /";
    char test2[] = "3 + 4 * 2 / (5 - 1)";
    char result2[] = "3 4 2 * 5 1 - / +";
    char test3[] = "1 + 2";
    char result3[] = "1 2 +";
    char test4[] = "1 + 2 + 3 + 4";
    char result4[] = "1 2 + 3 + 4 +";

    infixToPostfix(test1);
    infixToPostfix(test2);
    infixToPostfix(test3);
    infixToPostfix(test4);

    if (strcmp(test1, result1) != 0)
    {
        return false;
    }
    if (strcmp(test2, result2) != 0)
    {
        return false;
    }
    if (strcmp(test3, result3) != 0)
    {
        return false;
    }
    if (strcmp(test4, result4) != 0)
    {
        return false;
    }

    return true;
}