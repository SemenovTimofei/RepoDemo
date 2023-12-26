#include "tree.h"
#include "test.h"

int main()
{
	FILE* file = NULL;
	fopen_s(&file, "text.txt", "r");
	if (file == NULL)
	{
		printf("Error opening file\n");
		return 1;
	}

	ParseTree* tree = createParseTree("text.txt");
	
	printTree(tree);
}