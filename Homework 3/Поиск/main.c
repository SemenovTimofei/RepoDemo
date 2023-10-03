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

int binarySearch(int array[], int start, int end, int value)
{
    if (start <= end)
    {
        int middle = start + (end - start) / 2;

        if (array[middle] == value)
            return true;

        if (array[middle] > value)
            return binarySearch(array, start, middle - 1, value);

        return binarySearch(array, middle + 1, end, value);
    }

    return false;
}

void main()
{
	printf("Input number of elements in array\n");
	int n = -1;
	scanf_s("%d", &n);

    if (n < 1)
    {
        printf("An array must have at least one element\n");
        return;
    }

	printf("Input number of random elements\n");
	int k = -1;
	scanf_s("%d", &k);

    if (k < 1)
    {
        printf("An array must have at least one element\n");
        return;
    }

	int* array = (int*)calloc(n, sizeof(int));
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; ++i)
	{
		array[i] = rand() % 100;
	}

	int* searchArray = (int*)calloc(k, sizeof(int));

	for (int i = 0; i < n; ++i)
	{
		searchArray[i] = rand() % 100;
	}

    // sort the main array
    int quickSortStart = smallNumberPartition(array, n);
    insertionSort(array, quickSortStart + 1);
    quickSort(array, quickSortStart, n - 1);

    // sort the secondary array
    quickSortStart = smallNumberPartition(searchArray, k);
    insertionSort(searchArray, quickSortStart + 1);
    quickSort(searchArray, quickSortStart, k - 1);

    // finding an element in the main array
    for (int i = 0; i < k; ++i)
    {
        if (binarySearch(array, 0, n, searchArray[i]))
        {
            printf("%d is in the main array\n", searchArray[i]);
        }
        else
        {
            printf("%d is not in the main array\n", searchArray[i]);
        }
    }

    free(array);
    free(searchArray);
}