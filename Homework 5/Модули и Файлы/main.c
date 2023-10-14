#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Rus");

    if (!fileTesting())
    {
        printf("Testing failed\n");
        return 1;
    }

    char* fileName = "sample.txt";
    char* readMode = "r";
    const int elementCount = countElementsInFile(fileName, readMode);

    if (elementCount == -1)
    {
        printf("Error opening file\n");
        return 1;
    }

    if (elementCount == -2)
    {
        printf("File is empty\n");
        return 1;
    }

    int* array = calloc(elementCount, elementCount * sizeof(int));

    fileToArray(fileName, readMode, array);

    printf("Самый частый элемент в файле %s это %d", fileName, mostFrequentElement(array, elementCount));

    return 0;
}