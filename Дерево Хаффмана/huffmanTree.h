#pragma once

typedef struct HuffmanTree HuffmanTree;

const HuffmanTree* makeLeaf(const char value, const size_t count);

const int getCount(HuffmanTree* tree);