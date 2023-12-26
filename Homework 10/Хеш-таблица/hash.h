#pragma once

#include "list.h"

#define HASH_TABLE_SIZE 100
#define EXPRESSION_SIZE 100
#define MODULUS 17

typedef struct HashTable HashTable;

size_t hash(char word[]);

HashTable* initializeTable();

int addToTable(HashTable* table, char word[]);

void printTable(HashTable* table);

void freeTable(HashTable** table);

float loadFactor(HashTable* table);

size_t maxListLength(HashTable* table);

float averageListLength(HashTable* table);