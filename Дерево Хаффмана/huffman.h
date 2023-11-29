#pragma once

#include <stdlib.h>

#include "huffmanTree.h"

void insertionSortStep(const HuffmanTree** const array, const size_t index);

void insertionSort(const HuffmanTree** const array, const size_t size);

// char* compress(char* string) -> const char* const compress(const char* const string, size_t* const resultSize);
void const compress(const char* const string, size_t* const resultSize);
    
