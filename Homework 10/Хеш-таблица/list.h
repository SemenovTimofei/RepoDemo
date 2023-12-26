#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node Node;

Node* push(Node* head, int key, int value);

Node* deleteByKey(Node* head, int key);

void printList(Node* head);

void freeList(Node* head);

bool isEmpty(Node* head);

char getHeadValue(Node* head);