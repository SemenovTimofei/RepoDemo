#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node Node;

typedef struct Tree Tree;

Node* createNode(int value);

bool isOperation(char character);

void freeNodes(Node* node);

Node* addNodes(FILE* file);

int createTree(Tree** tree, char fileName[]);

void printNodes(Node* node);

void printTree(Tree* tree);