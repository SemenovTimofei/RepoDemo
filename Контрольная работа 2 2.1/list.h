#pragma once

#include <stdio.h>

typedef enum ErrorCode
{
    OK = 0,
    MemoryAllocationError = 1,
    NULLPointerError = 2,
} ErrorCode;

typedef struct ListElement ListElement;

typedef struct List List;

ErrorCode push(List* list, int value);

ErrorCode pop(List* list);

ErrorCode freeList(List* list);

ErrorCode printList(List* list);