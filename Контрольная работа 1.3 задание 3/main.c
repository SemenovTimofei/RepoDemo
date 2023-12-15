#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LENGTH 100

void deleteCopies(char string[])
{
    char* newString = string;
    char* example = string + 1;

    while (*example != NULL)
    {
        if (*example != *newString)
        {
            ++newString;
            *newString = *example;
        }
        ++example;
    }

    *(++newString) = '\0';
}

bool testing()
{
    FILE* file1 = NULL;
    fopen_s(&file1, "test1.txt", "r");
    if (file1 == NULL)
    {
        return false;
    }

    char string1[MAX_LENGTH] = { '\0' };
    if (fscanf_s(file1, "%s", string1, MAX_LENGTH) != 1)
    {
        return false;
    }

    deleteCopies(string1);
    if (strcmp(string1, "ababababab") != 0)
    {
        return false;
    }

    FILE* file2 = NULL;
    fopen_s(&file2, "test2.txt", "r");
    if (file2 == NULL)
    {
        return false;
    }

    char string2[MAX_LENGTH] = { '\0' };
    if (fscanf_s(file2, "%s", string2, MAX_LENGTH) != 1)
    {
        return false;
    }

    deleteCopies(string2);
    if (strcmp(string2, "abababa\nqwewrty") != 0)
    {
        return false;
        printf("f %s f", string2);
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
    FILE* file = NULL;
    fopen_s(&file, "text.txt", "r");
    if (file == NULL)
    {
        printf("Error openning file\n");
        return 1;
    }

    char string[MAX_LENGTH] = { '\0' };
    if (fscanf_s(file, "%s", string, MAX_LENGTH) != 1)
    {
        printf("Error openning file\n");
    }

    deleteCopies(string);
    printf("The edited string: %s\n", string);

    return 0;
}