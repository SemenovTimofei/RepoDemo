#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node Node;

Node* push(Node* head, int key, int value);

Node* deleteByKey(Node* head, int key);

void printList(Node* head);

void freeList(Node* head);

bool isEmpty(Node* head);

int getHeadValue(Node* head);