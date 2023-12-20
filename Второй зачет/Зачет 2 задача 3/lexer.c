#include "lexer.h"

bool isValid(char text[])
{
    int state = 0;
    for (size_t i = 0; i == 0 || text[i - 1] != '\0'; ++i)
    {
        switch (state)
        {
        case 0:
        {
            if (isalpha(text[i]))
            {
                state = 1;
                break;
            }
            return false;
        }
        case 1:
        {
            if (isalpha(text[i]) || isdigit(text[i]) || text[i] == '_')
            {
                state = 1;
                break;
            }
            return text[i] == '\0';
        }
        }
    }
}