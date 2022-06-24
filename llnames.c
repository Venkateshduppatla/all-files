// Program to save multiple names.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mytools.c"
#define NAMES "llname.dat"
#define MAX_LENGTH 30
struct node
{
	char name[MAX_LENGTH];
	struct node *nextNode;
};
struct node *start;

//___________________________________________________
// Function to load names into the linked list.

int loadList()
{
	struct node *newNode, *tempNode;
	char names[MAX_LENGTH];
	FILE *fpNames;
	fpNames = fopen(NAMES, "r");
	tempNode = start;
	while (fgets(names, sizeof(names), fpNames) != '\0')
	{
		if (tempNode == '\0')
		{
			tempNode = (struct node*)malloc(sizeof(struct node));
			strcpy(tempNode -> name, names);
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
			strcpy(newNode -> name, names);
			newNode -> nextNode = '\0';
			tempNode -> nextNode = newNode;
		}
	}
	fclose(fpNames);
}

//_______________________________________________________
// Save the names into the file. 

saveNames()
{
	struct node *tempNode;
	char names[MAX_LENGTH];
	FILE *fpNames;
	fpNames = fopen(NAMES, "w");
	while (tempNode != '\0')
	{
		fwrite(names, sizeof(names), 1, fpNames);
		tempNode = tempNode -> nextNode;
	}
	fclose(fpNames);
}

//____________________________________________________
// Function to show the menu.

int showMenu()
{
	int choice;
	do
	{
		printf("\n1. Load the Name into the list.\n2. Show All Names.\n3. Search for a Name.\n4. Update a Name.\n5. Sort all Names.\n6. Exit.");
		printf("\nEnter the choice: ");
		scanf("%d", &choice);
		fflush(stdin);
		switch (choice)
		{
			case 1:
				loadName();
				saveNames();
				break;
			case 2:
				showAllNames();
				break;
			case 3:
				searchName();
				break;
			case 4:
				updateName();
				break;
			case 5:
				sortNames();
				break;
			case 6:
				exit(0);
				break;
			default:
				printf("\nEnter the Correct Choice!");
				break;
		}
	} while (choice != 6);
}

//____________________________________________________________-
// Main Function.

int main()
{
	//writeNames();
	loadList();
	showMenu();
}


//__________________________________________________________
//Function to show all the names.

int showAllNames()
{
	
	struct node *tempNode;
	tempNode = start;
	if (start == '\0')
	{
		printf("\nNo Names Found!\n");
	}
	else
	{
		printf("\nNames are:\n\n");
		while (tempNode != '\0')
		{
			printf("%s", tempNode -> name);
			tempNode = tempNode -> nextNode;
		}
	}
}

//_________________________________________________
// Function to load name into Linked List. 

int loadName()
{
	struct node *newNode, *tempNode;
	tempNode = (struct node*) malloc(sizeof(struct node));
	char nextName[MAX_LENGTH];
	printf("Enter the name: ");
	fgets(nextName, MAX_LENGTH, stdin);
	tempNode = start;
	if (tempNode == '\0')
	{
		strcpy(newNode -> name, nextName);
		newNode -> nextNode = '\0';
		start = newNode;
		printf("%s\n", nextName);
	}
	else
	{
		while (tempNode -> nextNode != '\0')
		{
			tempNode = tempNode -> nextNode;
		}
		strcpy(newNode -> name, nextName);
		newNode -> nextNode = '\0';
		tempNode -> nextNode = newNode;
	}
}
	
//____________________________________________________
// Function to search a name.

int searchName()
{
	struct node *tempNode;
	char nameSearched[MAX_LENGTH];
	int status = 0;
	tempNode = start;

}

//_________________________________________________
// Function to update a name.

int updateName()
{

}

//__________________________________________________
// Function to sort all the names. 

int sortNames()
{
	
}