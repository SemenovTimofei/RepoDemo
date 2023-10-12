#pragma once

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

int mostFrequentElement(int array[], int size)
{
    if (size < 1)
    {
        printf("An array must have at least one element\n");
        return -1;
    }

    // sorting the array
    int quickSortStart = smallNumberPartition(array, size);
    insertionSort(array, quickSortStart + 1);
    quickSort(array, quickSortStart, size - 1);

    // finding the most frequent array element
    int maxCount = 1;
    int result = array[0];
    int currentCount = 1;

    for (int i = 1; i < size; ++i)
    {
        if (array[i] == array[i - 1])
        {
            ++currentCount;
        }
        else
        {
            currentCount = 1;
        }

        if (currentCount > maxCount)
        {
            maxCount = currentCount;
            result = array[i - 1];
        }
    }

    return result;
}

bool testCorrectCase()
{
    int array1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 9 };
    int size1 = sizeof(array1) / sizeof(array1[0]);
    int result1 = mostFrequentElement(array1, size1);

    if (result1 != 9)
    {
        return false;
    }

    int array2[] = { -9, -8, -7, -6, -5, -4, -3, -2, -1, -1, 0 };
    int size2 = sizeof(array2) / sizeof(array2[0]);
    int result2 = mostFrequentElement(array2, size2);

    if (result2 != -1)
    {
        return false;
    }

    int array3[] = { 5, 5, 5, 5, 5 };
    int size3 = sizeof(array3) / sizeof(array3[0]);
    int result3 = mostFrequentElement(array3, size3);

    if (result3 != 5)
    {
        return false;
    }

    return true;
}

int readFile(char fileName, char readMode)
{

}