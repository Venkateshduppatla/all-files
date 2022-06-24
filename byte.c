// Declare 2 long strings and read multistrings with using fflash().	

#include <stdio.h>
#include <stdlib.h>
#define STRING_LENGTH 10
void main()
{
	int stringCounter;
	char string1[STRING_LENGTH];
	char string2[STRING_LENGTH];
	for(stringCounter = 0; stringCounter < STRING_LENGTH; stringCounter++)
	{
		printf("%c : %d \n", string1[stringCounter], string1[stringCounter]);
	}
	for(stringCounter = 0; stringCounter < STRING_LENGTH; stringCounter++)
	{
		printf("%c : %d \n", string2[stringCounter], string2[stringCounter]);
	}
	printf("Enter the name-1: ");
	scanf("%s", string1);
	fflush(stdin);
	printf("Enter the name-2: ");
	fgets(string2, STRING_LENGTH, stdin);
	for(stringCounter = 0; stringCounter < STRING_LENGTH; stringCounter++)
	{
		printf("%c : %d \n", string1[stringCounter], string1[stringCounter]);
	}
	for(stringCounter = 0; stringCounter < STRING_LENGTH; stringCounter++)
	{
		printf("%c : %d \n", string2[stringCounter], string2[stringCounter]);
	}
}