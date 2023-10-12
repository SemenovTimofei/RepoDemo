#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* file;
    char* filename = "sample.txt";
    char* mode = "r";

    if (fopen_s(&file, filename, mode) != 0) {
        printf("Error opening file.\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* fileContents = (char*)calloc(fileSize, fileSize * sizeof(char));

    fread(fileContents, sizeof(char), fileSize, file);

    fclose(file);

    // Use the fileContents array as needed
    
    int array[11];

    for (int i = 0; fileContents[i] != '\0'; i++)
    {
        array[i] = (fileContents[i] - '0');
    }

    printArray(array, fileSize);

    //mostFrequentElement(fileContents, fileSize);

    free(fileContents);

    return 0;
}