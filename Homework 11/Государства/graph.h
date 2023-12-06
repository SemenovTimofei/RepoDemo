#pragma once

#include <stdbool.h>
#include <stdio.h>

typedef struct Graph Graph;

int createGraph(Graph** const graph, const char* const fileName);

void freeGraph(Graph** const graph);

int assignStates(Graph* const graph, const int amountOfStates, bool* const occupied);

void printStates(const Graph* const graph);

size_t amountOfCities(const Graph* const graph);

size_t amountOfCapitals(const Graph* const graph);

int checkStates(const Graph* const graph, const int* const states, const size_t* const sizeOfState, const size_t amountOfStates);

int distributeCities(Graph* const graph);