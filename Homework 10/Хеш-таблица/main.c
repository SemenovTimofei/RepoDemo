#include "hash.h"

int main()
{
    HashTable* table = initializeTable();
    if (table == NULL)
    {
        return 1;
    }
    addToTable(table, "ababa");
    addToTable(table, "ababa");
    addToTable(table, "check");
    addToTable(table, "ababa");
    printTable(table);

    freeTable(&table);
    return 0; // load factor, collision etc
}