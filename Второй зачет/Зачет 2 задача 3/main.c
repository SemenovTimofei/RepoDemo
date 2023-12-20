#include <stdio.h>

#include "lexer.h"
#include "test.h"

#define EXPRESSION_SIZE 50

int main()
{
	if (!testing())
	{
		printf("Testing failed\n");
		return 1;
	}

	printf("Enter a string: \n");
	char text[EXPRESSION_SIZE] = { '\0' };
	scanf_s("%s", &text, EXPRESSION_SIZE);

	if (isValid(text))
	{
		printf("%s fits the criteria", text);
	}
	else
	{
		printf("%s does not fit the criteria", text);
	}

	return 0;
}