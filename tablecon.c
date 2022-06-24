// Conditions program for multiplication table.

#include <stdio.h>
#include "single.c"
int printTablesBook(int tablesCount, int endMultiple)
{
	int columnCount;
	for(columnCount = 1; columnCount <= tablesCount; columnCount++)
	{
		printf("The multiplication table of %d is:\n", columnCount);
		printSingleTable(columnCount, endMultiple);
	}
}
