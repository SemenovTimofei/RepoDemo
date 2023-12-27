#include "postfix.h"

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
                if (secondValue == 0)
                {
                    return 0;
                }
                result = firstValue / secondValue;
                break;
            }

            default:
                break;
            }

            push(&head, result);
        }
    }

    while (!isEnd(head))
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