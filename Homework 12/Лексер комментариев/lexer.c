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
                previousSymbol = current;
                state = openningSlash;
                break;
            }
        }
        case openningSlash:
        {
            if (current == '*')
            {
                size += 2;
                string = realloc(string, size);
                string[size - 2] = previousSymbol;
                string[size - 1] = current;
                string[size] = '\0';

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
            ++size;
            string = realloc(string, size);
            string[size - 1] = current;
            string[size] = '\0';

            if (current == '*')
            {
                previousSymbol = current;
                state = closingAsterisk;
                break;
            }
            break;
        }
        case closingAsterisk:
        {
            ++size;
            string = realloc(string, size);
            string[size - 1] = current;
            string[size] = '\0';

            if (current == '/')
            {
                state = start;
                break;
            }

            state = comment;
            break;
        }
        }
    }
    return string;
}