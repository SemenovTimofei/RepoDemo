#include "tree.h"

typedef struct Node
{
    Node* left;
    Node* right;
    int number;
    char operation;
} Node;

typedef struct ParseTree
{
    Node* root;
} ParseTree;

/*
Node* createNode(int number, char operation)
{
    Node* newNode = (Node*)calloc(1, sizeof(Node));
    if (newNode == NULL)
    {
        return NULL;
    }
    newNode->number = number;
    newNode->operation = operation;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


ParseTree* initializeParseTree()
{
    return (ParseTree*)calloc(1, sizeof(ParseTree));
}
*/

bool isOperation(char character)
{
    return character == '+' || character == '-' || character == '/' || character == '*';
}

Node* buildTree(FILE* file)
{
    char current = fgetc(file);
    while (current != EOF && !isdigit(current) && !isOperation(current))
    {
        current = fgetc(file);
    }

    Node* newNode = (Node*)calloc(1, sizeof(Node));
    if (newNode == NULL)
    {
        return NULL;
    }
    if (isdigit(current))
    {
        printf("number %c\n", current);
        newNode->number = current;
    }
    else if (isOperation(current))
    {
        printf("operation %c\n", current);
        newNode->operation = current;
        newNode->left = buildTree(file);
        newNode->right = buildTree(file);
    }
    return newNode;
}

ParseTree* createParseTree(char fileName[])
{
    FILE* file = NULL;
    fopen_s(&file, fileName, "r");
    if (file == NULL)
    {
        return NULL;
    }
    ParseTree* tree = (ParseTree*)calloc(1, sizeof(ParseTree));
    if (tree == NULL)
    {
        fclose(file);
        return NULL;
    }
    tree->root = buildTree(file);
    return tree;
}

void printTree(ParseTree* tree)
{
    Node* node = tree->root;
    if (node == NULL)
    {
        return;
    }
    if (node->left == NULL && node->right == NULL)
    {
        printf("%d ", node->number);
        return;
    }
    printf("%c ", node->operation);
    printTree(node->left);
    printTree(node->right);
}