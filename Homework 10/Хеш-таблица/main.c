#include <stdio.h>

#include "list.h"
#include "hash.h"

#define MAX_LENGTH 50

int main()
{
    FILE* file = NULL;
    fopen_s(&file, "text.txt", "r");
    if (file == NULL)
    {
        printf("Error openning file\n");
        return 1;
    }

    HashTable* table = createTable();
    char word[MAX_LENGTH] = { 0 };
    while (fscanf_s(file, "%s", word, MAX_LENGTH) == 1)
    {
        if (insert(table, word) == 1)
        {
            printf("Error writing to hash table\n");
            return 2;
        }
    }

    printTable(table);
    printf("Load factor: %f\nMax word frequency: %d\nAverage word frequency: %f\n", loadFactor(table), maxLength(table), averageLength(table));
    freeTable(&table);
}