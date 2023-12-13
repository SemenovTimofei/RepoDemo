#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define EXPRESSION_SIZE 50

void smallNumber(char num[], size_t size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		bool swap = false;

		for (int j = 0; j < size - i - 1; ++j)
		{
			if (num[j] > num[j + 1])
			{
				char temporaryValue = num[j];
				num[j] = num[j + 1];
				num[j + 1] = temporaryValue;
				swap = true;
			}
		}

		if (swap == false)
		{
			break;
		}
	}

	return;
}

bool testing()
{
	char test1[] = "11111";
	size_t size1 = strlen(test1);
	smallNumber(test1, size1);
	for (size_t i = 0; i < size1 - 1; ++i)
	{
		if (test1[i] > test1[i + 1])
		{
			return false;
		}
	}

	char test2[] = "987654321";
	size_t size2 = strlen(test2);
	smallNumber(test2, size2);
	for (size_t i = 0; i < size2 - 1; ++i)
	{
		if (test2[i] > test2[i + 1])
		{
			return false;
		}
	}
	
	char test3[] = "12321";
	size_t size3 = strlen(test3);
	smallNumber(test3, size3);
	for (size_t i = 0; i < size3 - 1; ++i)
	{
		if (test3[i] > test3[i + 1])
		{
			return false;
		}
	}

	return true;
}

int main()
{
	if (!testing())
	{
		printf("Testing failed\n");
		return 1;
	}

	printf("Input number:\n");
	char number[EXPRESSION_SIZE];
	if (scanf_s("%s", number, sizeof(number)) != 1)
	{
		printf("Invalid input\n");
		return 1;
	}

	smallNumber(number, strlen(number));
	printf("The smallest number: %s\n", number);

	return 0;
}