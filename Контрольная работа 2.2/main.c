#include <stdio.h>

#include "graph.h"

int maint()
{
	Graph* graph = createGraph();
	addToTable(graph, 1, 2);
}