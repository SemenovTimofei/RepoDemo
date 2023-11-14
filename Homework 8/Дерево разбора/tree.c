#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "tree.h"

typedef struct Node
{
    char operation;
    int operand;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct ParseTree
{
    Node* root;
};

ParseTree* createParseTree()
{
    return calloc(1, sizeof(ParseTree));
}

bool isEmpty(ParseTree* tree)
{
    return tree->root == NULL;
}

bool isLeaf(Node* node)
{
    return node->left == NULL && node->right == NULL;
}

bool isOperation(char symbol)
{
    return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/';
}

int getNumber(char* expression, int* position)
{
    int number = 0;
    while ('0' <= expression[*position] && expression[*position] <= '9')
    {
        number = number * 10 + (expression[*position] - '0');
        ++(*position);
    }

    return number;
}

Node* newNode(char* expression, int* position)
{
    ++(*position);
    while (expression[*position] == ' ' || expression[*position] == '(' || expression[*position] == ')')
    {
        ++(*position);
    }

    Node* node = calloc(1, sizeof(Node));

    if (isOperation(expression[*position]))
    {
        node->operation = expression[*position];
        node->left = newNode(expression, position);
        node->right = newNode(expression, position);
    }
    else
    {
        node->operand = getNumber(expression, position);
    }

    return node;
}

ParseTree* build(char* expression)
{
    int position = -1;

    ParseTree* tree = createParseTree();
    tree->root = newNode(expression, &position);

    return tree;
}

void printNode(Node* node)
{
    if (isLeaf(node))
    {
        printf("%d ", node->operand);
        return;
    }

    printf("%c ", node->operation);
    printNode(node->left);
    printNode(node->right);
}

void printParseTree(ParseTree* tree)
{
    if (isEmpty(tree))
    {
        return;
    }
    printNode(tree->root);
}

int calculateSubtree(Node* node)
{
    if (isLeaf(node))
    {
        return node->operand;
    }
    int operand1 = calculateSubtree(node->left);
    int operand2 = calculateSubtree(node->right);
    char operation = node->operation;
    if (operation == '+')
    {
        return operand1 + operand2;
    }
    if (operation == '-')
    {
        return operand1 - operand2;
    }
    if (operation == '*')
    {
        return operand1 * operand2;
    }
    return operand1 / operand2;
}

int calculate(ParseTree* tree)
{
    return calculateSubtree(tree->root);
}

void deleteNode(Node* node)
{
    if (node == NULL)
    {
        return;
    }

    deleteNode(node->left);
    deleteNode(node->right);
    free(node);
}

void deleteParseTree(ParseTree** tree)
{
    deleteNode((*tree)->root);
    free(*tree);
    *tree = NULL;

    return;
}