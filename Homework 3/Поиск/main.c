#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

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

bool binarySearch(int array[], int start, int end, int key)
{
    while (start <= end)
    {
        int middle = start + (end - start) / 2;
        if (array[middle] == key)
        {
            return true;
        }
        else if (array[middle] < key)
        {
            start = middle + 1;
        }
        else
        {
            end = middle - 1;
        }
        
    }
    return false;
}

bool testing()
{
    int* array = createRandomArray(50);
    quickSort(array, 0, 49);
    if (!isSorted(array, 50))
    {
        free(array);
        return false;
    }
    free(array);

    int searchArray[11] = { 0, 1, 2, 3, 4, 5, -5, -4, -3, -2, -1 };
    quickSort(searchArray, 0, 10);
    int notPresentElements[5] = { 10, 6, -6, 20, 9 };
    int presentElements[5] = { 0, 5, -3, 2, -4 };

    for (size_t i = 0; i < 5; ++i)
    {
        if (binarySearch(searchArray, 0, 10, notPresentElements[i]))
        {
            return false;
        }
        if (!binarySearch(searchArray, 0, 10, presentElements[i]))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    if (!testing())
    {
        printf("Testing failed\n");
        return 1;
    }

    printf("Enter array size: ");
    int n = 0;
    scanf_s("%d", &n);
    if (n <= 0)
    {
        printf("Invalid array size\n");
        return 1;
    }

    printf("Enter number of elements: ");
    size_t k = 0;
    scanf_s("%zd", &k);
    if (k <= 0)
    {
        printf("Invalid number of elements\n");
        return 1;
    }

    int* array = createRandomArray(n);
    quickSort(array, 0, n - 1);
    int* searchElements = createRandomArray(k); // i can't create an array that differs from the previous one

    for (size_t i = 0; i < k; ++i)
    {
        if (binarySearch(array, 0, n - 1, searchElements[i]))
        {
            printf("%d is present in the array\n", searchElements[i]);
        }
        else
        {
            printf("%d is not present in the array\n", searchElements[i]);
        }
    }

    free(array);
    free(searchElements);
    return 0;
}