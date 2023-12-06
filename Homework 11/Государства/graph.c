#include <stdlib.h>

#include "graph.h"
#include "list.h"

typedef struct Graph
{
    List** adjacency;
    List** states;
    size_t amountOfCapitals;
    size_t amountOfCities;
    int* occupation;
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

void freeGraph(Graph** const graph)
{
    freeTable(&(*graph)->adjacency, (*graph)->amountOfCities);
    freeTable(&(*graph)->states, (*graph)->amountOfCapitals);
    free((*graph)->occupation);
    free(*graph);
    *graph = NULL;
}

int createAdjacencyTable(Graph* const graph, FILE* const stream)
{
    graph->amountOfCities = 0;
    size_t numberOfRoads = 0;
    fscanf_s(stream, "%d", &graph->amountOfCities);
    fscanf_s(stream, "%d", &numberOfRoads);

    graph->adjacency = (List**)malloc(graph->amountOfCities * sizeof(List*));
    int errorOccured = initialiseTable(&graph->adjacency, graph->amountOfCities);
    if (errorOccured)
    {
        return 1;
    }
    for (size_t i = 0; i < numberOfRoads; ++i)
    {
        int city1 = 0, city2 = 0;
        size_t distance = 0;
        fscanf_s(stream, "%d %d %d", &city1, &city2, &distance);

        if (push(graph->adjacency[city1 - 1], city2, distance) != 0 || push(graph->adjacency[city2 - 1], city1, distance) != 0)
        {
            return 1;
        }
    }
    return 0;
}

int assignCapitals(Graph* const graph, FILE* const stream)
{
    graph->amountOfCapitals = 0;
    fscanf_s(stream, "%d", &graph->amountOfCapitals);

    graph->states = (List**)malloc(graph->amountOfCapitals * sizeof(List*));
    graph->occupation = (int*)calloc(graph->amountOfCities, sizeof(int));
    int errorOccured = initialiseTable(&graph->states, graph->amountOfCapitals) || graph->occupation == NULL;
    if (errorOccured)
    {
        return 1;
    }
    for (size_t i = 0; i < graph->amountOfCapitals; ++i)
    {
        int capital = 0;
        fscanf_s(stream, "%d", &capital);
        if (push(graph->states[i], capital, 0) != 0)
        {
            return 1;
        }
        graph->occupation[capital - 1] = i + 1;
    }
    return 0;
}

int createGraph(Graph** const graph, const char* const fileName)
{
    FILE* file = NULL;
    int errorCode = fopen_s(&file, fileName, "r");
    if (errorCode != 0)
    {
        return errorCode;
    }
    *graph = (Graph*)malloc(sizeof(Graph));
    if (*graph == NULL)
    {
        fclose(file);
        return 1;
    }
    if (createAdjacencyTable(*graph, file) != 0 || assignCapitals(*graph, file) != 0)
    {
        freeGraph(graph);
        fclose(file);
        return 1;
    }
    fclose(file);
    return 0;
}

int assignStates(Graph* const graph, const int amountOfStates, bool* const occupied)
{
    int minDistance = UINT_MAX;
    int closestCity = 0;
    List* state = graph->states[amountOfStates - 1];
    for (size_t i = 0; i < listSize(state); ++i)
    {
        List* neighbors = graph->adjacency[getCity(state, i) - 1];
        for (size_t j = 0; j < listSize(neighbors); ++j)
        {
            if (graph->occupation[getCity(neighbors, j) - 1] == 0)
            {
                size_t currentDistance = distance(neighbors, j);
                closestCity = currentDistance <= minDistance ? getCity(neighbors, j) : closestCity;
                minDistance = min(minDistance, currentDistance);
            }
        }
    }
    if (closestCity == 0)
    {
        *occupied = false;
        return 0;
    }
    graph->occupation[closestCity - 1] = amountOfStates;
    *occupied = true;
    return push(state, closestCity, 0);
}

void printStates(const Graph* const graph)
{
    for (size_t i = 0; i < graph->amountOfCapitals; ++i)
    {
        printf("State: %d\nCities: ", i + 1);
        printList(graph->states[i]);
        printf("\n\n");
    }
}

size_t amountOfCities(const Graph* const graph)
{
    return graph->amountOfCities;
}

size_t amountOfCapitals(const Graph* const graph)
{
    return graph->amountOfCapitals;
}

int checkStates(const Graph* const graph, const int* const states, const size_t* const sizeOfState, const size_t const amountOfStates)
{
    if (amountOfCapitals(graph) != amountOfStates)
    {
        return 0;
    }
    for (size_t i = 0; i < amountOfStates; ++i)
    {
        if (!arrayIsEqual(graph->states[i], states[i], sizeOfState[i]))
        {
            return 0;
        }
    }
    return 1;
}

int distributeCities(const Graph* const graph)
{
    if (amountOfCapitals(graph) == 0)
    {
        return 0;
    }
    size_t remaining = amountOfCities(graph) - amountOfCapitals(graph);
    int state = 1;
    while (remaining > 0)
    {
        bool occupied = false;
        int errorOccured = assignStates(graph, state, &occupied);
        if (errorOccured)
        {
            return 1;
        }
        if (occupied)
        {
            --remaining;
        }
        state = state % amountOfCapitals(graph) + 1;
    }
    return 0;
}