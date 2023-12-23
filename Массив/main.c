#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10

void flipArray(int array[], size_t start, size_t end)
{
    while (start < end)
    {
        int temporary = array[start];
        array[start] = array[end];
        array[end] = temporary;
        ++start;
        --end;
    }
}

void printArray(int array[], size_t length)
{
    for (size_t i = 0; i < length; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

bool compareArrays(int firstArray[], int secondArray[], size_t length)
{
    for (size_t i = 0; i < length; ++i)
    {
        if (firstArray[i] != secondArray[i])
        {
            return false;
        }
    }
    return true;
}
bool testing()
{
    size_t segmentLength = 4;
    int array[MAX_SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
    flipArray(array, 0, segmentLength - 1);
    int firstCheck[MAX_SIZE] = {4, 3, 2, 1, 5, 6, 7, 8, 9, 0 };
    if (!compareArrays(array, firstCheck, MAX_SIZE))
    {
        return false;
    }

    flipArray(array, segmentLength, MAX_SIZE - 1);
    int secondCheck[MAX_SIZE] = { 4, 3, 2, 1, 0, 9, 8, 7, 6, 5 };
    if (!compareArrays(array, secondCheck, MAX_SIZE))
    {
        return false;
    }

    flipArray(array, 0, MAX_SIZE - 1);
    int thirdCheck[MAX_SIZE] = { 5, 6, 7, 8, 9, 0, 1, 2, 3, 4 };
    if (!compareArrays(array, thirdCheck, MAX_SIZE))
    {
        return false;
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

    int array[MAX_SIZE] = { 0 };
    printf("Enter %d numbers\n", MAX_SIZE);
    for (size_t i = 0; i < MAX_SIZE; ++i)
    {
        printf("%zd. ", i + 1);
        scanf_s("%d", &array[i]);
    }

    printf("Enter first segment length (less than %d): ", MAX_SIZE);
    size_t segmentLength = 0;
    scanf_s("%zd", &segmentLength);

    printf("The original array: \n");
    printArray(array, MAX_SIZE);

    flipArray(array, 0, segmentLength - 1);
    flipArray(array, segmentLength, MAX_SIZE - 1);
    flipArray(array, 0, MAX_SIZE - 1);

    printf("The reversed array: \n");
    printArray(array, MAX_SIZE);
    return 0;
}