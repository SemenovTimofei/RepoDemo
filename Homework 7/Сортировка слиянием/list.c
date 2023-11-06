#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "list.h"

#define MAX_NAME_LENGTH 30
#define MAX_PHONE_LENGTH 30

typedef struct Node
{
    char* name;
    char* phone;
    Node* next;
} Node;

ListErrorCode push(Node** list, const char* name, const char* phone)
{
    Node* temporary = malloc(sizeof(Node));
    if (temporary == NULL)
    {
        return listOutOfMemory;
    }

    size_t nameLength = strlen(name) + 1;
    temporary->name = malloc(nameLength);
    if (temporary->name == NULL)
    {
        return listOutOfMemory;
    }
    strcpy_s(temporary->name, nameLength, name);

    size_t phoneNumberLength = strlen(phone) + 1;
    temporary->phone = malloc(phoneNumberLength);
    if (temporary->phone == NULL)
    {
        return listOutOfMemory;
    }
    strcpy_s(temporary->phone, phoneNumberLength, phone);

    temporary->next = NULL;

    if (*list == NULL)
    {
        *list = temporary;
    }
    else
    {
        Node* head = *list;
        while (head->next != NULL)
        {
            head = head->next;
        }
        head->next = temporary;
    }

    return noErrors;
}

ListErrorCode loadData(Node** list, const char* filename)
{
    FILE* file = NULL;

    fopen_s(&file, filename, "r");
    if (file == NULL)
    {
        freeList(*list);
        return errorOpenningFile;
    }

    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    while (fscanf_s(file, "%s - %s", name, MAX_NAME_LENGTH, phone, MAX_PHONE_LENGTH) == 2)
    {
        push(list, name, phone);
    }

    fclose(file);
    return noErrors;
}

Node* getNextNode(Node* node, ListErrorCode* errorCode)
{
    if (node == NULL)
    {
        *errorCode = listIsEmpty;
        return NULL;
    }
    return node->next;
}

void printList(Node* list)
{
    Node* current = list;
    while (current != NULL)
    {
        printf("%s - %s\n", current->name, current->phone);
        current = current->next;
    }
}

ListErrorCode freeList(Node** list)
{
    if (*list == NULL)
    {
        return listIsEmpty;
    }

    while ((*list) != NULL)
    {
        Node* trash = *list;
        *list = (*list)->next;
        free(trash->name);
        free(trash->phone);
        free(trash);
    }

    return noErrors;
}

ListErrorCode changeNextNode(Node** node, Node* changeValue)
{
    (*node)->next = changeValue;
}

char* currentValue(Node* node, int valueType)
{
    if (valueType == 1)
    {
        return node->name;
    }

    return node->phone;
}