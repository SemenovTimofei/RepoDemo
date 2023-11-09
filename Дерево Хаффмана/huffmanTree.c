#include <stdlib.h>

#include "huffmanTree.h"

typedef struct Node
{
    char value;
    size_t count;
    struct Node* leftChild;
    struct Node* rightChild;
} Node;

typedef struct HuffmanTree
{
    Node* root;
} HuffmanTree;

const HuffmanTree* makeLeaf(const char value, const size_t count)
{
    Node* leaf = (Node*)calloc(1, sizeof(Node));
    leaf->value = value;
    leaf->count = count;

    HuffmanTree* tree = (HuffmanTree*)malloc(sizeof(HuffmanTree));
    tree->root = tree;

    return tree;
}

const int getCount(HuffmanTree* tree)
{
    return tree->root->count;
}