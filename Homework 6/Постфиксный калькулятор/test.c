#include "test.h"

bool testing()
{
    if (!(calculatePostfix("1 2 + 3 + 4 +") == 10))
    {
        return false;
    }
    if (!(calculatePostfix("4 5 * 6 *") == 120))
    {
        return false;
    }
    if (!(calculatePostfix("5") == 5))
    {
        return false;
    }
    if (!(calculatePostfix("9 3 /") == 3))
    {
        return false;
    }
    if (!(calculatePostfix("1 4 -") == -3))
    {
        return false;
    }
    if (!(calculatePostfix("9 3 + 4 * 4 - 4 /") == 11))
    {
        return false;
    }

    return true;
}