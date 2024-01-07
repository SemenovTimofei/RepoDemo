#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ARRAY_SIZE 100000

void countingSort(int array[], size_t size)
{
    int maxElement = array[0];
    for (size_t i = 1; i < size; ++i)
    {
        maxElement = max(maxElement, array[i]);
    }

    int* count = (int*)calloc(maxElement + 1, sizeof(int));
    if (count == NULL)
    {
        return;
    }
    
    for (size_t i = 0; i < size; ++i)
    {
        ++count[array[i]];
    }

    size_t index = 0;
    for (int i = 0; i <= maxElement; ++i)
    {
        while (count[i] > 0)
        {
            array[index] = i;
            ++index;
            --count[i];
        }
    }

    free(count);
}

void bubbleSort(int array[], size_t size)
{
    for (size_t i = 0; i < size - 1; ++i)
    {
        bool swappedAtLeastOnce = false;

        for (size_t j = 0; j < size - i - 1; ++j)
        {
            if (array[j] > array[j + 1])
            {
                int temporary = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temporary;
                swappedAtLeastOnce = true;
            }
        }

        if (swappedAtLeastOnce == false)
        {
            break;
        }
    }
}

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

int main()
{
    int* firstArray = createRandomArray(ARRAY_SIZE);
    int* secondArray = createRandomArray(ARRAY_SIZE);

    clock_t startTime = clock();
    countingSort(firstArray, ARRAY_SIZE);
    clock_t stopTime = clock();
    printf("Counting sort runtime: %f seconds\n", (float)(stopTime - startTime) / CLOCKS_PER_SEC);

    startTime = clock();
    bubbleSort(secondArray, ARRAY_SIZE);
    stopTime = clock();
    printf("Bubble sort runtime: %f seconds\n", (float)(stopTime - startTime) / CLOCKS_PER_SEC);

    free(firstArray);
    free(secondArray);
    return 0;
}