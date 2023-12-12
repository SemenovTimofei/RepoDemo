#include "search.h"
#include "test.h"

int main()
{
	if (!testing())
	{
		printf("Testing failed\n");
		return 1;
	}

	printf("First entry of substring: %d\n", find("abc", "cb")); // add fail safes in code: string < substring...
	return 0;
}