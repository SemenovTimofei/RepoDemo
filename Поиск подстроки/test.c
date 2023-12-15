#include "search.h"
#include "test.h"

#define MAX_LENGTH 1000

bool testing()
{
    bool flag = true;

    FILE* file1 = NULL;
    fopen_s(&file1, "test1.txt", "r");
    if (file1 == NULL)
    {
        flag = false;
    }
    char string1[MAX_LENGTH] = { '\0' };
    if (fscanf_s(file1, "%s", string1, MAX_LENGTH) != 1)
    {
        flag = false;
    }
    if (find(string1, "abc") != -1)
    {
        flag = false;
    }
    fclose(file1);

    FILE* file2 = NULL;
    fopen_s(&file2, "test2.txt", "r");
    if (file2 == NULL)
    {
        flag = false;
    }
    char string2[MAX_LENGTH] = { '\0' };
    if (fscanf_s(file2, "%s", string2, MAX_LENGTH) != 1)
    {
        flag = false;
    }
    if (find(string2, "!d") != 44)
    {
        flag = false;
    }
    fclose(file2);

	return flag;
}