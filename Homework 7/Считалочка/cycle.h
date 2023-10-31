#pragma once

#include <stdbool.h>

// list structure
typedef struct List List;

// adds an element to the list
int push(List** head, int value);

// deletes the head element
int pop(List** head);

// moves head pointer to the next element
void moveHead(List** head);

// returns the position of the last soldier
int findSurvivor(const int size, const int step);

// test findSurvivor function
bool testing();