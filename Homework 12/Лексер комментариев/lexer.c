#include "lexer.h"

char* getComment(FILE* file)
{
    int state = start;
    char current = '\0';
    char previousSymbol = '\0';

    char* string = NULL;
    size_t size = 0;

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
                ++size;
                string = realloc(string, size);
                string[size - 1] = current;
                string[size] = '\0';
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
                ++size;
                string = realloc(string, size);
                string[size - 1] = current;
                string[size] = '\0';
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
            size += 2;
            string = realloc(string, size);
            string[size - 2] = previousSymbol;
            string[size - 1] = current;
            string[size] = '\0';

            state = comment;
            break;
        }
        }
    }
    return string;
}