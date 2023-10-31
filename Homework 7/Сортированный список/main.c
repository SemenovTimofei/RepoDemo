#include <stdio.h>

#include "list.h"

int main()
{
	if (!testing())
	{
		printf("Testing failed\n");
		return 1;
	}

	List* list = NULL;

	int command = -1;
	int elementCount = 0;

	while (command != 0)
	{
		printf("Enter the command: ");
		scanf_s("%d", &command);
		switch (command)
		{
		case 0:
		{
			if (elementCount == 0)
			{
				free(list);
				return 0;
			}
			deleteList(&list);
			return 0;
		}
		case 1:
		{
			printf("Enter value: ");

			int value = 0;
			if (scanf_s("%d", &value) == NULL)
			{
				printf("Invalid input\n");
				return 1;
			}

			push(&list, value);
			++elementCount;

			break;
		}
		case 2:
		{
			printf("Enter index of the element to delete: ");
			int index = 0;
			if (scanf_s("%d", &index) == NULL)
			{
				printf("Invalid input\n");
				return 1;
			}

			if (elementCount == 0)
			{
				printf("The list is empty\n");
				break;
			}

			if (0 <= index && index <= elementCount - 1)
			{
				deleteElement(&list, index);
				--elementCount;
				break;
			}

			printf("Invalid index\n");
			break;
		}
		case 3:
		{
			if (elementCount > 0)
			{
				printList(list);
				break;
			}
			
			printf("The list is empty\n");
			break;
		}
		default:
		{
			printf("Invalid command\n");
			return 1;
		}
		}
	}
}