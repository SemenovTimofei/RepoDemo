#include <stdbool.h>

#include "hash.h"
#include "test.h"

bool testing()
{
    List* list = createList();

    const char value[5][2] = { "1", "2", "3", "4", "5" };
    for (size_t i = 0; i < 5; ++i)
    {
        if (push(list, value[i], 1) != OK)
        {
            return false;
        }
    }
    
    for (size_t i = 0; i < 2; ++i)
    {
        if (pop(list) != OK)
        {
            return false;
        }
    }
    
    if (!isPresent(list, "1") || !isPresent(list, "2") || !isPresent(list, "3"))
    {
        return false;
    }
    if (isPresent(list, "4") || isPresent(list, "5"))
    {
        return false;
    }

    freeList(list);

    FILE* file = NULL;
    fopen_s(&file, "test.txt", "r");
    if (file == NULL)
    {
        return false;
    }

    HashTable* table = createTable();
    char word[MAX_LENGTH] = { 0 };
    while (fscanf_s(file, "%s", word, MAX_LENGTH) == 1)
    {
        if (insert(table, word) == 1)
        {
            return false;
        }
    }

    if (maxLength(table) != 5)
    {
        return false;
    }
    if (averageLength(table) != 3)
    {
        return false;
    }

    return true;
}