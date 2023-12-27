#include "hash.h"
#include "test.h"

int main()
{
    /*
    if (!testing())
    {
        printf("Testing failed\n");
        //return 1;
    }
    */

    FILE* file = NULL;
    fopen_s(&file, "text.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    HashTable* table = initializeTable();
    if (table == NULL)
    {
        return 1;
    }

    char word[EXPRESSION_SIZE] = { 0 };
    while (fscanf_s(file, "%s", word, EXPRESSION_SIZE) == 1)
    {
        if (addToTable(table, word) != 0)
        {
            printf("Error writing to hash table\n");
            return 1;
        }
    }
    //printTable(table);

    printf("Load factor: %f\n", loadFactor(table));
    printf("Max list length: %zd\n", maxListLength(table));
    printf("Average list length: %f\n", averageListLength(table));

    List* list = initializeList();
    push(list, "egor");
    push(list, "ddas");
    printList(list);
    printf("%s", listTop(list));

    freeTable(&table);
    return 0;
}