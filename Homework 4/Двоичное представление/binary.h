#pragma once

#include <stdio.h>
#include <stdbool.h>

#define MAX_INT_BIT_SIZE 32

void decimalToBinary(int number, bool binary[]);

void printBinary(bool binary[]);

void binarySum(bool first[], bool second[], bool result[]);

int binaryToDecimal(bool array[]);