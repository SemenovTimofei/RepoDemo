#include "graph.h"

typedef struct Graph
{
    List** edge;
} Graph;

int createGraph()
{
    return (Graph*)calloc(1, sizeof(Graph));
}

int addToTable(Graph* graph, int vertex1, int vertex2)
{
    List* newEdge = createList();
    push(newEdge, vertex1);
    push(newEdge, vertex2);
    
    printList(newEdge);
}