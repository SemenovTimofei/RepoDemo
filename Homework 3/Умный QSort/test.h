#pragma once

#include "quickSort.h"

int* createRandomArray(size_t size);

bool compareArrays(int firstArray[], int secondArray[], size_t size);

bool isSorted(int array[], size_t size);

bool testing();