#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LENGTH 100

void deleteCopies(char string[])
{
    char* current = string;
    char* example = string + 1;

    while (*example != NULL)
    {
        if (*example != *current)
        {
            ++current;
            *current = *example;
        }
        ++example;
    }

    *(++current) = '\0';
}

bool testing()
{

}

int main()
{
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
}

// aababaasddsaaabsaasss
// ababasdsabsas