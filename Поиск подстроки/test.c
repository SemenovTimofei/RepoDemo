#include "search.h"
#include "test.h"

bool testing()
{
	if (find("abc", "d") != 0)
	{
		return false;
	}
	return true;
}