#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "huffman.h"
#include "huffmanTree.h"

#define ALPHABET_SIZE 256

void insertionSortStep(const HuffmanTree** const array, const size_t index)
{
    for (size_t i = index; i >= 1 && getCount(array[i - 1]) < getCount(array[i]); --i)
    {
        const HuffmanTree* temporary = array[i];
        array[i] = array[i - 1];
        array[i - 1] = temporary;
    }
}

void insertionSort(const HuffmanTree** const array, const size_t size)
{
    for (size_t i = 1; i < size; ++i)
    {
        insertionSortStep(array, i);
    }
}

static char toByte(const bool* const array, const size_t index)
{
    char result = 0;
    for (size_t i = index; i < 8; ++i)
    {
        result += array[i + index] * (1 << (7 - i));
    }
    return result;
}

static void writeTable(const Code* const table, const char* const fileName)
{
    FILE* file = NULL;
    fopen_s(&file, fileName, "w");

    for (size_t i = 0; i < 256; ++i)
    {
        fputc((char)i, file);
        for (size_t j = 0; j < 256; j += 8)
        {
            fputc(toByte(table[i].code, j), file);
        }
    }
}

static void writeMessage(const char* const text, const Code* const table, const char* const fileName)
{
    FILE* file = NULL;
    fopen_s(&file, fileName, "b");
    char buffer = 0;
    size_t bufferIndex = 0;
    for (size_t i = 0; text[i] != '\0'; ++i)
    {
        for (size_t j = 0; j < table[i].size; ++j)
        {
            buffer += table[text[i]].code[j] << (7 - bufferIndex);
            ++bufferIndex;
            if (bufferIndex >= 8)
            {
                fputc(buffer, file);
                buffer = 0;
                bufferIndex = 0;
            }
        }
    }
    fputc(buffer, file);
}

void const compress(const char* const string, size_t* const resultSize)
{
    size_t* const charCount = (size_t*)calloc(ALPHABET_SIZE, sizeof(size_t));
    size_t stringLength = strlen(string);

    for (size_t i = 0; i < stringLength; ++i)
    {
        ++charCount[string[i]];
    }

    HuffmanTree** treeArray = (HuffmanTree**)calloc(ALPHABET_SIZE, sizeof(HuffmanTree*));

    for (size_t i = 0; i < ALPHABET_SIZE; ++i)
    {
        treeArray[i] = charCount[i] != 0 ? makeLeaf((char)i, charCount[i]) : NULL;
    }

    insertionSort(treeArray, ALPHABET_SIZE);

    for (size_t i = ALPHABET_SIZE - 1; i != 0; --i)
    {
        if (treeArray[i] == NULL)
        {
            continue;
        }

        treeArray[i] = makeTree(&treeArray[i], &treeArray[i - 1]);
        insertionSortStep(treeArray, i);
    }

    Code* table = createCodeTable(treeArray[0]);
    writeTable(table, "output.txt");
    writeMessage(string, table, "output.txt");
    return;
}