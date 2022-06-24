//To read and save names into a file and priting the output.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_LENGTH 30
#define NAMES_FILE "names.dat"
int main()
{
	int choice;
	do
	{
		showMenu();
		
	} while (choice != 4);	
}
showMenu()
{
	int choice;
	printf("\n1. Save the name.\n2. Show the names.\n3. Clear Names.\n4. Exit.\n\nEnter your Choice: ");
	scanf("%d", &choice);
	printf("\n");
	fflush(stdin);
	switch (choice)
		{
			case 1:
				saveNames();
				break;
			case 2:
				showNames();
				break;
			case 3:
				clearNames();
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("Enter the correct choice.\n");
				break;
		}
}
// Function to save a name.

saveNames()
{
	char name[NAME_LENGTH];
	FILE *fpNames;
	fpNames = fopen(NAMES_FILE, "a");
	printf("Enter the name: ");
	fgets(name, NAME_LENGTH, stdin);
	removeNewLine(name);
	fprintf(fpNames, "%s\n", name);
	fclose(fpNames);
}
// Function to remove a new line.

removeNewLine(char *anyName)
{
	anyName[strlen(anyName) - 1] = '\0';
}
// Function to show the names.

showNames()
{
	int choice;
	char name[NAME_LENGTH];
	FILE *fpNames;
	fpNames = fopen(NAMES_FILE, "r");
	if (fpNames == '\0')
	{
		printf("No Records found.\n");
	}
	else 
	{
		printf("The names found in the records are: \n");
		while (fgets(name, NAME_LENGTH, fpNames) != '\0')
			{
				printf("%s", name);
			}
	}
	fclose(fpNames);
}
// Function to clear all the names. 

clearNames()
{
	FILE *manyNames;
	manyNames = fopen(NAMES_FILE, "w");
	fclose(manyNames);
}
