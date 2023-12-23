#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LENGTH 100

size_t subStringEntries(char string[], char subString[])
{
    const size_t stringLength = strlen(string);
    const size_t subStringLength = strlen(subString);
    size_t entryCount = 0;
    for (int i = 0; i <= stringLength - subStringLength; ++i)
    {
        bool match = true;
        for (int j = 0; j < subStringLength; ++j)
        {
            if (string[i + j] != subString[j])
            {
                match = false;
                break;
            }
        }
        if (match)
        {
            ++entryCount;
        }
    }
    return entryCount;
}

bool testing()
{
    char subString[] = "abc";
    char string1[] = "abcdef";
    char string2[] = "abcdefabc";
    char string3[] = "xyz";

    if (subStringEntries(string1, subString) != 1)
    {
        return false;
    }
    if (subStringEntries(string2, subString) != 2)
    {
        return false;
    }
    if (subStringEntries(string3, subString) != 0)
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

    printf("Enter string: \n");
    char string[MAX_LENGTH] = { '\0' };
    scanf_s("%s", &string, MAX_LENGTH);

    printf("Enter substring: \n");
    char subString[MAX_LENGTH] = { '\0' };
    scanf_s("%s", &subString, MAX_LENGTH);

    printf("The number of entries: %zd\n", subStringEntries(string, subString));
    return 0;
}