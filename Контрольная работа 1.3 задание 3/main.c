#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 100

char* makeString(char string[], size_t length)
{
    char* newString = malloc(MAX_LENGTH);

    for (size_t i = 0; i < length - 1; ++i)
    {
        if (string[i] != string[i + 1])
        {
            printf("%c", string[i]);
            newString[i] = string[i];
            //printf("help %c\n", newString);
        }
    }
    
    //printf("pls %s\n", newString);
    return string;
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

    /*
    char* newString = malloc(MAX_LENGTH);
    strcpy_s(newString, sizeof(string), string);
    printf("test %s test", newString);
    */


    makeString(string, strlen(string));
    //printf("aboba %s\n", makeString(string, strlen(string)));
}