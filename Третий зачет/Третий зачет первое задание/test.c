#include "test.h"

bool compareMatrices(int firstMatrix[][MAX_SIZE], int secondMatrix[][MAX_SIZE], size_t columnLength, size_t rowLength)
{
    for (size_t i = 0; i < rowLength; ++i)
    {
        for (size_t j = 0; j < columnLength; ++j)
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
    int originalMatrix[][MAX_SIZE] = {
        { 10, 7321, -213, 6363, 0 },
        { 123, -4324, 32, -321, 90 },
        { 9321, -444, 9096, 332, 666 },
        { 464, 12, 2, 3, 0 }, };
    size_t columnLength = sizeof(originalMatrix[0]) / sizeof(originalMatrix[0][0]);
    size_t rowLength = sizeof(originalMatrix) / sizeof(originalMatrix[0]);

    if (columnLength != 5 || rowLength != 4)
    {
        return false;
    }

    sortMatrix(originalMatrix, columnLength, rowLength);

    // testing whether the original matrix was sorted
    int originalMatrixCopy[][MAX_SIZE] = {
        { 10, 7321, -213, 6363, 0 },
        { 123, -4324, 32, -321, 90 },
        { 9321, -444, 9096, 332, 666 },
        { 464, 12, 2, 3, 0 }, };

    if (compareMatrices(originalMatrix, originalMatrixCopy, columnLength, rowLength))
    {
        return false;
    }

    // testing whether the original matrix is sorted correctly
    int sortedMatrix[][MAX_SIZE] = {
        { -213, 0, 10, 6363, 7321 },
        { 32, 90, 123, -321, -4324 },
        { 9096, 666, 9321, 332, -444 },
        { 2, 0, 464, 3, 12 }
    };

    if (!compareMatrices(originalMatrix, sortedMatrix, columnLength, rowLength))
    {
        return false;
    }

    return true;
}