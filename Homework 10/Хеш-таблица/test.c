#include "test.h"

bool testing()
{
    FILE* file = NULL;
    fopen_s(&file, "test.txt", "r");
    if (file == NULL)
    {
        return false;
    }

    HashTable* table = initializeTable();
    if (table == NULL)
    {
        return false;
    }

    char word[EXPRESSION_SIZE] = { 0 };
    while (fscanf_s(file, "%s", word, EXPRESSION_SIZE) == 1)
    {
        if (addToTable(table, word) != 0)
        {
            return false;
        }
    }

    if (loadFactor(table) != (float)5 / HASH_TABLE_SIZE)
    {
        return false;
    }
    if (maxListLength(table) != 5)
    {
        return false;
    }
    if (averageListLength(table) != (float)3)
    {
        return false;
    }

    return true;
}