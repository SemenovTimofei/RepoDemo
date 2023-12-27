#pragma once

#include <stdlib.h>
#include <stdbool.h>

// list structure
typedef struct List List;

// adds an element to the list
size_t push(List** head, size_t value);

// deletes the head element
size_t pop(List** head);

// moves head pointer to the next element
void moveHead(List** head);