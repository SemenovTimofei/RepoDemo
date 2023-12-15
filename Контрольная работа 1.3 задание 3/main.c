#include <stdio.h>
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
    bool flag = true;
    FILE* file1 = NULL;
    fopen_s(&file1, "test1.txt", "r");
    if (file1 == NULL)
    {
        flag = false;
    }

    char string1[MAX_LENGTH] = { '\0' };
    if (fscanf_s(file1, "%s", string1, MAX_LENGTH) != 1)
    {
        flag = false;
    }

    deleteCopies(string1);
    if (strcmp(string1, "ababababab") != 0)
    {
        flag = false;
    }

    fclose(file1);

    FILE* file2 = NULL;
    fopen_s(&file2, "test2.txt", "r");
    if (file2 == NULL)
    {
        flag = false;
    }

    char string2[MAX_LENGTH] = { '\0' };
    if (fscanf_s(file2, "%s", string2, MAX_LENGTH) != 1)
    {
        flag = false;
    }

    deleteCopies(string2);
    if (strcmp(string2, "abababa\qwewrty") != 0) // the function doesn't work with line breaks, so the testing will be failed
    {
        flag = false;
    }

    fclose(file2);
    return flag;
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
        fclose(file);
        return 1;
    }

    char string[MAX_LENGTH] = { '\0' };
    if (fscanf_s(file, "%s", string, MAX_LENGTH) != 1)
    {
        printf("Error openning file\n");
    }

    printf("The original string: %s\n", string);
    deleteCopies(string);
    printf("The edited string: %s\n", string);

    fclose(file);
    return 0;
}