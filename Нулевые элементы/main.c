#include <stdio.h>
#include <stdbool.h>

size_t countNullElements(int array[], size_t size)
{
    size_t nullElementAmount = 0;
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] == 0)
        {
            ++nullElementAmount;
        }
    }

    return nullElementAmount;
}

bool testing()
{
    int array1[] = { 0, 1, 2, 3, 0 };
    size_t size1 = sizeof(array1) / sizeof(int);
    if (countNullElements(array1, size1) != 2)
    {
        return false;
    }

    int array2[] = { 1, 2, 3, 4, 5 };
    size_t size2 = sizeof(size2) / sizeof(int);
    if (countNullElements(array2, size2) != 0)
    {
        return false;
    }

    int array3[] = { 0, 0, 0, 0, 0 };
    size_t size3 = sizeof(array2) / sizeof(int);
    if (countNullElements(array3, size3) != 5)
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

    int array[] = { 1, 2, 3, 4, 5, 0, 0 };
    size_t size = sizeof(array) / sizeof(int);

    printf("Amount of null elements in the array: %d\n", countNullElements(array, size));
    return 0;
}