#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void swap(int* firstValue, int* secondValue);

void printArray(int* array, size_t size);

void insertionSort(int array[], size_t start, size_t end);

size_t partition(int array[], size_t start, size_t end);

void quickSort(int array[], size_t start, size_t end);