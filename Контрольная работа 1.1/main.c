#include <stdio.h>
#include <stdbool.h>

void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");
}

int numberSum(int number)
{
    int sum = 0;

    if (number < 0)
    {
        number = -number;
    }

    while (number > 0)
    {
        sum = sum + number % 10;
        number = number / 10;
    }

    return sum;
}

int findMaxSum(int array[], int size, int* result)
{
    int maxSum = 0;
    int maxNumber = calloc(size, sizeof(array));

    for (int i = 0; i < size; ++i)
    {
        if (numberSum(array[i]) > maxSum)
        {
            maxSum = numberSum(array[i]);
        }
    }

    int count = 0;
    for (int i = 0; i < size; ++i)
    {
        if (numberSum(array[i]) == maxSum)
        {
            result[count] = array[i];
            ++count;
        }
    }

    return count;
}

bool testing()
{
    int testArray1[3][5] = {{-4, -3, -2, -1, 0}, {5, 4, 3, 2, 1}, {10, 50, 44, 55, 123}};
    int answers[3] = { -4, 5, 55 };
    for (int i = 0; i < 3; ++i)
    {
        int size = sizeof(testArray1[i]) / sizeof(int);
        int result = 0;
        int count = findMaxSum(testArray1[i], size, &result);


        if (result != answers[i])
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

	int array[] = { 1, 2, 5, 10, 15, 55 , 46, 56 , 0, -57 };
    int size = sizeof(array) / sizeof(int);
    int* result = calloc(size, sizeof(array));

    int count = findMaxSum(array, size, &result);

    printf("The elements with the largest digit sum: ");
    printArray(&result, count);

    return 0;
}