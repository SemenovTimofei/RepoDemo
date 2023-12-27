#include "quickSort.h"

void swap(int* firstValue, int* secondValue)
{
    int temporaryValue = *firstValue;
    *firstValue = *secondValue;
    *secondValue = temporaryValue;
}

void printArray(int* array, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void insertionSort(int array[], size_t start, size_t end)
{
    for (size_t i = start + 1; i <= end; ++i)
    {
        int key = array[i];
        size_t j = i - 1;
        while (j >= start && array[j] > key)
        {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
}

size_t partition(int array[], size_t start, size_t end)
{
    int pivot = array[start];
    size_t i = start;
    size_t j = end;
    while (i < j)
    {
        while (array[i] <= pivot && i < end)
        {
            ++i;
        }
        while (array[j] > pivot)
        {
            --j;
        }
        if (i < j)
        {
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[start], &array[j]);
    return j;
}

void quickSort(int array[], size_t start, size_t end)
{
    if (start < end)
    {
        if (end - start < 10)
        {
            insertionSort(array, start, end);
            return;
        }
        size_t pivot = partition(array, start, end);
        quickSort(array, start, pivot - 1);
        quickSort(array, pivot + 1, end);
    }
}