#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

Node* push(Node* head, int key, int value);

Node* deleteAtIndex(Node* head, int key);

void printList(Node* head);

void freeList(Node* head);