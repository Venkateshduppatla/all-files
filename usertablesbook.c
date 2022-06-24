// user program for tables book.

#include <stdio.h>
#include "tablecon.c"
int main()
{
	
	int tablesCount, endMultiple;
	printf("How many tables do you require in Tables Book? ");
	scanf("%d", &tablesCount);
	printf("Enter the end multiple of every table: ");
	scanf("%d", &endMultiple);
	printTablesBook(tablesCount, endMultiple);
}
