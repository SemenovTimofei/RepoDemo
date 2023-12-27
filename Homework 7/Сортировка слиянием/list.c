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
    Node* temporary = (Node*)calloc(1, sizeof(Node));
    if (temporary == NULL)
    {
        free(temporary);
        return listOutOfMemory;
    }

    size_t nameLength = strlen(name) + 1;
    temporary->name = calloc(nameLength, sizeof(char));
    if (temporary->name == NULL)
    {
        free(temporary->name);
        free(temporary);
        return listOutOfMemory;
    }
    strcpy_s(temporary->name, nameLength, name);

    size_t phoneNumberLength = strlen(phone) + 1;
    temporary->phone = calloc(phoneNumberLength, sizeof(char));
    if (temporary->phone == NULL)
    {
        free(temporary->phone);
        free(temporary->name);
        free(temporary);
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

ListErrorCode loadData(Node** list, const char* fileName)
{
    FILE* file = NULL;

    fopen_s(&file, fileName, "r");
    if (file == NULL)
    {
        freeList(*list);
        return errorOpenningFile;
    }

    char name[MAX_NAME_LENGTH] = { '\0' };
    char phone[MAX_PHONE_LENGTH] = { '\0' };
    while (fscanf_s(file, "%s - %s", name, MAX_NAME_LENGTH, phone, MAX_PHONE_LENGTH) == 2)
    {
        if (push(list, name, phone) != noErrors)
        {
            fclose(file);
            return listOutOfMemory;
        }
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

ListErrorCode changeNextNode(Node** node, Node* changeValue)
{
    (*node)->next = changeValue;
}

char* currentValue(Node* node, int valueType)
{
    return valueType == 1 ? node->name : node->phone;
}