//To Print n names using only one pointer.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_LENGTH 20
int main()
{
	int namesCount, namesCounter;
	printf("Enter the number of names do you want to read and print: ");
	scanf("%d", &namesCount);
	char *names;
	names = malloc(namesCount * NAME_LENGTH);
	fflush(stdin);
	for(namesCounter = 0; namesCounter < namesCount; namesCounter++)
	{
		printf("Enter the name of the student-%d of %d: ", namesCounter + 1, namesCount);
		fgets(names + (NAME_LENGTH * namesCounter), NAME_LENGTH, stdin);
		removeNewLine(names + (NAME_LENGTH * namesCounter));
	}
	printf("\n");
	for(namesCounter = 0; namesCounter < namesCount; namesCounter++)
	{
		printf("The name of the student-%d is %s.\n", namesCounter + 1, names +(NAME_LENGTH * namesCounter));
		printf("                             -----------\n");
	}
}
removeNewLine(char *anyName)
{
	anyName[strlen(anyName) - 1] = '\0';
}