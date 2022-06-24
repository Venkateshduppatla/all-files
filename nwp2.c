//To read and print n names using pointers.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRING_LENGTH 15
int main()
{
	int namesCounter, namesCount;
	printf("Enter the number of names do you want to read and print: ");
	scanf("%d", &namesCount);
	fflush(stdin);
	char **names;
	names = malloc(namesCount * sizeof(int));
	for(namesCounter = 0; namesCounter < namesCount; namesCounter++)
	{
		names[namesCounter] = malloc(STRING_LENGTH);
		printf("Enter the name of the student-%d of %d: ", namesCounter + 1, namesCount);
		fgets(names[namesCounter], STRING_LENGTH, stdin);
		removeNewLine(names[namesCounter]);
	}
	printf("\nNames of the Students are: \n");
	for(namesCounter = 0; namesCounter < namesCount; namesCounter++)
	{
		printf("The Name of the Student-%d is %s.\n", namesCounter + 1, names[namesCounter]);
	}
}
int removeNewLine(char *aString)
{
	aString[strlen(aString) - 1] = '\0';
}