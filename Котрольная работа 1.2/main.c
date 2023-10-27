#include <stdio.h>
#include <stdbool.h>

void swap(int* firstValue, int* secondValue)
{
	int temporaryValue = *firstValue;
	*firstValue = *secondValue;
	*secondValue = temporaryValue;
}

void printArray(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}

	printf("\n");
}

void shellSort(int* array, int size)
{
	int step = size / 2;

	while (step > 0)
	{
		for (int i = 0; i < size - step; ++i)
		{
			int j = i;

			while (j >= 0 && (array[j + step] < array[j]))
			{
				swap(&array[j], &array[j + step]);
				j = j - step;
			}
		}

		step = step / 2;
	}
}

bool testing()
{
	int array1[] = { 132, 65, 6712, -4127, -312, 36 };
	int size1 = sizeof(array1) / sizeof(int);

	shellSort(&array1, size1);

	for (int i = 0; i < size1 - 1; ++i)
	{
		if (array1[i] > array1[i + 1])
		{
			return false;
		}
	}

	int array2[] = { -5, 321, 36, 33, 48, -532, -321, -321, 36, 33 };
	int size2 = sizeof(array2) / sizeof(int);

	shellSort(&array2, size2);

	for (int i = 0; i < size2 - 1; ++i)
	{
		if (array2[i] > array2[i + 1])
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

	int array[] = { 10, -5, 8, 6, 4, 7, 1, 2, 5, 9 };
	int size = sizeof(array) / sizeof(int);

	printf("The original array is: ");
	printArray(array, size);

	shellSort(&array, size);

	printf("The sorted array is: ");
	printArray(array, size);

	return 0;
}