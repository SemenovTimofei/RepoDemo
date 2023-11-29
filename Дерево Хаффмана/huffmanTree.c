#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>

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

/*
typedef struct Code
{
    size_t size;
    bool code[256];
} Code;
*/

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
    return tree != NULL ? tree->root->count : 0;
}

HuffmanTree* makeTree(HuffmanTree** const first, HuffmanTree** const second)
{
    HuffmanTree* newTree = makeLeaf('\0', getCount(*first) + getCount(*second));
    newTree->root->leftChild = (*first)->root;
    newTree->root->rightChild = (*second)->root;

    free(*first);
    free(*second);
    *first = NULL;
    *second = NULL;

    return newTree;
}

void makeCode(size_t position, bool code[256], Node* current, Code* codeTable)
{
    if (current->leftChild == NULL)
    {
        codeTable[current->value].size = position;
        memcpy_s(codeTable[current->value].code, 256 * sizeof(bool), code, 256 * sizeof(bool));
        return;
    }

    code[position] = 0;
    makeCode(position + 1, code, current->leftChild, codeTable);
    code[position] = 1;
    makeCode(position + 1, code, current->rightChild, codeTable);
}

Code* createCodeTable(const HuffmanTree* const tree)
{
    Code* table = (Code*)calloc(256, sizeof(Code));
    bool code[256] = { false };
    makeCode(0, code, tree->root, table);
    return table;
}