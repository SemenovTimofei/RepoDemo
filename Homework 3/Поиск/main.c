#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

int* createRandomArray(size_t size)
{
    int* array = (int*)calloc(size, sizeof(int));
    if (array == NULL)
    {
        return NULL;
    }
    srand(time(NULL));
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

int main()
{


    printf("Enter array size: ");
    size_t n = 0;
    scanf_s("%zd", &n);
    if (n <= 0)
    {
        printf("Invalid array size\n");
        return 1;
    }

    printf("Enter number of elements: ");
    size_t k = 0;
    scanf_s("%zd", &k);
    if (n <= 0)
    {
        printf("Invalid number\n");
        return 1;
    }


}