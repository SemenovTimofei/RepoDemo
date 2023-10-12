#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char* fileName = "sample.txt";
    char* readMode = "r";
    FILE* file = fopen_s(&file, fileName, readMode);

    if (fopen_s(&file, fileName, readMode) != 0)
    {
        printf("Error opening file\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    int fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* fileContents = (char*)calloc(fileSize, fileSize * sizeof(char));

    fread(fileContents, sizeof(char), fileSize, file);
    fclose(file);

    // подсчет количества элементов для создания списка
    int spaceCount = 1;

    for (int i = 0; i < fileSize; ++i)
    {
        if (fileContents[i] == ' ')
        {
            ++spaceCount;
        }
    }

    int* array = calloc(spaceCount, spaceCount * sizeof(int));
    int elementCount = 0;
    char* context;

    char* token = strtok_s(fileContents, " ", &context);

    while (token != NULL && elementCount < fileSize)
    {
        array[elementCount] = atoi(token);
        elementCount++;
        token = strtok_s(NULL, " ", &context);
    }

    printArray(array, elementCount);

    free(fileContents);
    return 0;
}