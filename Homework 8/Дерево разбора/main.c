#include <stdio.h>
#include <string.h>

#include "tree.h"
#include "test.h"

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
        printf("File not found");
        return 1;
    }

    char expression[MAX_EXPRESSION_LENGTH];
    fgets(expression, MAX_EXPRESSION_LENGTH, file);
    fclose(file);

    ParseTree* tree = build(expression);

    printf("Prefix expression: ");
    printParseTree(tree);
    printf("\nThe result is: %d\n", calculate(tree));

    deleteParseTree(&tree);
    return 0;
}