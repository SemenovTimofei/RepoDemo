#pragma once

#include <stdbool.h>

typedef struct Node Node;

typedef struct HuffmanTree HuffmanTree;

typedef struct Code
{
    size_t size;
    bool code[256];
} Code;

const HuffmanTree* makeLeaf(const char value, const size_t count);

const int getCount(HuffmanTree* tree);
    
HuffmanTree* makeTree(HuffmanTree** const first, HuffmanTree** const second);

void makeCode(size_t position, bool code[256], Node* current, Code* codeTable);

Code* createCodeTable(const HuffmanTree* const tree);