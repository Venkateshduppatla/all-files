// Frame Work Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mytools.c"
#define MAX_LENGTH 50
#define MENU "menu.cfg"
#define FIELD_NAMES "fields.cfg"
#define FIELD_VALUES "fieldrecords.dat"
char **storedFields;
char **storedMenuLines;
char **lines;
int fieldsCount, fieldsCounter, linesCount, linesCounter;
int main()
{
	//countAndLoadFields();
	loadMenu();
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
			case 4:
				updateRecord();
				break;
			case 5:
				deleteRecord();
				break;
			case 6:
				fclose(fpShowMenu);
				exit(0);
				break;
		}
	} while (choice != 6);
}

//_________________________________________________________________________
// Function to count and load the fileds into an array. 

int loadMenu()
{
	char menuLine[MAX_LENGTH];
	FILE *fpShowMenu;
	fpShowMenu = fopen(MENU, "r");
	while (fgets(menuLine, MAX_LENGTH, fpShowMenu) != '\0')
	{
		linesCount++;
	}
	storedMenuLines = malloc(linesCount * sizeof(char*));
	rewind(fpShowMenu);
	for (linesCounter = 0; linesCounter < linesCount; linesCounter++)
	{
		storedMenuLines[linesCounter] = malloc(MAX_LENGTH);
		fgets(storedMenuLines[linesCounter], MAX_LENGTH, fpShowMenu);
	}
	for (linesCounter = 0; linesCounter < linesCount; linesCounter++)
	{
		printf("%s", storedMenuLines[linesCounter]);
	}
	fclose(fpShowMenu);
}

//_________________________________________________________________________
// Function to count and load the fileds into an array. 

/*int countAndLoadFields()
{
	char fieldName[MAX_LENGTH];
	FILE *fpFieldNames;
	fpFieldNames = fopen(FIELD_NAMES, "r");
	while (fgets(fieldName, MAX_LENGTH, fpFieldNames) != '\0')
	{
		fieldsCount++;
	}
	storedFields = malloc(fieldsCount);
	rewind(fpFieldNames);
	for (fieldsCounter = 0; fieldsCounter < fieldsCount; fieldsCounter++)
	{
		storedFields[fieldsCounter] = malloc(MAX_LENGTH);
		fgets(storedFields[fieldsCounter], MAX_LENGTH, fpFieldNames);
		removeNewLine(storedFields[fieldsCounter]);
	}*/
	/*for (fieldsCounter = 0; fieldsCounter < fieldsCount; fieldsCounter++)
	{
		printf("%s",storedFields[fieldsCounter]);
	}
	fclose(fpFieldNames);*/
//}

//_________________________________________________________________
// Function to Load the lines. 

char **loadLines(char *FILE_NAME)
{
	char line[MAX_LENGTH];
	FILE *fpLines;
	fpLines = fopen(FILE_NAME, "r");
	while (fgets(line, MAX_LENGTH, fpLines) != '\0')
	{
		linesCount++;
	}
	//lines[linesCounter] = linesCount;
	lines = malloc(linesCount * sizeof(char*));
	rewind(fpLines);
	for (linesCounter = 0; linesCounter < linesCount; linesCounter++)
	{
		lines[linesCounter] = malloc(MAX_LENGTH);
		fgets(lines[linesCounter], MAX_LENGTH, fpLines);
	}
	for (linesCounter = 0; linesCounter < linesCount; linesCounter++)
	{
		printf("%s", lines[linesCounter]);
	}
	return lines;
	fclose(fpLines);
}

// _____________________________________________________________________
// Function to create a Record.

int createRecord()
{
	FILE *fpData;
	fpData = fopen(FIELD_VALUES, "a");
	storedFields = loadLines(FIELD_NAMES);
	char fieldValue[MAX_LENGTH];
	for(fieldsCounter = 0; fieldsCounter < linesCount; fieldsCounter++)
	{

		printf("Enter the %s: ", storedFields[fieldsCounter]);
		fgets(fieldValue, MAX_LENGTH, stdin);
		fwrite(fieldValue, MAX_LENGTH, 1, fpData);
	}
	fclose(fpData);
}

//______________________________________________________________________
// Function to show Record.

