#include <stdio.h>

#include "list.h"

typedef struct Graph
{
    List** relation;
} Graph;

int initialiseTable()
{
    return (Graph*)calloc(1, sizeof(Graph));
}

void freeRelation(List*** relation)
{
    
}

int addToTable(Graph* graph)
{

}