#pragma once

#include <stdio.h>

#define MAX_SIZE 5

void swapColumns(int martix[][MAX_SIZE], size_t firstColumn, size_t secondColumn, size_t rowLength);

void sortMatrix(int martix[][MAX_SIZE], size_t columnLength, size_t rowLength);

void printMatrix(int martix[][MAX_SIZE], size_t columnLength, size_t rowLength);