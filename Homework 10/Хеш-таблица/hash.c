#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "hash.h"

typedef struct HashTable
{
    size_t size;
    size_t amount;
    List* items[HASH_TABLE_SIZE];
} HashTable;

size_t hash(const char* const value)
{
    size_t hash = 0;
    for (size_t i = 0; value[i] != '\0'; ++i)
    {
        hash = (value[i] + hash * 31) % HASH_TABLE_SIZE;
    }
    return hash;
}

HashTable* createTable()
{
    HashTable* table = calloc(1, sizeof(HashTable));
    table->amount = 0;
    table->size = HASH_TABLE_SIZE;
    return table;
}

int insert(HashTable* table, const char* const value)
{
    if (table == NULL)
    {
        return 1;
    }

    List* bucket = table->items[hash(value)];

    if (bucket == NULL)
    {
        table->items[hash(value)] = createList();
        push(table->items[hash(value)], value, 1);
        ++table->amount;
        return 0;
    }
    ListElement* entry = findElement(bucket, value);
    if (entry == NULL)
    {
        push(bucket, value, 1);
        ++table->amount;
    }
    else
    {
        changeElement(entry, getAmount(entry) + 1);
        push(bucket, value, getAmount(entry));
    }
    return 0;
}

float loadFactor(const HashTable* const table)
{
    if (table == NULL)
    {
        return 0;
    }
    return (float)table->amount / (float)table->size;
}

size_t maxLength(const HashTable* const table)
{
    if (table == NULL)
    {
        return 0;
    }
    size_t maxLength = 0;
    for (size_t i = 0; i < table->size; ++i)
    {
        if (table->items[i] != NULL && getAmount(table->items[i]) > maxLength)
        {
            maxLength = listLength(table->items[i]);
        }
    }
    return maxLength;
}

float averageLength(const HashTable* const table)
{
    if (table == NULL)
    {
        return 0;
    }

    size_t listAmount = 0;
    size_t listElementAmount = 0;
    for (size_t i = 0; i < table->size; ++i)
    {
        if (table->items[i] != NULL)
        {
            ++listAmount;
            listElementAmount += listLength(table->items[i]);
        }
    }
    return (float)listElementAmount / (float)listAmount;
}

void printTable(const HashTable* const table)
{
    if (table == NULL)
    {
        return;
    }
    for (size_t i = 0; i < table->size; ++i)
    {
        if (table->items[i] != NULL)
        {
            printf("%d idk\n", getAmount(table->items[i]));
        }
    }
}

void freeTable(HashTable** table)
{
    if (table == NULL)
    {
        return;
    }
    for (size_t i = 0; i < (*table)->size; ++i)
    {
        freeList(&(*table)->items[i]);
    }

    free(*table);
    *table = NULL; // necessary ???
}