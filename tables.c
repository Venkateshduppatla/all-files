// print tables book.

#include <stdio.h>
void main()
{
	int tablesCount, endMultiple, product, columnCount, counter;
	printf("How many tables do you require in Tables Book? ");
	scanf("%d", &tablesCount);
	printf("Enter the end multiple of every table: ");
	scanf("%d",  &endMultiple);
	for(columnCount = 1; columnCount <= tablesCount; columnCount++)
	{
		printf("The multiplication table of %d is:\n", columnCount);
		for(counter = 1; counter <= endMultiple; counter++)
		{
			product = columnCount * counter;
			printf("%2d x %2d = %3d\n",columnCount, counter, product);
		}
	}
		
}