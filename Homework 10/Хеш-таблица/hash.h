#pragma once

#include "list.h"

#define HASH_TABLE_SIZE 20

#define MODULUS 17

#include "hash.h"

typedef struct HashTable HashTable;

size_t hash(char word[]);

HashTable* initializeTable();

int addToTable(HashTable* table, char word[]);