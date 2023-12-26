#include "list.h"
#include "hash.h"

int main()
{
	HashTable* table = initializeTable();
	if (table == NULL)
	{
		return 1;
	}
	addToTable(table, "ababa");
	printTable(table);

	return 0;
}