#pragma once

#include <stdbool.h>
#include <stdio.h>

enum states
{
    start = 0,
    openningSlash = 1,
    openningAsterisk = 2,
    comment = 3,
    closingAsterisk = 4,
    closingSlash = 5
};

void printComment(FILE* file);