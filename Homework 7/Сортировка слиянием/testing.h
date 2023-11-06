#pragma once

#include <stdbool.h>

#include "mergeSort.h"
#include "list.h"

typedef enum
{
    testErrorOpenningFile = -1,
    testErrorCode1,
    testErrorCode2,
    testErrorCode3,
    testsPassed,
} TestErrorCode;

// checks whether the list value of a certain type are the same
bool isSame(Node* list, Node* expectedList, int valueType);

// returns error code depending on success of passing tests
TestErrorCode testing();