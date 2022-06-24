#include <stdio.h>
#include <string.h>

//Remove new line function.
removeNewLine(char *anyName)
{
	anyName[strlen(anyName) - 1] = '\0';
}

//Underline function

doUnderLine(char *string)
{
	int stringLength, counter;
	stringLength = printf("%s", string);
	printf("\n");
	for(counter = 0; counter < stringLength; counter++)
	{
		printf("_");
	}
}

// Compare function

compareStrings(char *firstString, char *secondString)
{
	int compare = 0, characterCounter = 0;
	while (firstString[characterCounter] !='\0' && secondString[characterCounter] != '\0')
	{
		if (firstString[characterCounter] != secondString[characterCounter])
		{
			compare = 1;
			break;
		}
		characterCounter++;
	}
	return compare;
}

int printCharacters(char *string)
{
	while(*string != '\0')
	{
		printf("%c\n", *string++);
	}
}