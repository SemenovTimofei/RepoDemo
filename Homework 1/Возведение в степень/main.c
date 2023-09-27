#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int recursiveExponentiation(const int number, const int power)
{
	if (power == 0)
	{
		return 1;
	}
	if (power % 2 == 1)
	{
		return recursiveExponentiation(number, power - 1) * number;
	}
	return recursiveExponentiation(number, power / 2) * recursiveExponentiation(number, power / 2);
}

int iterativeExponentiation(const int number, int power)
{
	if (power == 0)
	{
		return 1;
	}

	int result = number;
	while (power > 1)
	{
		result *= number;
		--power;
	}

	return result;
}

bool testCorrectCase(const int number, const int power)
{
	return (pow(number, power) == recursiveExponentiation(number, power)) && (pow(number, power) == iterativeExponentiation(number, power));
}

void main()
{
	printf("Enter a number\n");
	int number = 1;
	scanf_s("%d", &number);

	printf("Enter an exponent\n");
	int power = 1;
	scanf_s("%d", &power);

	if (power < 0)
	{
		printf("Raising to a negative power is not supported\n");
		return;
	}

	if (!testCorrectCase(number, power))
	{
		printf("Test failed\n");
		return;
	}

	printf("%d to the power of %d is %d", number, power, recursiveExponentiation(number, power));
}