#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "list.h"

typedef struct ListElement ListElement;

typedef struct List List;

List* initializeList();

int push(List* list, char* word);

int freeList(List* list);

int printList(List* list);