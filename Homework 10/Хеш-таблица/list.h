#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 50

typedef enum ErrorCode
{
    OK = 0,
    MemoryAllocationError = 1,
    NULLPointerError = 2,
} ErrorCode;

typedef struct ListElement ListElement;

typedef struct List List;

List* createList();

ErrorCode push(List* list, char* value, int frequency);

ErrorCode pop(List* list);

size_t getFrequency(const ListElement* const element);

size_t listLength(const List* const list);

ErrorCode changeElement(ListElement* const element, const size_t const frequency);

ErrorCode freeList(List* list);

ErrorCode printList(List* list);

ErrorCode printHead(List* list);

ListElement* findElement(const List* const list, const char* const value);

bool isPresent(const List* const list, const char* const value);