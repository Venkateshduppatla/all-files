// Print single table.
#include<stdio.h>
int printSingleTable(int number, int endMultiple)
{
	int counter, product;
	for(counter = 1; counter <= endMultiple; counter++)
	{
		product = number * counter;
		printf("%2d x %2d = %3d\n", number, counter, product);
	}
		
}