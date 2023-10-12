#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* file;
    char* filename = "sample.txt";
    char* mode = "r";

    if (fopen_s(&file, filename, mode) != 0)
    {
        printf("Error opening file.\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* fileContents = (char*)calloc(fileSize, fileSize * sizeof(char));

    fread(fileContents, sizeof(char), fileSize, file);

    fclose(file);
    
    int* array = calloc(fileSize, fileSize * sizeof(int));

    for (int i = 0; fileContents[i] != '\0'; i++)
    {
        array[i] = (fileContents[i] - '0');
    }
    
    printf("%d\n", mostFrequentElement(array, fileSize));

    free(fileContents);

    return 0;
}