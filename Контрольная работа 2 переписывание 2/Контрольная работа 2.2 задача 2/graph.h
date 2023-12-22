#pragma once

#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], size_t n);

void writeToFile(int matrix[MAX_SIZE][MAX_SIZE], size_t n, char fileName[]);

void transitiveClosure(int matrix[MAX_SIZE][MAX_SIZE], size_t n, char fileName[]);