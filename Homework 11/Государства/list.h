#pragma once

#include <stdbool.h>
#include <stdio.h>

typedef struct ListElement ListElement;

typedef struct List List;

ListElement* head(List* const list);

List* createList();

void freeList(List** const list);

ListElement* createElement(const int const getCity, const size_t const distance);

int push(List* const list, const int getCity, const int const distance);

void setCurrent(List* const list);

ListElement* getElement(List* const list, const size_t index);

int getCity(List* const list, const size_t index);

size_t distance(List* const list, const size_t index);

size_t listSize(List* const list);

void printList(List* const list);

int arrayIsEqual(List* const list, const int* const array, const size_t length);