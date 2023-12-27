#pragma once

#include <stdbool.h>

#include "mergeSort.h"

typedef enum
{
    testErrorOpenningFile = -1,
    testsPassed = 0,
    testErrorCode1 = 1,
    testErrorCode2 = 2,
    testErrorCode3 = 3,
} TestErrorCode;

// checks whether the list value of a certain type are the same
bool isSame(Node* list, Node* expectedList, int valueType);

// returns error code depending on success of passing tests
TestErrorCode testing();