#include "test.h"

int* createRandomArray(size_t size)
{
    int* array = (int*)calloc(size, sizeof(int));
    if (array == NULL)
    {
        return NULL;
    }
    srand((unsigned int)time(NULL));
    for (size_t i = 0; i < size; ++i)
    {
        array[i] = rand();
    }
    return array;
}

bool compareArrays(int firstArray[], int secondArray[], size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (firstArray[i] != secondArray[i])
        {
            return false;
        }
    }
    return true;
}

bool isSorted(int array[], size_t size)
{
    for (size_t i = 1; i < size; ++i)
    {
        if (array[i - 1] > array[i])
        {
            return false;
        }
    }
    return true;
}

bool testing()
{
    // testing quick sort module
    int array1[21] = { -10, 10, -9, 9, -8, 8, -7, 7, -6, 6, -5, 5, -4, 4, -3, 3, -2, 2, -1, 1, 0 };
    int result1[21] = { -10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    insertionSort(array1, 0, 20);
    if (!compareArrays(array1, result1, 21))
    {
        return false;
    }

    int* array2 = createRandomArray(50);
    quickSort(array2, 0, 49);
    if (!isSorted(array2, 50))
    {
        free(array2);
        return false;
    }

    free(array2);

    // testing most common element module
    int array3[] = { 1, 1, 1, 1, 1, 1, 2, 3, 4, 4, 5, 6, 7, 8, 9, 0, 0, 0, 9, 3321, 312, 3, 32, 323, 333, 33333333, 3333333 };
    size_t length = sizeof(array3) / sizeof(array3[0]);
    quickSort(array3, 0, length - 1);
    if (findMostCommonElement(array3, length) != 1)
    {
        return false;
    }

    return true;
}