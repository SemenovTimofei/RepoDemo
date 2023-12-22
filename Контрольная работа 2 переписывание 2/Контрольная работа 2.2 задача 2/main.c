#include <stdio.h>

#define MAX_SIZE 100

void writeToFile(int matrix[MAX_SIZE][MAX_SIZE], size_t n) // change to FILE* file later
{
	FILE* output = fopen("output.txt", "w");
	for (size_t i = 0; i < n; ++i)
	{
		for (size_t j = 0; j < n; ++j)
		{
			fprintf(output, "%d ", matrix[i][j]);
		}
		fprintf(output, "\n");
	}
	fclose(output);
	return;
}

void transitiveClosure(int matrix[MAX_SIZE][MAX_SIZE], size_t n)
{
	int newMatrix[MAX_SIZE][MAX_SIZE];
	for (size_t i = 0; i < n; ++i)
	{
		for (size_t j = 0; j < n; ++j)
		{
			newMatrix[i][j] = matrix[i][j];
		}
	}

	for (size_t k = 0; k < n; ++k)
	{
		for (size_t i = 0; i < n; ++i)
		{
			for (size_t j = 0; j < n; ++j)
			{
				if (newMatrix[i][k] == 1 && newMatrix[k][j] == 1)
				{
					newMatrix[i][j] = 1;
				}
			}
		}
	}
	
	writeToFile(newMatrix, n);
	return;
}

int main()
{
	/*
	int matrix[n][n] = { { 0, 1, 1, 1 }, { 1, 0, 1, 0 }, { 1, 1, 0, 1 }, { 1, 0, 1, 0} };

	for (size_t k = 0; k < n; ++k)
	{
		for (size_t i = 0; i < n; ++k)
		{
			for (size_t j = 0; j < n; ++j)
			{
				if (matrix[])
			}
		}
	}
	*/

	size_t n = 0;
	FILE* input = fscanf_s(&input, "%d", &n);

	int matrix[MAX_SIZE][MAX_SIZE];
	for (size_t i = 0; i < n; ++i)
	{
		for (size_t j = 0; j < n; ++j)
		{
			fscanf_s(input, "%d", &matrix[i][j]);
		}
	}

	transitiveClosure(matrix, n);

	fclose(input);


	return 0;
}