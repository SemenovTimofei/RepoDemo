#pragma once

#include "list.h"

#define MAX_NAME_LENGTH 30
#define MAX_PHONE_LENGTH 30

typedef enum
{
    noErrors,
    errorOpenningFile,
    listIsEmpty,
    listOutOfMemory,
    inputError
} ListErrorCode;

// Node structure
typedef struct Node Node;

// adds a name and a phone number at the end of the list
ListErrorCode push(Node** list, const char* name, const char* phone);

// loads text from file
ListErrorCode loadData(Node** list, const char* fileName);

// returns next node
Node* getNextNode(Node* node, ListErrorCode* errorCode);

// prints all recorded names and phone numbers
void printList(Node* list);

// frees the list
ListErrorCode freeList(Node** list);

// changes the value of next node
ListErrorCode changeNextNode(Node** node, Node* changeValue);

// returns current node value depending on the type
char* currentValue(Node* node, int valueType);