#include "matrixSort.h"

void swapColumns(int martix[][MAX_SIZE], size_t firstColumn, size_t secondColumn, size_t rowLength)
{
    for (int i = 0; i < rowLength; ++i)
    {
        int temporary = martix[i][firstColumn];
        martix[i][firstColumn] = martix[i][secondColumn];
        martix[i][secondColumn] = temporary;
    }
}

void sortMatrix(int martix[][MAX_SIZE], size_t columnLength, size_t rowLength)
{
    for (size_t i = 0; i < columnLength - 1; ++i)
    {
        for (size_t j = 0; j < columnLength - i - 1; ++j)
        {
            if (martix[0][j] > martix[0][j + 1])
            {
                swapColumns(martix, j, j + 1, rowLength);
            }
        }
    }
}

void printMatrix(int martix[][MAX_SIZE], size_t columnLength, size_t rowLength)
{
    for (size_t i = 0; i < rowLength; ++i)
    {
        for (size_t j = 0; j < columnLength; ++j)
        {
            printf("%d ", martix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}