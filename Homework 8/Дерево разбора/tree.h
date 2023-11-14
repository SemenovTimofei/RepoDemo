#pragma once

#include <stdbool.h>

#define MAX_EXPRESSION_LENGTH 1000

typedef struct Node Node;

typedef struct ParseTree ParseTree;

// returns Parse Tree
ParseTree* createParseTree();

// returns true or false whether the tree is empty
bool isEmpty(ParseTree* tree);

// returns true or false whether the node is a leaf
bool isLeaf(Node* node);

// returns true or false whether the character is an operation
bool isOperation(char symbol);

// returns number at a certain position
int getNumber(char* expression, int* position);

// returns a created node
Node* newNode(char* expression, int* position);

// adds a node to the tree
ParseTree* build(char* expression);

// prints a node
void printNode(Node* node);

// prints the expression
void printParseTree(ParseTree* tree);

// calculates part of a tree
int calculateSubtree(Node* node);

// calculates the whole expression
int calculate(ParseTree* tree);

// deletes node
void deleteNode(Node* node);

// Deleting tree
void deleteParseTree(ParseTree** tree);