#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int* firstValue, int* secondValue)
{
    int temporaryValue = *firstValue;
    *firstValue = *secondValue;
    *secondValue = temporaryValue;
}

void printArray(int array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", array[i]);
    }

    printf("\n\n");
}

void insertionSort(int array[], int size)
{
    for (int i = 1; i < size; ++i)
    {
        int comparedElement = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > comparedElement)
        {
            array[j + 1] = array[j];
            --j;
        }

        array[j + 1] = comparedElement;
    }
}

int smallNumberPartition(int array[], int size)
{
    int i = 0;
    int temporaryValue = 0;
    int j = size - 1;

    // move all numbers less than 10 to the left
    while (i < j)
    {
        while (array[i] < 10 && i < j)
        {
            ++i;
        }

        while (array[j] >= 10 && i < j)
        {
            j--;
        }

        if (i < j)
        {
            temporaryValue = array[i];
            array[i] = array[j];
            array[j] = temporaryValue;
        }
    }

    // return array position at which numbers greater than 9 start
    for (int i = 0; i < size; ++i)
    {
        if (array[i] > 9)
        {
            return i;
        }
    }

    return 0;
}

int partition(int array[], int start, int end)
{
    int pivot = array[start];
    int i = start + 1;
    int j = end;

    while (i <= j)
    {
        while (array[i] < pivot && i <= end)
        {
            ++i;
        }

        while (array[j] > pivot && j >= start + 1)
        {
            --j;
        }

        if (i <= j)
        {
            swap(&array[i], &array[j]);
            ++i;
            --j;
        }
    }

    swap(&array[start], &array[j]);

    return j;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

bool testCorrectCase()
{
    const int size = 100;
    int* array = (int*)calloc(size, size * 4);
    memset(array, 0, size * 4);

    srand((unsigned int)time(NULL));

    for (int i = 0; i < size; ++i)
    {
        array[i] = rand() % 100;
    }

    int quickSortStart = smallNumberPartition(array, size);
    insertionSort(array, quickSortStart + 1);
    quickSort(array, quickSortStart, size - 1);

    for (int i = 0; i < size - 1; ++i)
    {
        if (array[i] > array[i + 1])
        {
            return false;
        }
    }

    free(array);
    return true;
}

void main()
{
    if (!testCorrectCase())
    {
        printf("Test failed\n");
        return;
    }
    
    const int size = 20; 
    int* array = (int*)calloc(size, size * 4);
    memset(array, 0, size * 4);

    for (int i = 0; i < size; ++i)
    {
        array[i] = rand() % 20; 
    }

    printf("The original array is:\n");
    printArray(array, size);

    int quickSortStart = smallNumberPartition(array, size);

    printf("The array with single digit numbers coupled at the beginning:\n");
    printArray(array, size);

    insertionSort(array, quickSortStart + 1);

    printf("The array with single digit numbers sorted:\n");
    printArray(array, size);

    quickSort(array, quickSortStart, size - 1);

    printf("The array with non-single numbers sorted:\n");
    printArray(array, size);

    free(array);
}