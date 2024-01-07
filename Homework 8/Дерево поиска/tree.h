#pragma once

#include <stdbool.h>

typedef struct Node Node;

// returns node
Node* createNode();

// returns tree with the added value to a tre at a certain index
Node* push(Node* root, int key, char* value);

// returns value at a certain index
char* search(Node* root, int key);

// returns true or false depending on presence of a node
bool isPresent(Node* root, int key);

// return node with the smallest value
Node* minValueNode(Node* root);

// returns tree with a certain node deleted
Node* deleteNode(Node* root, int key);

// deletes the whole tree
void deleteTree(Node* root);