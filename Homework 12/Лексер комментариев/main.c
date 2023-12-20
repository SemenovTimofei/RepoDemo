#include "lexer.h"

int main()
{
    FILE* file = NULL;
    // text.txt is used to show how an uncompleted comment works
    // text.c is given to show how it works with c file (there's no difference as far as I know)
    fopen_s(&file, "text.txt", "r"); 
    if (file == NULL)
    {
        printf("Error openning file\n");
        return 1;
    }

    printComment(file);

    fclose(file);
    return 0;
}