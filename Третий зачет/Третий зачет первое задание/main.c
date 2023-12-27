#include <stdio.h>

#include "matrixSort.h"
#include "test.h"

int main()
{
    if (!testing())
    {
        printf("Testing failed\n");
        return 1;
    }

    // columns are horizontal and rows are vertical...
    int matrix[][MAX_SIZE] = {
        { 5, 3, 2, 4, 1 },
        { 3, 2, 4, 1, 5 },
        { 2, 4, 1, 5, 3 },
        { 4, 1, 5, 3, 2 } };
    size_t columnLength = sizeof(matrix[0]) / sizeof(matrix[0][0]);
    size_t rowLength = sizeof(matrix) / sizeof(matrix[0]);
    printf("Original matrix: \n");
    printMatrix(matrix, columnLength, rowLength);

    sortMatrix(matrix, columnLength, rowLength);
    printf("Sorted matrix: \n");
    printMatrix(matrix, columnLength, rowLength);
    
    return 0;
}