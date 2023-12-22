#include <stdio.h>
#include <stdlib.h>

#define MATRIX_SIZE 6
#define EXPRESSION_SIZE 100

int main()
{
    // GraphVizDotExe is system path for C:\Program Files\Graphviz\bin\dot.exe
    char* dotExePath = getenv("GraphVizDotExe");
    if (dotExePath == NULL)
    {
        dotExePath = "C:\\Program Files\\Graphviz\\bin\\dot.exe";
    }

    int matrix[MATRIX_SIZE][MATRIX_SIZE] = {
    { 0, 1, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 1, 0 },
    { 0, 0, 0, 1, 1, 0 },
    { 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 1, 0, 1 },
    { 0, 0, 0, 0, 0, 0 } };

    char dotFileName[] = "graph.dot";

    FILE* file = NULL;
    fopen_s(&file, dotFileName, "w");
    if (file == NULL)
    {
        printf("Error openning file\n");
        return 1;
    }

    fprintf(file, "digraph Graph {\n");
    for (size_t i = 0; i < MATRIX_SIZE; ++i)
    {
        for (size_t j = 0; j < MATRIX_SIZE; ++j)
        {
            if (matrix[i][j] == 1)
            {
                fprintf(file, "%zd -> %zd;\n", i, j);
            }
        }
    }
    fprintf(file, "}\n");
    fclose(file);

    char command[EXPRESSION_SIZE] = { '\0' };
    char pngFileName[] = "graph.png";
    sprintf_s(command, EXPRESSION_SIZE, "\"%s\" -Tpng %s -o %s", dotExePath, dotFileName, pngFileName);
    system(command);

    sprintf_s(command, EXPRESSION_SIZE, "start %s", pngFileName);
    system(command);

    return 0;
}