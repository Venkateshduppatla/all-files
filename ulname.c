//Program to print the given string with an underline.

#include <stdio.h>
#define MAX_LENGTH 50
#include "mytools.c"
int main()
{
	char string[MAX_LENGTH];
	printf("Enter the String: ");
	fgets(string, MAX_LENGTH, stdin);
	removeNewLine(string);
	printf("\n");
	printUnderLineForGivenString(string);
}

printUnderLineForGivenString(char *string)
{
	int stringLength, counter;
	stringLength = printf("%s", string);
	printf("\n");
	for(counter = 0; counter < stringLength; counter++)
	{
		printf("-");
	}
}