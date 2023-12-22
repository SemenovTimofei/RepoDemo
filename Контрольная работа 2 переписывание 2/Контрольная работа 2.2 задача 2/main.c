#include <stdio.h>

#define MAX_SIZE 100

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

void writeToFile(int matrix[MAX_SIZE][MAX_SIZE], size_t n) // change to FILE* file later
{
    FILE* output = fopen("output.txt", "w");
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < n; ++j)
        {
            fprintf(output, "%d ", matrix[i][j]);
        }
        fprintf(output, "\n");
    }

    printMatrix(matrix, n);
    fclose(output);
    return;
}

void transitiveClosure(int matrix[MAX_SIZE][MAX_SIZE], size_t n)
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
    
    writeToFile(newMatrix, n);
    return;
}

int main()
{
    size_t n = 0;
    FILE* input = NULL;
    fopen_s(&input, "input.txt", "r");
    if (input == NULL)
    {
        printf("Error openning file\n");
        return 1;
    }
    fscanf_s(input, "%d", &n);

    int matrix[MAX_SIZE][MAX_SIZE];
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < n; ++j)
        {
            fscanf_s(input, "%d", &matrix[i][j]);
        }
    }

    printMatrix(matrix, n);
    printf("\n");
    transitiveClosure(matrix, n);

    fclose(input);
    return 0;
}