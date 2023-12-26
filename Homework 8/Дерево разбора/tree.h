#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct Node Node;

typedef struct ParseTree ParseTree;

bool isOperation(char character);

Node* buildTree(FILE* file);

ParseTree* createParseTree(char fileName[]);

void printExpression(Node* root);