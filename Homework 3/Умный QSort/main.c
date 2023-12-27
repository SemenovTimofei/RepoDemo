#include "quickSort.h"
#include "test.h"

int main()
{
    if (!testing())
    {
        printf("Testing failed\n");
        return 1;
    }

    printf("Enter size of array: ");
    size_t size = 0;
    scanf_s("%zd", &size);
    if (size <= 0)
    {
        printf("Invalid array size\n");
        return 0;
    }

    int* array = createRandomArray(size);
    printf("The original array: \n");
    printArray(array, size);

    quickSort(array, 0, size - 1);
    printf("Sorted array: \n");
    printArray(array, size);

    free(array);
    return 0;
}