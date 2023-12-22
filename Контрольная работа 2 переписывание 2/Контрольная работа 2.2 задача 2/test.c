#include "test.h"

bool compareMatrices(int firstMatrix[MAX_SIZE][MAX_SIZE], int secondMatrix[MAX_SIZE][MAX_SIZE], size_t n)
{
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < n; ++j)
        {
            if (firstMatrix[i][j] != secondMatrix[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

bool testing()
{
    // check overall algorith work
    FILE* file = NULL;
    fopen_s(&file, "testInput.txt", "r");
    if (file == NULL)
    {
        return false;
    }

    size_t n = 0;
    fscanf_s(file, "%d", &n);

    int matrix[MAX_SIZE][MAX_SIZE];
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < n; ++j)
        {
            fscanf_s(file, "%d", &matrix[i][j]);
        }
    }
    transitiveClosure(matrix, n, "testOutput.txt");

    // check algorithm correctness
    FILE* input = NULL;
    fopen_s(&input, "testOutput.txt", "r");
    if (input == NULL)
    {
        return false;
    }

    int firstMatrix[MAX_SIZE][MAX_SIZE];
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < n; ++j)
        {
            fscanf_s(input, "%d", &firstMatrix[i][j]);
        }
    }

    // correct matrix
    int secondMatrix[MAX_SIZE][MAX_SIZE] = { 
        { 0, 1, 1, 1, 1, 1 }, 
        { 0, 0, 1, 1, 1, 1 },  
        { 0, 0, 0, 1, 1, 1 }, 
        { 0, 0, 0, 0, 0, 0 }, 
        { 0, 0, 0, 1, 0, 1 }, 
        { 0, 0, 0, 0, 0, 0 } };

    if (!compareMatrices(firstMatrix, secondMatrix, n))
    {
        return false;
    }

    // incorrect matrix (just like the second matrix, but the last line is changed)
    int thirdMatrix[MAX_SIZE][MAX_SIZE] = {
        { 0, 1, 1, 1, 1, 1 },
        { 0, 0, 1, 1, 1, 1 },
        { 0, 0, 0, 1, 1, 1 },
        { 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 1, 0, 1 },
        { 0, 0, 0, 0, 0, 1 } };

    if (compareMatrices(firstMatrix, thirdMatrix, n))
    {
        return false;
    }

    return true;
}