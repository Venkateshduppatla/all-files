//To read and print n names which consumes only 200 bytes.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRING_LENGTH 15
int main()
{
	int namesCounter, namesCount;
	printf("How many names do you need to read and print? ");
	scanf("%d", &namesCount);
	fflush(stdin);
	char *names;
	names = malloc(namesCount * STRING_LENGTH * sizeof(char));
	for(namesCounter = 0; namesCounter < namesCount; namesCounter++)
	{
		printf("Enter the name of Student-%d of %d: ", namesCounter + 1, namesCount);
		fgets(names + (STRING_LENGTH * namesCounter), STRING_LENGTH, stdin);
		removeNewLine(names + (STRING_LENGTH * namesCounter));
	}
	printf("\n");
	for(namesCounter = 0; namesCounter < namesCount; namesCounter++)
	{
		printf("The name of the student-%d is %s.\n", namesCounter + 1, (names + (STRING_LENGTH * namesCounter)));
		makeUnderLine(names +(STRING_LENGTH * namesCounter))
	}
}
int removeNewLine(char *aString)
{
	aString[strlen(aString) - 1] = '\0';
}
void