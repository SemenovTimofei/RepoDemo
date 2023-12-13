#pragma once

#include <stdbool.h>
#include <stdio.h>

// list structure
typedef struct List List;

// adds an element to the list
int enqueue(List** head, int value, int key);

// deletes the head element
int dequeue(List** head);

// returns a key of an element at a given index
List* getElement(List* head, size_t index);

// deletes an element at a given index
int deleteElement(List** head, size_t index);

// deletes the whole list
void deleteList(List** head);

// prints out all list values
void printList(const List* head);