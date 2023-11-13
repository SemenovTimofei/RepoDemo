#include < stdbool.h>

#include "tree.h"

bool testing()
{
	Node* root = createNode();
	push(root, 5, "five");
	
	for (int i = -1000; i < 1000; ++i)
	{
		if (i != 5 && isPresent(root, i))
		{
			return false;
		}
	}

	deleteNode(root, 5);
	for (int i = -1000; i < 1000; ++i)
	{
		if (isPresent(root, i))
		{
			return false;
		}
	}

	push(root, 2, "two");
	push(root, 1, "one");
	push(root, 3, "three");
	push(root, 4, "four");

	if (search(root, 1) != "one" || search(root, 2) != "two" || search(root, 3) != "three" || search(root, 4) != "four")
	{
		return false;
	}

	deleteNode(root, 3);
	if (isPresent(root, 3))
	{
		return false;
	}
	if (search(root, 1) != "one" || search(root, 2) != "two" || search(root, 4) != "four")
	{
		return false;
	}

	deleteNode(root, 2);
	if (isPresent(root, 2))
	{
		return false;
	}
	if (search(root, 1) != "one" || search(root, 4) != "four")
	{
		return false;
	}

	return true;
}