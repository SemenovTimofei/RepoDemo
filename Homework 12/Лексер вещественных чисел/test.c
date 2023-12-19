#include "test.h"

bool testing()
{
    if (!isRealNumber("0"))
    {
        return false;
    }
    if (!isRealNumber("123"))
    {
        return false;
    }
    if (!isRealNumber("123.456"))
    {
        return false;
    }
    if (!isRealNumber("123.456E10"))
    {
        return false;
    }
    if (!isRealNumber("123.456E-10"))
    {
        return false;
    }
    if (!isRealNumber("123.456E+10"))
    {
        return false;
    }

    if (isRealNumber("number"))
    {
        return false;
    }
    if (isRealNumber("."))
    {
        return false;
    }
    if (isRealNumber("123..456"))
    {
        return false;
    }
    if (isRealNumber("123.456.789"))
    {
        return false;
    }
    if (isRealNumber("123.456E"))
    {
        return false;
    }
    if (isRealNumber("123.456E+"))
    {
        return false;
    }
    if (isRealNumber("123.456E+-10"))
    {
        return false;
    }
    if (isRealNumber("123.456E10E10"))
    {
        return false;
    }
    if (isRealNumber("123four"))
    {
        return false;
    }

    return true;
}