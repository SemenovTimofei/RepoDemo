#include <stdio.h>

#include "list.h"

int main()
{
	Node* head = NULL;
	head = push(head, 1, 10);
	head = push(head, 2, 20);
	head = push(head, 3, 30);

	printList(head);

	return 0;
}