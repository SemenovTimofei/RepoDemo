#pragma once

#include <stdio.h>
#include <stdlib.h>

enum states
{
    start = 0,
    openningSlash = 1,
    openningAsterisk = 2,
    comment = 3,
    closingAsterisk = 4,
    closingSlash = 5
};

char* getComment(FILE* file);