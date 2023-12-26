#include "tree.h"

typedef struct Node
{
    int value;
    Node* left;
    Node* right;
} Node;

typedef struct Tree
{
    Node* root;
} Tree;

Node* createNode(int value)
{
    Node* newNode = (Node*)calloc(1, sizeof(Node));
    if (newNode == NULL)
    {
        return NULL;
    }
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

bool isOperation(char character)
{
    return character == '-' || character == '+' || character == '/' || character == '*';
}

void freeNodes(Node* node)
{
    if (node == NULL)
    {
        return;
    }
    freeNodes(node->left);
    freeNodes(node->right);
    free(node);
}

Node* addNodes(FILE* file)
{
    Node* newNode = NULL;
    char current = fgetc(file);
    while (current != EOF && current != ')')
    {
        if (isOperation(current))
        {
            newNode = createNode(current);
            if (newNode == NULL)
            {
                return NULL;
            }
            newNode->left = addNodes(file);
            newNode->right = addNodes(file);
            if (newNode->left == NULL || newNode->right == NULL)
            {
                freeNodes(newNode);
                return NULL;
            }
        }
        else if (isdigit(current))
        {
            newNode = createNode(current);
            if (newNode == NULL)
            {
                return NULL;
            }
            break;
        }
        current = fgetc(file);
    }
    return newNode;
}

int createTree(Tree** tree, char fileName[])
{
    FILE* file = NULL;
    fopen_s(&file, fileName, "r");
    if (file == NULL)
    {
        return 1;
    }

    *tree = (Tree*)calloc(1, sizeof(Tree));
    if (*tree == NULL)
    {
        fclose(file);
        return 1;
    }

    (*tree)->root = addNodes(file);
    fclose(file);
    return 0;
}

void printTree()
{

}