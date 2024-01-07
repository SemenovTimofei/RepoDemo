#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"

#define MAX_EXPRESSION_LENGTH 100

typedef struct Node
{
    int key;
    char* value;
    Node* left;
    Node* right;
} Node;

Node* createNode(int key, char* value)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

Node* push(Node* root, int key, char* text)
{
    size_t length = strlen(text) + 1;
    char* value = (char*)calloc(length, sizeof(char));
    strcpy_s(value, sizeof(char) * length, text);

    if (root == NULL)
    {
        return createNode(key, value);
    }

    if (key < root->key)
    {
        root->left = push(root->left, key, value);
    }
    else if (key > root->key)
    {
        root->right = push(root->right, key, value);
    }
    else
    {
        // fix
        free(root->value);
        root->value = malloc(sizeof(value));
        strcpy_s(root->value, sizeof(value), value);
    }

    return root;
}

char* search(Node* root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    
    if (key < root->key)
    {
        return search(root->left, key);
    }
    else if (root->key == key)
    {
        return root->value;
    }
    return search(root->right, key);
}

bool isPresent(Node* root, int key)
{
    return search(root, key) != NULL;
}

Node* minValueNode(Node* root)
{
    Node* current = root;

    while (current->left != NULL)
    {
        current = current->left;
    }

    return current;
}

Node* deleteNode(Node* root, int key)
{
    if (root == NULL)
    {
        return root;
    }

    if (key < root->key)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            Node* temporary = root->right;
            free(root->value);
            free(root);
            return temporary;
        }
        else if (root->right == NULL)
        {
            Node* temporary = root->left;
            free(root->value);
            free(root);
            return temporary;
        }

        Node* temporary = minValueNode(root->right);
        root->key = temporary->key;
        root->value = temporary->value;
        root->right = deleteNode(root->right, temporary->key);
    }
    return root;
}

void deleteTree(Node* root)
{
    if (root != NULL)
    {
        deleteTree(root->left);
        deleteTree(root->right);
        free(root->value);
        free(root);
    }
}