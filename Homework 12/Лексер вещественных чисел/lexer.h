#pragma once

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

enum states
{
    start = 0,
    integer = 1,
    decimalPoint = 2,
    decimalDigit = 3,
    exponent = 4,
    exponentSign = 5,
    exponentDigit = 6
};

bool isRealNumber(char text[]);