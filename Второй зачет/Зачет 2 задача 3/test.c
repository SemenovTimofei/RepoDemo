#include "test.h"

bool testing()
{
	if (!isValid("ABCabc_ABC123abc"))
	{
		return false;
	}
	if (!isValid("a"))
	{
		return false;
	}
	if (!isValid("aa"))
	{
		return false;
	}
	if (!isValid("Z9___999"))
	{
		return false;
	}

	if (isValid("1AA_1"))
	{
		return false;
	}
	if (isValid("_A1"))
	{
		return false;
	}
	if (isValid("A_1+B"))
	{
		return false;
	}
	if (isValid(" "))
	{
		return false;
	}

	return true;
}