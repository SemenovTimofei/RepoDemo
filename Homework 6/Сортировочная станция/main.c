#include <stdio.h>

#include "stack.h"

#define MAX_LENGTH 100

int main()
{
	if (!testing())
	{
		printf("Testing failed\n");
		return 1;
	}

	printf("Enter the expression: ");

	char text[MAX_LENGTH] = { 0 };
	if (fgets(text, MAX_LENGTH, stdin) == NULL)
	{
		return -1;
	}

	infixToPostfix(text);

	printf("%s", text);
}