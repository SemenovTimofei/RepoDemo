#include <stdio.h>

#define MAX_LENGTH 100

int main()
{
    char text[MAX_LENGTH] = { 0 };
    
    printf("Enter\n");
    scanf_s("%s", &text, MAX_LENGTH);
    //char text[] = "()(([]))";
    if (bracketCheck(text))
    {
        printf("%s has correct bracket placement\n", text);
        return 0;
    }
    printf("%s has incorrect bracket placement\n", text);
    return 0;
}