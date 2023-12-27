#include "mostCommonElement.h"
#include "test.h"

int main()
{
    int array[] = { 123, 321, 335, 5, 66, 7, 6, 66, 77, 5, 444, 44, 44, 44, 90, 321, 3232 };
    size_t length = sizeof(array) / sizeof(array[0]);

    printf("The given array: \n");
    printArray(array, length);

    printf("The most common element: %d\n", findMostCommonElement(array, length));
}