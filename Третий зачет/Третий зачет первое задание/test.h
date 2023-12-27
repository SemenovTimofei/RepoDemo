#pragma once

#include <stdbool.h>

#include "matrixSort.h"

bool compareMatrices(int firstMatrix[][MAX_SIZE], int secondMatrix[][MAX_SIZE], size_t columnLength, size_t rowLength);

bool testing();