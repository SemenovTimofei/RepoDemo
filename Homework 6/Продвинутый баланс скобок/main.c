#include <stdio.h>

#define MAX_LENGTH 100

int main()
{
    if (!testing())
    {
        printf("Testing failed\n");
        return 1;
    }

    char text[MAX_LENGTH] = { 0 };
    
    printf("Enter bracket sequence\n");
    scanf_s("%s", &text, MAX_LENGTH);
    
    if (bracketCheck(text))
    {
        printf("%s has correct bracket placement\n", text);
        return 0;
    }

    printf("%s has incorrect bracket placement\n", text);
    return 0;
}