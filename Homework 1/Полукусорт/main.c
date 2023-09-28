#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int* firstValue, int* secondValue)
{
    int temporaryValue = *firstValue;
    *firstValue = *secondValue;
    *secondValue = temporaryValue;
}

int partition(int array[], int length)
{
    int pivot = array[0];
    int pivotPosition = 1;

    for (int i = pivotPosition; i <= length; i++)
    {
        if (array[i] < pivot)
        {
            swap(&array[pivotPosition], &array[i]);
            pivotPosition++;
        }
    }

    swap(&array[0], &array[pivotPosition - 1]);

    return pivotPosition - 1;
}

void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");
}

bool testCorrectCase(int pivotPosition, int array[], int size)
{
    for (int i = 0; i < pivotPosition; ++i)
    {
        if (array[i] > array[pivotPosition])
        {
            return false;
        }
    }

    for (int i = pivotPosition; i < size; ++i)
    {
        if (array[i] < array[pivotPosition])
        {
            return false;
        }
    }

    return true;
}

void main()
{
    const int size = 10;
    int* array = (int*)malloc(size * 4);
    memset(array, 0, size * 4);

    srand(time(NULL));

    for (int i = 0; i < size; ++i)
    {
        array[i] = rand() % 100;
    }

    printf("The original array is: ");
    printArray(array, size);

    int pivotPosition = partition(array, size - 1);

    if (!testCorrectCase(pivotPosition, array, size))
    {
        printf("Test failed\n");
        return;
    }

    printf("The divided array is: ");
    printArray(array, size);

    return;
}