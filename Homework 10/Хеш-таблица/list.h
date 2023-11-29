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

ErrorCode push(List* list, char* value, int amount);

ErrorCode pop(List* list);

size_t getAmount(const ListElement* const element);

size_t listLength(const List* const list);

ErrorCode changeElement(ListElement* const element, const size_t const amount);

ErrorCode freeList(List* list);

ErrorCode printList(List* list);

ListElement* findElement(const List* const list, const char* const value);