#include "lexer.h"

#define EXPRESSION_SIZE 50

int main()
{
    if (!testing())
    {
        printf("Testing failed\n");
        return 1;
    }

    printf("Enter a number: \n");
    char text[EXPRESSION_SIZE] = { '\0' };
    scanf_s("%s", &text, EXPRESSION_SIZE);

    if (isRealNumber(text))
    {
        printf("%s is a real number\n", text);
    }
    else
    {
        printf("%s is not a real number\n", text);
    }

    return 0;
}