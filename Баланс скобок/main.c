#include <stdio.h>
#include <stdbool.h>

#define MAX_LENGTH 100

bool bracketBalance(char text[])
{
    int count = 0;
    for (size_t i = 0; text[i] != '\0'; ++i)
    {
        if (text[i] == '(')
        {
            ++count;
        }
        else if (text[i] == ')')
        {
            --count;
        }
        if (count < 0)
        {
            return false;
        }
    }

    return count == 0;
}

bool testing()
{
    if (!bracketBalance("(())"))
    {
        return false;
    }
    if (!bracketBalance("(()())"))
    {
        return false;
    }
    if (bracketBalance(")("))
    {
        return false;
    }
    if (bracketBalance("("))
    {
        return false;
    }
    if (bracketBalance(")"))
    {
        return false;
    }
    return true;
}

int main()
{
    if (!testing())
    {
        printf("Testing failed\n");
        return 1;
    }

    printf("Enter text: \n");
    char text[MAX_LENGTH] = { '\0' };
    scanf_s("%s", &text, MAX_LENGTH);

    if (bracketBalance(text))
    {
        printf("The bracket placement is corrent\n");
        return 0;
    }
    printf("The bracket placement is incorrect\n");
    return 0;
}