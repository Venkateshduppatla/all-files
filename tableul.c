// Print tables book.

#include <stdio.h>
#include "mytools.c"
#define MAX_LENGTH 15
void main()
{
	int tablesCount, endMultiple, product, columnCount, productCounter;
	char storedString[MAX_LENGTH];
	printf("How many tables do you require in a Tables Book? ");
	scanf("%d", &tablesCount);
	printf("Enter the end multiple of every table: ");
	scanf("%d", &endMultiple);
	for(columnCount = 1; columnCount <= tablesCount; columnCount++)
	{
		sprintf(storedString, "Table-%d:", columnCount);
		doUnderLine(storedString);
		printf("\n");
		for(productCounter = 1; productCounter <= endMultiple; productCounter++)
		{
			product = columnCount * productCounter;
			printf("%2d x %2d = %4d\n", columnCount, productCounter, product);
		}
		printf("\n");
	}
		
}
