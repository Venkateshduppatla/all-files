#include <stdio.h>
#define NAME_LENGTH 5
#define NAMES_COUNT 2
int main()
{
	int namesCounter;
	char names[NAMES_COUNT] [NAME_LENGTH];
	for(namesCounter = 0; namesCounter < NAMES_COUNT; namesCounter++)
	{
		printf("Enter the name of the student-%d of %d: ", namesCounter + 1, NAMES_COUNT);
		scanf("%5s", names[namesCounter]);
	}
	for(namesCounter = 0; namesCounter < NAMES_COUNT; namesCounter++)
	{
		printf("The name of Student-%d is %s.\n", namesCounter + 1, names[namesCounter]);
	}
}