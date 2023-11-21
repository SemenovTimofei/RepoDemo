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

// returns true or false whether the tree is empty
bool isEmpty(AVLTree* const tree);

// changes tree structure accordingly
Node* rotateRight(Node* const root);

// changes tree structure accordingly
Node* rotateLeft(Node* const root);

// changes tree structure accordingly
Node* balance(Node* const node);

// finds its place and inserts the value at a given key
void insert(Node* const node, char* const key, char* const value);

// adds the value to the tree
void addValue(AVLTree* const tree, char* const key, char* const value);

// finds and returns the value at a given key
char* get(Node* const node, char* const key);

// finds the value in the tree
char* getValue(AVLTree* const tree, char* const key);

// searches for the key and returns true or false whether the key is present
bool find(Node* const node, char* const key);

// returns true or false whether the key is present in the tree
bool isPresent(AVLTree* const tree, char* const key);

// returns the closest node
Node* findNodeClosestToNode(Node* const node);

// copies data from one node to another
void copyData(Node* const destination, Node* const source);

// deletes a node at a given key
void deleteNode(Node* node, char* const key);

// deletes the tree root
void deleteRoot(AVLTree* const tree);

// deletes a value within the tree
void deleteValue(AVLTree* const tree, char* const key);

// deletes tree branches
void deleteChildren(Node* const node);

// deletes the whole tree
void deleteAVLTree(const AVLTree** const tree);

// prints command options
void printMenu();