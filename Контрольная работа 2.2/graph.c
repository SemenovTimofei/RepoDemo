#include <stdio.h>

#include "list.h"

typedef struct Graph
{
	List** relation;
    size_t amountOfVertices;
} Graph;

int initialiseTable(List*** const table, const size_t length)
{
    if (*table == NULL)
    {
        return 1;
    }
    for (size_t i = 0; i < length; ++i)
    {
        (*table)[i] = createList();
        if ((*table)[i] == NULL)
        {
            return 1;
        }
    }
    return 0;
}

void freeTable(List*** const table, const size_t length)
{
    for (size_t i = 0; i < length; ++i)
    {
        freeList(&(*table)[i]);
    }
    free(*table);
    *table = NULL;
}

