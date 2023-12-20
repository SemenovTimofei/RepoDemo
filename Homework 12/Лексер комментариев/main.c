#include "lexer.h"
#include "test.h"

int main()
{
    if (!testing())
    {
        printf("Testing failed\n");
        //return 1;
    }

    FILE* file = NULL;
    fopen_s(&file, "text.txt", "r"); 
    if (file == NULL)
    {
        printf("Error openning file\n");
        fclose(file);
        return 1;
    }

    printf("%s", getComment(file));

    fclose(file);
    return 0;
}