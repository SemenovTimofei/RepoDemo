#pragma once

typedef enum ErrorCode
{
    OK = 0,
    MemoryAllocationError = 1,
    NULLPointerError = 2,
    ListIndexOutOfRange = 3
} ErrorCode;

typedef struct ListElement ListElement;

typedef struct List List;

List* createList();

ErrorCode push(List* list, char* charValue, int intValue);

ErrorCode getPop(List* list, char* charValue, int* intValue);

ErrorCode freeList(List* list);

ErrorCode printList(List* list);

size_t listSize(List* list);

ErrorCode deleteElement(List* list, size_t index);