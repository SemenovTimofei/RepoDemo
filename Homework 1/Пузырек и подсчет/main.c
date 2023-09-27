#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

void countingSort(int* array, int size)
{
	int* arraySort = (int*)malloc(10 * size); // 10 это количество возможных цифр в массиве (0, 1, 2 ... 9)
	memset(arraySort, 0, size * 10);

	for (int i = 0; i < size; ++i)
	{
		++arraySort[array[i]];
	}

	int addNumber = 0;
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < arraySort[i]; ++j)
		{
			array[addNumber++] = i;
		}
	}

	free(arraySort);
}

void bubbleSort(int array[], int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		bool swap = false;

		for (int j = 0; j < size - i - 1; ++j)
		{
			if (array[j] > array[j + 1])
			{
				int temporaryValue = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temporaryValue;
				swap = true;
			}
		}

		if (swap == false)
		{
			break;
		}
	}
}

void main()
{
	int size = 100000;
	int* array = (int*)malloc(size * 4);
	memset(array, 0, size * 4);

	srand((unsigned int)time(NULL));

	for (int i = 0; i < size; ++i) 
	{
		array[i] = rand() % 10;
	}

	time_t start = time(NULL);

	countingSort(array, size);

	printf("Counting sort execution time: %Ii second(s)\n", time(NULL) - start);

	start = time(NULL);
	
	for (int i = 0; i < size; ++i)
	{
		array[i] = rand() % 10;
	}

	bubbleSort(array, size);

	printf("Bubble sort execution time: %Ii second(s)\n", time(NULL) - start);

	free(array);
}