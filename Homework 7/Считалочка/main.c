#include <stdio.h>

#include "cycle.h"

int main()
{
	if (!testing())
	{
		printf("Testing failed\n");
		return 1;
	}

	printf("Enter how many soldiers there are: ");

	int size = 0;
	scanf_s("%d", &size);
	if (size <= 0)
	{
		printf("There must be at least one soldier\n");
		return 1;
	}

	printf("Enter which soldier will be killed next: ");

	int step = 0;
	scanf_s("%d", &step);
	if (step <= 0)
	{
		printf("Invalid step\n");
		return 1;
	}

	printf("The surviving soldier is number %d\n", findSurvivor(size, step));
}