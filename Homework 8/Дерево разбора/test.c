#include <stdbool.h>
#include <stdio.h>

#include "test.h"

bool testing()
{
    FILE* file1 = NULL;

    fopen_s(&file1, "test1.txt", "r");
    if (file1 == NULL)
    {
        return false;
    }

    char expression1[MAX_EXPRESSION_LENGTH];
    fgets(expression1, MAX_EXPRESSION_LENGTH, file1);
    fclose(file1);

    ParseTree* tree1 = build(expression1);

    if (calculate(tree1) != 5)
    {
        deleteParseTree(&tree1);
        return false;
    }
    deleteParseTree(&tree1);

    FILE* file2 = NULL;

    fopen_s(&file2, "test2.txt", "r");
    if (file2 == NULL)
    {
        return false;
    }

    char expression2[MAX_EXPRESSION_LENGTH];
    fgets(expression2, MAX_EXPRESSION_LENGTH, file2);
    fclose(file2);

    ParseTree* tree2 = build(expression2);

    if (calculate(tree2) != 16)
    {
        deleteParseTree(&tree2);
        return false;
    }

    deleteParseTree(&tree2);
    return true;
}