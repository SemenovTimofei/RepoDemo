#include "list.h"

typedef struct Node
{
    int key;
    int value;
    Node* next;
} Node;

Node* push(Node* head, int key, int value)
{
    Node* newElement = (Node*)calloc(1, sizeof(Node));
    newElement->key = key;
    newElement->value = value;

    if (head == NULL || key < head->key)
    {
        newElement->next = head;
        return newElement;
    }

    Node* current = head;
    while (current->next != NULL && current->next->key < key)
    {
        current = current->next;
    }

    newElement->next = current->next;
    current->next = newElement;
    return head;
}

Node* deleteAtIndex(Node* head, int key)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->key == key)
    {
        Node* newElement = head->next;
        free(head);
        return newElement;
    }
    Node* current = head;
    while (current->next != NULL && current->next->key != key)
    {
        current = current->next;
    }
    if (current->next != NULL)
    {
        Node* trash = current->next;
        current->next = current->next->next;
        free(trash);
    }
    return head;
}

void printList(Node* head)
{
    while (head != NULL)
    {
        printf("%d %d -> ", head->key, head->value);
        head = head->next;
    }
    printf("\n");
}

void freeList(Node* head)
{
    while (head != NULL)
    {
        Node* trash = head;
        head = head->next;
        free(trash);
    }
}