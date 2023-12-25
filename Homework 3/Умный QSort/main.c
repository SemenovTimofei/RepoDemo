#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10

void swap(int* firstValue, int* secondValue)
{
    int temporaryValue = *firstValue;
    *firstValue = *secondValue;
    *secondValue = temporaryValue;
}

void printArray(int* array, int size)
{
    for (int i = 0; i < size; ++i)
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
            j--;
        }
        array[j + 1] = key;
    }
}

size_t partition(int* array, size_t start, size_t end)
{
    size_t pivot = start;
    size_t i = start;
    size_t j = end;
    while (i < j)
    {
        while (array[i] <= array[pivot] && i < j)
        {
            ++i;
        }
        while (array[j] > array[pivot])
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

void quickSort(int* array, size_t start, size_t end)
{
    if (end - start < 10)
    {
        insertionSort(array, start, end);
        return;
    }
    if (start < end) // delete later ???
    {
        size_t pivot = partition(array, start, end);
        quickSort(array, start, pivot - 1);
        quickSort(array, pivot + 1, end);
    }
}

int main()
{
    int array[10] = { 1, 0, 2, 9, 3, 8, 4, 7, 5, 6 };
    quickSort(array, 0, 9);
    printArray(array, 10);
}