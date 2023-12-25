#pragma once

#include <stdbool.h>
#include <stdlib.h> // might not need this

#define MAX_INT_BIT_SIZE 32

size_t binaryLength(int number);

void decimalToBinary(int number, bool binaryArray[]);

void printBinary(bool binary[]);
