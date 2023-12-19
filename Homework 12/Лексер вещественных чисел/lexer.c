#include "lexer.h"

bool isRealNumber(char text[])
{
    int state = start;
    for (size_t i = 0; text[i - 1] != '\0' || i == 0; ++i)
    {
        switch (state)
        {
        case start:
        {
            if (isdigit(text[i]))
            {
                state = integer;
                break;
            }
            return false;
        }
        case integer:
        {
            if (isdigit(text[i]))
            {
                state = integer;
                break;
            }
            if (text[i] == '.')
            {
                state = decimalPoint;
                break;
            }
            return text[i] == '\0';
        }
        case decimalPoint:
        {
            if (isdigit(text[i]))
            {
                state = decimalDigit;
                break;
            }
            return false;
        }
        case decimalDigit:
        {
            if (isdigit(text[i]))
            {
                state = decimalDigit;
                break;
            }
            if (text[i] == 'E')
            {
                state = exponent;
                break;
            }
            return text[i] == '\0';
        }
        case exponent:
        {
            if (isdigit(text[i]))
            {
                state = exponentDigit;
                break;
            }
            if (text[i] == '+' || text[i] == '-')
            {
                state = exponentSign;
                break;
            }
        }
        case exponentSign:
        {
            if (isdigit(text[i]))
            {
                state = exponentDigit;
                break;
            }
            return false;
        }
        case exponentDigit:
        {
            if (isdigit(text[i]))
            {
                state = exponentDigit;
                break;
            }
            return text[i] == '\0';
        }
        }
    }
}