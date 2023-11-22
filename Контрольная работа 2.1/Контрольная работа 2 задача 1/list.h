#pragma once

#include <stdbool.h>

// list structure
typedef struct List List;

// adds an element to the list
int push(List** head, int value);

// deletes the head element
int pop(List** head);

// deletes odd elements within a list
void deleteOddElements(List** head);

// returns a value of an element at a given index
List* getElement(List* head, size_t index);

// deletes an element at a given index
int deleteElement(List** head, size_t index);

// deletes the whole list
void deleteList(List** head);

// prints out all list values
void printList(const List* head);

// testing list operations
bool testing();