int showRecord()
{	
	FILE *fpData;
	fpData = fopen(FIELD_VALUES, "r");
	char fieldValue[MAX_LENGTH];
	int printStatus = 0;
	while (fread(fieldValue, MAX_LENGTH, 1, fpData) != '\0')
	{ 
		for(fieldsCounter = 0; fieldsCounter < fieldsCount; fieldsCounter++)
		{
			printf("%s : %s", storedFields[fieldsCounter], fieldValue);
			fread(fieldValue, MAX_LENGTH, 1, fpData);
		}
		if (fread(fieldValue, MAX_LENGTH, 1, fpData) != '\0')
		{
			fseek(fpData, -2 *(MAX_LENGTH + 1), SEEK_CUR);
		}
		printStatus = 1;
	}
	if (printStatus == 0)
	{
		printf("No Records Found!\n");
	}
	printf("\n");
	fclose(fpData);
}

//____________________________________________________________________
// Function to searh a record.

int searchRecord()
{
	
	FILE *fpData;
	fpData = fopen(FIELD_VALUES, "r");
	char fieldValue[MAX_LENGTH];
	char searchTerm[MAX_LENGTH];
	int comparedStrings = 0, printStatus = 0;
	printf("Enter the %s: ", storedFields[0]);
	fgets(searchTerm, MAX_LENGTH, stdin);
	while (fread(fieldValue, MAX_LENGTH, 1, fpData) != '\0')
	{
		comparedStrings = strcmp(fieldValue, searchTerm);
		if (comparedStrings == 0)
		{
			printf("\n");
			for(fieldsCounter = 0; fieldsCounter < fieldsCount; fieldsCounter++)
			{
				printf("%s : %s", storedFields[fieldsCounter], fieldValue);
				fread(fieldValue, MAX_LENGTH, 1, fpData);
			}
			if (fread(fieldValue, MAX_LENGTH, 1, fpData) != '\0')
			{
				fseek(fpData, -2 *(MAX_LENGTH + 1), SEEK_CUR);
			}
		printStatus = 1;
		}
	}	
	if (printStatus == 0)
	{
		printf("No Records Found!\n");
	}
	fclose(fpData);
}

//____________________________________________________________________________
// Function search and update a record.

int updateRecord()
{
	FILE *fpData;
	fpData = fopen(FIELD_VALUES, "r");
	char fieldValue[MAX_LENGTH];
	char searchTerm[MAX_LENGTH];
	int comparedStrings = 0, printStatus = 0;
	printf("Enter the %s: ", storedFields[0]);
	fgets(searchTerm, MAX_LENGTH, stdin);
	while (fread(fieldValue, MAX_LENGTH, 1, fpData) != '\0')
	{
		comparedStrings = strcmp(fieldValue, searchTerm);
		if (comparedStrings == 0)
		{
			for(fieldsCounter = 1; fieldsCounter < fieldsCount; fieldsCounter++)
			{

				printf("Enter the %s: ", storedFields[fieldsCounter]);
				fgets(fieldValue, MAX_LENGTH, stdin);
				fwrite(fieldValue, MAX_LENGTH, 1, fpData);
			}
		}
	}
	if (comparedStrings != 0)
	{
		printf("No Records Found or Enter the correct record!");
	}
	printf("Record Updated!\n");
	fclose(fpData);	
}

//___________________________________________________________________________
// Function to Delete Reccord.

int deleteRecord()
{

}

	
/*int showRecord()
{	
	FILE *fpData;
	fpData = fopen(FIELD_VALUES, "r");
	char fieldValue[MAX_LENGTH];
	int printStatus = 0;
	while (fread(fieldValue, MAX_LENGTH, 1, fpData) != '\0')
	{ 
		//while (fgets(storedFields, MAX_LENGTH ));
		for(fieldsCounter = 0; fieldsCounter < fieldsCount; fieldsCounter++)
		{
			//removeNewLine(fieldName);
			printf("%s : %s", storedFields[fieldsCounter], fieldValue);
			fread(fieldValue, MAX_LENGTH, 1, fpData);
		
		
		if (fieldsCounter == fieldsCount)
		{
			fseek(fpData, -(MAX_LENGTH + 1), SEEK_CUR);
		}}
		printStatus = 1;
	}
	if (printStatus == 0)
	{
		printf("No Records Found!\n");
	}
	printf("\n");
	fclose(fpData);
}*/