#include <stdio.h>
#include <stdbool.h>

void comment(char string[], int size)
{
	int flag = 0;
	for (int i = 0; i < size; ++i)
	{
		if (string[i] == ';')
		{
			flag = 1;
		}

		if (string[i] == '\n')
		{
			break;
		}

		if (flag == 1)
		{
			printf("%c", string[i]);
		}
	}

	return;
}

bool testCorrectCase()
{

}

int main()
{
	const char string[] = "a = 1 ; this doesn't work here";
	const int size = strlen(string);

	printf("The original string is:\n%s\n\n", string);
	
	printf("The comment is:\n");
	comment(string, size);
}