#pragma once

#include <stdio.h>

#include "list.h"

#define HASH_TABLE_SIZE 1000

typedef struct HashTable HashTable;

size_t hash(const char* const value);

HashTable* createTable();

int insert(HashTable* table, const char* const value);

float loadFactor(const HashTable* const table);

size_t maxLength(const HashTable* const table);

float averageLength(const HashTable* const table);

void printTable(const HashTable* const table);

void freeTable(HashTable** table);