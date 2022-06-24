// Program to save multiple names.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mytools.c"
#define NAMES "names.dat"
#define MAX_LENGTH 30
struct node
{
	char name[MAX_LENGTH];
	struct node *nextNode;
};
struct node *start;

void main()
{
	writeNames();
	loadList();
	showMenu();
}

// Function to write names into file for test case.

int writeNames()
{
	FILE *fpNames;
	fpNames = fopen(NAMES, "w");
	char names[MAX_LENGTH][5];
	int counter;
	for (counter = 0; counter < 5; counter++)
	{	
		printf("Enter the Names: ");
		fgets(names[counter], MAX_LENGTH, stdin);
		removeNewLine(names[counter]);
		fwrite(names[counter], MAX_LENGTH, 1, fpNames);
		fclose(fpNames);
	}
}

int loadList()
{
	struct node *head, *newNode, *tempNode;
	char names[MAX_LENGTH];
	FILE *fpNames;
	fpNames = fopen(NAMES, "r");
	tempNode = start;
	while (fread(names, sizeof(names), 1, fpNames) != '\0')
	{
		if (tempNode == '\0')
		{
			tempNode = (struct node*)malloc(sizeof(struct node));
			strcpy(tempNode -> name, name);
			tempNode -> nextNode = '\0';
			start = tempNode;
		}
		else
		{
			while (tempNode -> nextNode != '\0')
			{
				tempNode = tempNode -> nextNode;
			}
			newNode = (struct node*)malloc(sizeof(struct node));
			strcpy(newNode -> nextNode = newNode);
		}
	}
	//printf("%s", newNode);
	fclose(fpNames);
}


// Save the names into the file. 

saveNames()
{
	FILE *fpNames;
	fpNames = fopen(NAMES, "w");
	while (tempNode != '\0')
	{
		fwrite(tempNode, sizeof(struct node), 1, fpNames);
		tempNode = tempNode -> nextNode;
	}
	fclose(fpNames);
}

// Function to show the menu.

int showMenu()
{
	int choice;
	do
	{
		printf("1. Load the Name into the list.\n2. Show All Names.\n3. Sort Alphabetically and Save Names\n4. Sort Alphabetically and Show Names\n5. Exit.");
		printf("\nEnter the choice: ");
		scanf("%d", &choice);
		fflush(stdin);
		switch (choice)
		{
			case 1:
				loadName();
				break;
			case 2:
				showAllNames();
				break;
			/*case 3:
				sortAndSaveNames();
				break;
			case 4:
				sortAndShowNames();
				break;*/
			case 5:
				exit(0);
				break;
			default:
				printf("\nEnter the Correct Choice!");
				break;
		}
	} while (choice != 5);
}

//___________________________________________________________________________________________
// Function to Load namesinto the list.

int loadName()
{
	struct node *newNode, *tempNode;
	char name[MAX_LENGTH];
	newNode = (struct node*)malloc(sizeof(struct node));
	printf("Enter the Name: ");
	fgets(name, MAX_LENGTH, stdin);
	removeNewLine(name);
	strcpy(newNode -> name, name);
	newNode -> nextName = '\0';
	if (start == '\0')
	{
		start = tempNode;
	}
	else
	{
		tempNode -> nextName = newNode;
		tempNode = newNode;
		//printf("%s", tempNode);
	}
}

//__________________________________________________________
//Function to show all the names.

int showAllNames()
{
	
	struct node *newNode, *tempNode;
	tempNode = start;
	char name[MAX_LENGTH];
	printf("\n\nNames are:\n");
	while (tempNode != '\0')
	{
		printf("%s\n", tempNode);
		tempNode = tempNode -> nextNode;
	}
}

//________________________________________________________________
// Function to save the name.
int saveName()
{
	char *name;
	FILE *fpNames;
	fpNames = fopen(NAMES, "a");
	printf("\nEnter the Name: ");
	fgets(name, MAX_LENGTH, stdin);
	removeNewLine(name);
	fwrite(name, MAX_LENGTH, 1, fpNames);
	fclose(fpNames);
}

//________________________________________________
// Function to sort and save the names.

int sortAndSaveNames()
{
	
}


int writeNames()
{
	FILE *fpNames;
	fpNames = fopen(NAMES, "w");
	char names[MAX_LENGTH][5];
	int counter;
	for (counter = 0; counter < 5; counter++)
	{	
		printf("Enter the Names: ");
		fgets(names[counter], MAX_LENGTH, stdin);
		removeNewLine(names[counter]);
		fwrite(names[counter], MAX_LENGTH, 1, fpNames);
		fclose(fpNames);
	}
}

