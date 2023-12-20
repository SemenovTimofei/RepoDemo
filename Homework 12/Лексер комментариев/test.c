#include "test.h"

bool testing()
{
    FILE* file1 = NULL;
    fopen_s(&file1, "test1.txt", "r");
    if (file1 == NULL)
    {
        fclose(file1);
        return false;
    }
    if (strcmp(getComment(file1), "/*four ->*<- // *** five*/") != 0)
    {
        fclose(file1);
        return false;
    }
    fclose(file1);

    FILE* file2 = NULL;
    fopen_s(&file2, "test2.txt", "r");
    if (file2 == NULL)
    {
        fclose(file2);
        return false;
    }
    if (strcmp(getComment(file2), "/*this\nis\nan\nexample\nusing\nline\nbreaks\n*//*multiple comments*/") != 0)
    {
        fclose(file2);
        return false;
    }
    fclose(file2);

    return true;
}