#include "lexer.h"

int main()
{
    FILE* file = NULL;
    fopen_s(&file, "text.c", "r");
    if (file == NULL)
    {
        printf("Error openning file\n");
        return 1;
    }

    printComment(file);

    fclose(file);
    return 0;
}