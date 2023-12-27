#include "test.h"

bool compareMatrices(int firstMatrix[][MAX_SIZE], int secondMatrix[][MAX_SIZE], size_t columnLength, size_t rowLength)
{

}

bool testing()
{
    int matrix[][MAX_SIZE] = {
        { 10, 7321, -213, 6363, 0 },
        { 123, -4324, 32, -321, 90 },
        { 9321, -444, 9096, 332, 666 },
        { 464, 12, 2, 3, 0 },
        { 0, 3, -12, -88888, 123} };
    size_t columnLength = sizeof(matrix[0]) / sizeof(matrix[0][0]);
    size_t rowLength = sizeof(matrix) / sizeof(matrix[0]);

    if (columnLength != 5 || rowLength != 5)
    {
        return false;
    }

    return true;
}