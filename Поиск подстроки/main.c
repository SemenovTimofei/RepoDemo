#include "search.h"
#include "test.h"

#define MAX_LENGTH 1000

int main()
{
    if (!testing())
    {
        printf("Testing failed\n");
        return 1;
    }

    FILE* file = NULL;
    fopen_s(&file, "text.txt", "r");
    if (file == NULL)
    {
        printf("Error openning file\n");
        fclose(file);
        return 1;
    }

    char string[MAX_LENGTH] = { '\0' };
    if (fscanf_s(file, "%s", string, MAX_LENGTH) != 1)
    {
        printf("Error openning file\n");
        fclose(file);
        return 1;
    }

    printf("Enter substring: \n");
    char subString[MAX_LENGTH] = { '\0' };
    scanf_s("%s", &subString, MAX_LENGTH);

    int entryIndex = find(string, subString);
    if (entryIndex != -1)
    {
        printf("First entry of substring: %d\n", entryIndex);
    }
    else
    {
        printf("The substring is not present within the text\n");
    }
    
    fclose(file);
    return 0;
}