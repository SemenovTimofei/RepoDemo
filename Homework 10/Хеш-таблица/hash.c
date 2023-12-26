#include "hash.h"

typedef struct HashTable
{
    size_t tableSize;
    size_t numberOfElements;
    List** items;
} HashTable;

size_t hash(char word[])
{
    size_t hash = 0;
    for (size_t i = 0; word[i] != '\0'; ++i)
    {
        hash = (hash * MODULUS + word[i]) % HASH_TABLE_SIZE;
    }
    return hash;
}

HashTable* initializeTable()
{
    HashTable* table = (HashTable*)calloc(1, sizeof(HashTable));
    if (table == NULL)
    {
        return NULL;
    }
    table->tableSize = HASH_TABLE_SIZE;
    table->numberOfElements = 0;
    
    table->items = (List**)calloc(HASH_TABLE_SIZE, sizeof(List*));
    if (table->items == NULL)
    {
        free(table);
        return NULL;
    }

    for (size_t i = 0; i < HASH_TABLE_SIZE; ++i)
    {
        table->items[i] = initializeList();
    }

    return table;
}

int addToTable(HashTable* table, char word[])
{
    if (table == NULL)
    {
        return 1;
    }
    size_t currentHash = hash(word);
    
    if (table->items[currentHash] == NULL)
    {
        table->items[currentHash] = initializeList();
        if (table->items[currentHash] == NULL)
        {
            return 1;
        }
    }

    push(table->items[currentHash], word);
    return 0;
}

void printTable(HashTable* table)
{
    for (size_t i = 0; i < HASH_TABLE_SIZE; ++i)
    {
        if (getLength(table->items[i]) > 0)
        {
            printList(table->items[i]);
        }
    }
}

void freeTable(HashTable** table)
{
    for (size_t i = 0; i < (*table)->numberOfElements; ++i)
    {
        if ((*table)->items[i] != NULL)
        {
            freeList(&((*table)->items[i]));
        }
    }
    free((*table)->items);
    free(*table);
}

float loadFactor(HashTable* table)
{
    if (table == NULL)
    {
        return 0;
    }

    size_t totalAmount = 0;
    for (size_t i = 0; i < HASH_TABLE_SIZE; ++i)
    {
        if (getLength(table->items[i]) > 0)
        {
            ++totalAmount;
        }
    }
    return (float)totalAmount / (float)HASH_TABLE_SIZE;
}

size_t maxListLength(HashTable* table)
{
    if (table == NULL)
    {
        return 0;
    }
    size_t maxLength = 0;
    for (size_t i = 0; i < HASH_TABLE_SIZE; ++i)
    {
        if (table->items[i] != NULL)
        {
            maxLength = max(maxLength, getLength(table->items[i]));
        }
    }
    return maxLength;
}

float averageListLength(HashTable* table)
{
    if (table == NULL)
    {
        return 0;
    }
    size_t totalListLength = 0;
    size_t listCount = 0;
    for (size_t i = 0; i < HASH_TABLE_SIZE; ++i)
    {
        if (getLength(table->items[i]) > 0)
        {
            totalListLength = totalListLength + getLength(table->items[i]);
            ++listCount;
        }
    }
    return (float)totalListLength / (float)listCount;
}