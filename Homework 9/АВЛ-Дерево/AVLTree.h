#pragma once

#include <stdio.h>

#define EXPRESSION_SIZE 100

typedef struct Node Node;

typedef struct AVLTree AVLTree;

// returns an initialized AVL-Tree
AVLTree* createAVLTree();

// returns node height
size_t getHeight(Node* const node);

// returns height difference between two siblings
int getHeightDifference(Node* node);

// updates height values
void updateHeight(Node* node);

// returns true or false whether the tree root is empty
bool isEmpty(AVLTree* const tree);

Node* rotateRight(Node* const root);

Node* rotateLeft(Node* const root);

Node* balance(Node* const node);

void insert(Node* const node, char* const key, char* const value);

void addValue(AVLTree* const tree, char* const key, char* const value);

char* get(Node* const node, char* const key);

char* getValue(AVLTree* const tree, char* const key);

bool find(Node* const node, char* const key);

bool isPresent(AVLTree* const tree, char* const key);

Node* findNodeClosestToNode(Node* const node);

void copyData(Node* const destination, Node* const source);

void deleteNode(Node* node, char* const key);

void deleteRoot(AVLTree* const tree);

void deleteValue(AVLTree* const tree, char* const key);

void deleteChildren(Node* const node);

void deleteAVLTree(const AVLTree** const tree);

void printOptions();