// Frame Work Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mytools.c"
#define MAX_LENGTH 50
#define MENU "menu.cfg"
#define FIELD_NAMES "fields.cfg"
#define FIELD_VALUES "fieldrecords.dat"

int main()
{
	loadAndCountFields();
	showMenu();
}


// Function to show menu.

int showMenu()
{
	int choice;
	char menuLine[MAX_LENGTH];
	FILE *fpShowMenu;
	fpShowMenu = fopen(MENU, "r");
	do
	{	
		while (fgets(menuLine, MAX_LENGTH, fpShowMenu) != '\0')
		{
			printf("%s", menuLine);
		}
		rewind(fpShowMenu);
		scanf("%d", &choice);
		fflush(stdin);
		switch (choice)
		{
			case 1:
				createRecord();
				break;
			case 2:
				showRecord();
				break;
			case 3:
				searchRecord();
				break;
			/*case 4:
				updateRecord();
				break;
			case 5:
				deleteRecord();
				break;*/
			case 6:
				fclose(fpShowMenu);
				exit(0);
				break;
		}
	} while (choice != 6);
}

// _____________________________________________________________________
// Function to create a Record.

int createRecord()
{
	FILE *fpData;
	fpData = fopen(FIELD_VALUES, "a");
	FILE *fpFieldName;
	fpFieldName = fopen(FIELD_NAMES, "r");
	loadAndCountFields();
	char fieldName[MAX_LENGTH], fieldValue[MAX_LENGTH];
	while (fgets(fieldName, MAX_LENGTH, fpFieldName) != '\0')
	{
		removeNewLine(fieldName);
		printf("Enter the %s: ", fieldName);
		fgets(fieldValue, MAX_LENGTH, stdin);
		fwrite(fieldValue, MAX_LENGTH, 1, fpData);
	}
	fclose(fpData);
	fclose(fpFieldName);
}

//______________________________________________________________________
// Function to show Record.

int showRecord()
{
	FILE *fpFieldName;
	fpFieldName = fopen(FIELD_NAMES, "r");
	FILE *fpData;
	fpData = fopen(FIELD_VALUES, "r");
	char fieldName[MAX_LENGTH], fieldValue[MAX_LENGTH];
	int printStatus = 0;
	while (fread(fieldValue, MAX_LENGTH, 1, fpData) != '\0')
	{ 
		if (fgets(fieldName, MAX_LENGTH, fpFieldName) != '\0') 
		{
			removeNewLine(fieldName);
			printf("%s : %s", fieldName, fieldValue);
		}
		else
		{
			fseek(fpData, -(MAX_LENGTH + 3), SEEK_CUR);
			rewind(fpFieldName);
		}
		printStatus = 1;
	}
	if (printStatus == 0)
	{
		printf("No Records Found!\n");
	}
	printf("\n");
	fclose(fpData);
	fclose(fpFieldName);
}

//____________________________________________________________________
// Function to searh a record.

int searchRecord()
{
	FILE *fpFieldName;
	fpFieldName = fopen(FIELD_NAMES, "r");
	FILE *fpData;
	fpData = fopen(FIELD_VALUES, "r");
	char fieldName[MAX_LENGTH], fieldValue[MAX_LENGTH];
	char searchTerm[MAX_LENGTH];
	int comparedStrings = 0;
	fgets(fieldName, MAX_LENGTH, fpFieldName);
	removeNewLine(fieldName);
	printf("Enter the %s: ", fieldName);
	fgets(searchTerm, MAX_LENGTH, stdin);
	while (fread(fieldValue, MAX_LENGTH, 1, fpData) != '\0')
	{
		comparedStrings = strcmp(fieldValue, searchTerm);
		if (comparedStrings == 0)
		{
			if (fgets(fieldName, MAX_LENGTH, fpFieldName) != '\0') 
			{
				removeNewLine(fieldName);
				printf("%s : %s", fieldName, fieldValue);
			}
			else
			{
				fseek(fpData, -(MAX_LENGTH + 3), SEEK_CUR);
				rewind(fpFieldName);
			}
		}
		else
		{
			printf("Enter the  Correct Record!\n");
		}
	}
	fclose(fpData);
	fclose(fpFieldName);
}
//____________________________________________________________________________
// Function to count and load the field names.

int fieldsCount = 0;
char *fields = storeFields[fieldsCount]
loadAndCountFields()
{
	FILE *fpFieldName;
	fpFieldName = fopen(FIELD_NAMES, "r");
	char fieldName[MAX_LENGTH];
	while (fgets(fieldName, MAX_LENGTH, fpFieldName) != '\0')
	{
		fieldsCount++;
	}
	char storeFields[fieldsCount][MAX_LENGTH];
	int fieldCounter;
	rewind(fpFieldName);
	for (fieldCounter = 0; fieldCounter < fieldsCount; fieldCounter++)
	{
		fgets(storeFields[fieldCounter], MAX_LENGTH, fpFieldName);
	}
	for (fieldCounter = 0; fieldCounter < fieldsCount; fieldCounter++)
	{
		printf("%s",storeFields[fieldCounter]);
	}
	fclose(fpFieldName);
}