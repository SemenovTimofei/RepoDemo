#include <stdio.h>

#define MAX_SIZE 5

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
    for (int i = 0; i < columnLength - 1; ++i)
    {
        for (int j = 0; j < columnLength - i - 1; ++j)
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
}

int main()
{
    int matrix[][MAX_SIZE] = {
        { 5, 3, 2, 4, 1 },
        { 3, 2, 4, 1, 5 },
        { 2, 4, 1, 5, 3 },
        { 4, 1, 5, 3, 2 } };
    size_t columnLength = sizeof(matrix[0]) / sizeof(matrix[0][0]);
    size_t rowLength = sizeof(matrix) / sizeof(matrix[0]);
    printf("Original matrix: \n", columnLength, rowLength);
    printMatrix(matrix, columnLength, rowLength);

    sortMatrix(matrix, columnLength, rowLength);
    printf("Sorted matrix: \n");
    printMatrix(matrix, columnLength, rowLength);
    
    return 0;
}