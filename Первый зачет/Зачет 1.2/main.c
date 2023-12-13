#include <stdio.h>

#include "queue.h"
#include "test.h"

int main()
{
	/*
	if (!testing())
	{
		printf("Testing failed\n");
		return 1;
	}
	*/

	List* list = NULL;

	enqueue(&list, 10, 16);
	enqueue(&list, 5, 1);
	enqueue(&list, 1, 5);
	enqueue(&list, 2, 4);
	enqueue(&list, 3, 3);

	printList(list);
	printf("The value with the biggest priority: %d\n", dequeue(&list));

	deleteList(&list);
	return 0;
}