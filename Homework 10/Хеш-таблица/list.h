#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "list.h"

typedef struct ListElement ListElement;

typedef struct List List;

List* initializeList();

ListElement* initializeListElement();

int push(List* list, char* word, size_t frequency);

int pop(List* list);

int freeList(List* list);

int changeFrequency(ListElement* element, size_t frequency);

int printList(List* list);