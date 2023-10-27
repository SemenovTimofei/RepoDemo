#include <stdio.h>

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

int main()
{
	int array[] = { 1, 2, 5, 10, 15, 55 , 46, 56 , 0, -57 };
    int size = sizeof(array) / sizeof(int);
    
    int maxSum = 0;
    int maxNumber = calloc(size, sizeof(array));

    for (int i = 0; i < size; ++i)
    {
        if (numberSum(array[i]) > maxSum)
        {
            maxSum = numberSum(array[i]);
        }
    }

    printf("The elements with the largest digit sum: ");
    for (int i = 0; i < size; ++i)
    {
        if (numberSum(array[i]) == maxSum)
        {
            printf("%d ", array[i]);
        }
    }
}