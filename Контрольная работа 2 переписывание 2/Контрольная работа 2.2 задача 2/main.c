#include "graph.h"
#include "test.h"

int main()
{
    if (!testing())
    {
        printf("Testing failed\n");
        return 1;
    }

    FILE* input = NULL;
    fopen_s(&input, "input.txt", "r");
    if (input == NULL)
    {
        printf("Error openning file\n");
        return 1;
    }

    size_t n = 0;
    fscanf_s(input, "%d", &n);

    int matrix[MAX_SIZE][MAX_SIZE];
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < n; ++j)
        {
            fscanf_s(input, "%d", &matrix[i][j]);
        }
    }

    printf("The original matrix: \n");
    printMatrix(matrix, n);

    transitiveClosure(matrix, n, "output.txt");

    fclose(input);
    return 0;
}