#include "graph.h"

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], size_t n)
{
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < n; ++j)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void writeToFile(int matrix[MAX_SIZE][MAX_SIZE], size_t n, char fileName[])
{
    FILE* output = fopen(fileName, "w");
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < n; ++j)
        {
            fprintf(output, "%d ", matrix[i][j]);
        }
        fprintf(output, "\n");
    }

    fclose(output);
    return;
}

void transitiveClosure(int matrix[MAX_SIZE][MAX_SIZE], size_t n, char fileName[])
{
    int newMatrix[MAX_SIZE][MAX_SIZE];
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < n; ++j)
        {
            newMatrix[i][j] = matrix[i][j];
        }
    }

    for (size_t k = 0; k < n; ++k)
    {
        for (size_t i = 0; i < n; ++i)
        {
            for (size_t j = 0; j < n; ++j)
            {
                newMatrix[i][j] = newMatrix[i][j] || (newMatrix[i][k] && newMatrix[k][j]);
            }
        }
    }

    writeToFile(newMatrix, n, fileName);
    return;
}