#include <stdio.h>

void swap(int* firstValue, int* secondValue)
{
	int temporaryValue = *firstValue;
	*firstValue = *secondValue;
	*secondValue = temporaryValue;
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

void printArray(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}

	printf("\n");
}

int main()
{
	int array[] = { 10, -5, 8, 6, 4, 7, 1, 2, 5, 9 };
	int size = sizeof(array) / sizeof(int);

	printf("The original array is: ");
	printArray(array, size);

	shellSort(&array, size);

	printf("The sorted array is: ");
	printArray(array, size);
}