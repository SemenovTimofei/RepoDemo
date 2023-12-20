#include <stdio.h>

#include "lexer.h"

int main()
{
	if (lexer("A_123"))
	{
		printf("yes");
	}
	else
	{
		printf("no");
	}
}