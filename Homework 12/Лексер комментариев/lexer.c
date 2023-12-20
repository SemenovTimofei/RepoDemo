#include "lexer.h"

void printComment(FILE* file)
{
    int state = start;
    char current = '\0';
    char previousSymbol = '\0';

    while (current != EOF)
    {
        current = fgetc(file);
        switch (state)
        {
        case start:
        {
            if (current == '/')
            {
                state = openningSlash;
                break;
            }
        }
        case openningSlash:
        {
            if (current == '*')
            {
                state = openningAsterisk;
                break;
            }
            state = start;
            break;
        }
        case openningAsterisk:
        {
            if (current != '*')
            {
                state = comment;
                break;
            }
            state = closingAsterisk;
            break;
        }
        case comment:
        {
            if (current != '*')
            {
                printf("%c", current);
                break;
            }
            previousSymbol = current;
            state = closingAsterisk;
            break;
        }
        case closingAsterisk:
        {
            if (current == '/')
            {
                state = start;
                break;
            }
            printf("%c%c", previousSymbol, current);
            state = comment;
            break;
        }
        }
    }

    if (state != start)
    {
        printf("\nIncomplete comment\n");
    }
}