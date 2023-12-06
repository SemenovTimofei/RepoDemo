#include <stdio.h>

#include "graph.h"

int main()
{
    Graph* graph = NULL;
    int errorCode = createGraph(&graph, "text.txt");
    if (errorCode != 0)
    {
        printf(errorCode == 2 ? "Error openning file\n" : "An error has occured\n");
        return errorCode;
    }

    if (distributeCities(graph) != 0)
    {
        freeGraph(&graph);
        return 1;
    }

    printStates(graph);

    freeGraph(&graph);
    return 0;
}
