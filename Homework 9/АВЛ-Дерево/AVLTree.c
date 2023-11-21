#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "AVLTree.h"

typedef struct Node
{
    char key[EXPRESSION_SIZE];
    char value[EXPRESSION_SIZE];
    size_t height;
    struct Node* parent;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct AVLTree
{
    Node* root;
} AVLTree;

AVLTree* createAVLTree()
{
    return calloc(1, sizeof(AVLTree));
}

size_t getHeight(Node* const node)
{
    return (node == NULL) ? -1 : node->height;
}

int getHeightDifference(Node* node)
{
    return getHeight(node->right) - getHeight(node->left);
}

void updateHeight(Node* node)
{
    size_t heightLeft = getHeight(node->left);
    size_t heightRight = getHeight(node->right);
    node->height = ((heightLeft > heightRight) ? heightLeft : heightRight) + 1;
}

bool isEmpty(AVLTree* const tree) 
{    
    return tree->root == NULL;
}

Node* rotateRight(Node* const root)
{
    Node* pivot = root->left;
    root->left = pivot->right;
    pivot->parent = root->parent;
    if (pivot->right != NULL)
    {
        pivot->right->parent = root;
    }
    pivot->right = root;
    root->parent = pivot;
    updateHeight(root);
    updateHeight(pivot);
    return pivot;
}

Node* rotateLeft(Node* const root)
{
    Node* pivot = root->right;
    root->right = pivot->left;
    pivot->parent = root->parent;
    if (pivot->left != NULL)
    {
        pivot->left->parent = root;
    }
    pivot->left = root;
    root->parent = pivot;
    updateHeight(root);
    updateHeight(pivot);
    return pivot;
}

Node* balance(Node* const node)
{
    if (node == NULL)
    {
        return node;
    }

    updateHeight(node);
    if (getHeightDifference(node) == 2)
    {
        if (getHeightDifference(node->right) < 0)
        {
            node->right = rotateRight(node->right);
        }
        return rotateLeft(node);
    }
    if (getHeightDifference(node) == -2)
    {
        if (getHeightDifference(node->left) > 0)
        {
            node->left = rotateLeft(node->left);
        }
        return rotateRight(node);
    }
    return node;
}

void insert(Node* const node, char* const key, char* const value)
{
    if (strcmp(key, node->key) == 0)
    {
        strcpy_s(node->value, EXPRESSION_SIZE, value);
        return;
    }
    if (strcmp(key, node->key) < 0)
    {
        if (node->left == NULL)
        {
            Node* newNode = calloc(1, sizeof(Node));
            newNode->parent = node;
            strcpy_s(newNode->key, EXPRESSION_SIZE, key);
            strcpy_s(newNode->value, EXPRESSION_SIZE, value);
            node->left = newNode;
            return;
        }
        insert(node->left, key, value);
        node->left = balance(node->left);
    }
    if (strcmp(key, node->key) > 0)
    {
        if (node->right == NULL)
        {
            Node* newNode = calloc(1, sizeof(Node));
            newNode->parent = node;
            strcpy_s(newNode->key, EXPRESSION_SIZE, key);
            strcpy_s(newNode->value, EXPRESSION_SIZE, value);
            node->right = newNode;
            return;
        }
        insert(node->right, key, value);
        node->right = balance(node->right);
    }
}

void addValue(AVLTree* const tree, char* const key, char* const value)
{
    if (tree == NULL)
    {
        return;
    }
    if (isEmpty(tree))
    {
        Node* newNode = calloc(1, sizeof(Node));
        strcpy_s(newNode->key, EXPRESSION_SIZE, key);
        strcpy_s(newNode->value, EXPRESSION_SIZE, value);
        tree->root = newNode;
        return;
    }
    insert(tree->root, key, value);
    tree->root = balance(tree->root);
}

char* get(Node* const node, char* const key)
{
    if (node == NULL)
    {
        return NULL;
    }
    if (strcmp(key, node->key) == 0)
    {
        return node->value;
    }
    (strcmp(key, node->key) < 0) ? get(node->left, key) : get(node->right, key);
}

char* getValue(AVLTree* const tree, char* const key)
{
    return get(tree->root, key);
}

bool find(Node* const node, char* const key)
{
    if (node == NULL)
    {
        return false;
    }
    if (strcmp(key, node->key) == 0)
    {
        return true;
    }
    (strcmp(key, node->key) < 0) ? find(node->left, key) : find(node->right, key);
}

bool isPresent(AVLTree* const tree, char* const key)
{
    return find(tree->root, key);
}

Node* findNodeClosestToNode(Node* const node)
{
    Node* rightmostNodeOnTheLeft = node->left;
    int leftPathLength = 1;
    while (rightmostNodeOnTheLeft->right != NULL)
    {
        rightmostNodeOnTheLeft = rightmostNodeOnTheLeft->right;
        leftPathLength++;
    }
    Node* leftmostNodeOnTheLeft = node->right;
    int rightPathLength = 1;
    while (leftmostNodeOnTheLeft->left != NULL)
    {
        leftmostNodeOnTheLeft = leftmostNodeOnTheLeft->left;
        rightPathLength++;
    }
    return (leftPathLength > rightPathLength) ? rightmostNodeOnTheLeft : leftmostNodeOnTheLeft;
}

void copyData(Node* const destination, Node* const source)
{
    strcpy_s(destination->value, EXPRESSION_SIZE, source->value);
    strcpy_s(destination->key, EXPRESSION_SIZE, source->key);
}

void deleteNode(Node* node, char* const key)
{
    if (node == NULL)
    {
        return;
    }

    if (strcmp(key, node->key) == 0)
    {
        if (node->right != NULL && node->left != NULL)
        {
            Node* temporary = findNodeClosestToNode(node);
            copyData(node, temporary);
            deleteNode(temporary, temporary->key);
            return;
        }
        if (node->right == NULL)
        {
            if (node->left != NULL)
            {
                node->left->parent = node->parent;
            }
            if (strcmp(key, node->parent->key) < 0)
            {
                node->parent->left = node->left;
            }
            else
            {
                node->parent->right = node->left;
            }
        }
        else
        {
            if (node->right != NULL)
            {
                node->right->parent = node->parent;
            }
            if (strcmp(key, node->parent->key) < 0)
            {
                node->parent->left = node->right;
            }
            else
            {
                node->parent->right = node->right;
            }
        }
        free(node);
        return;
    }
    (strcmp(key, node->key) < 0) ? deleteNode(node->left, key) : deleteNode(node->right, key);
    if (node->parent != NULL)
    {
        if (strcmp(node->key, node->parent->key) < 0)
        {
            node->parent->left = balance(node);
            return;
        }
        node->parent->right = balance(node);
    }
}

void deleteRoot(AVLTree* const tree)
{
    if (tree->root->right != NULL && tree->root->left != NULL)
    {
        Node* temporary = findNodeClosestToNode(tree->root);
        copyData(tree->root, temporary);
        deleteNode(temporary, temporary->key);
        tree->root = balance(tree->root);
        return;
    }
    Node* newRoot = NULL;
    if (tree->root->right == NULL)
    {
        newRoot = tree->root->left;
    }
    else
    {
        newRoot = tree->root->right;
    }
    if (newRoot != NULL)
    {
        newRoot->parent = NULL;
    }
    free(tree->root);
    tree->root = balance(newRoot);
}

void deleteValue(AVLTree* const tree, char* const key)
{
    if (tree == NULL)
    {
        return;
    }
    if (isEmpty(tree))
    {
        return;
    }
    if (strcmp(tree->root->key, key) == 0)
    {
        deleteRoot(tree);
        return;
    }
    deleteNode(tree->root, key);
    tree->root = balance(tree->root);
}

void deleteChildren(Node* const node)
{
    if (node == NULL)
    {
        return;
    }
    deleteChildren(node->left);
    deleteChildren(node->right);
    free(node);
}

void deleteAVLTree(const AVLTree** const tree)
{
    if ((*tree) != NULL)
    {
        deleteChildren((*tree)->root);
    }
    free(*tree);
    *tree = NULL;
}

void printMenu()
{
    printf("0 - Exit\n");
    printf("1 - Add value by key\n");
    printf("2 - Find value by key\n");
    printf("3 - Check presence of a key\n");
    printf("4 - Delete key\n");
    printf("Enter command: ");
}