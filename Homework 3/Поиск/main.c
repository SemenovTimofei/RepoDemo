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
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");
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
            --j;
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

void quickSort(int array[], int start, int end)
{
    if (start < end)
    {
        int pivotIndex = partition(array, start, end);
        quickSort(array, start, pivotIndex - 1);
        quickSort(array, pivotIndex + 1, end);
    }
}

bool binarySearch(int array[], int start, int end, int key)
{
    // sort the main array
    int quickSortStart = smallNumberPartition(array, end);
    insertionSort(array, quickSortStart + 1);
    quickSort(array, quickSortStart, end - 1);

    // binary search for key element
    if (start <= end)
    {
        int middle = start + (end - start) / 2;

        if (array[middle] == key)
            return true;

        if (array[middle] > key)
            return binarySearch(array, start, middle - 1, key);

        return binarySearch(array, middle + 1, end, key);
    }

    return false;
}

bool testCorrectCase()
{
    int array1[] = { 1, 3, 5, 7, 9 };
    int searchArray1[] = { 0, 2, 4, 6, 8 };
    for (int i = 0; i < 5; ++i)
    {
        if (binarySearch(array1, 0, 5, searchArray1[i]))
        {
            return false;
        }
    }

    int array2[] = { -2, -4, -6, -8, -10 };
    int searchArray2[] = { 0, 2, 4, 6, 8 };
    for (int i = 0; i < 5; ++i)
    {
        if (binarySearch(array2, 0, 5, searchArray2[i]))
        {
            return false;
        }
    }

    int array3[] = { 1, 2, 3, 4, 5};
    int searchArray3[] = { 0, 2, 4, 6, 8 };
    for (int i = 0; i < 5; ++i)
    {
        if (!binarySearch(array3, 0, 5, searchArray3[1]) || !binarySearch(array3, 0, 5, searchArray3[2]))
        {
            return false;
        }
    }

    return true;
}

void main()
{
    if (!testCorrectCase())
    {
        printf("Test failed\n");
        return;
    }

    printf("Input number of elements in array\n");
    int mainSize = -1;
    scanf_s("%d", &mainSize);

    if (mainSize < 1)
    {
        printf("An array must have at least one element\n");
        return;
    }

    printf("Input number of random elements\n");
    int secondarySize = -1;
    scanf_s("%d", &secondarySize);

    if (secondarySize < 1)
    {
        printf("An array must have at least one element\n");
        return;
    }

    int* array = calloc(mainSize, sizeof(int));
    srand((unsigned int)time(NULL));

    for (int i = 0; i < mainSize; ++i)
    {
        array[i] = rand() % 100;
    }

    int* searchArray = calloc(secondarySize, sizeof(int));

    for (int i = 0; i < mainSize; ++i)
    {
        searchArray[i] = rand() % 100;
    }

    // sort the secondary array
    int quickSortStart = smallNumberPartition(searchArray, secondarySize);
    insertionSort(searchArray, quickSortStart + 1);
    quickSort(searchArray, quickSortStart, secondarySize - 1);

    // finding an element in the main array
    for (int i = 0; i < secondarySize; ++i)
    {
        if (binarySearch(array, 0, mainSize, searchArray[i]))
        {
            printf("%d is in the main array\n", searchArray[i]);
        }
        else
        {
            printf("%d is not in the main array\n", searchArray[i]);
        }
    }

    return;
}