#pragma once

#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// print the matrix
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], size_t n);

// takes a matrix and writes it to a file
void writeToFile(int matrix[MAX_SIZE][MAX_SIZE], size_t n, char fileName[]);

// prints a transitive matrix to a file
void transitiveClosure(int matrix[MAX_SIZE][MAX_SIZE], size_t n, char fileName[]);