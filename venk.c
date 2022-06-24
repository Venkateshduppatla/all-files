// Cruds Framework Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mytools.c"
#define MAX_LENGTH 50
#define MENU "menu.cfg"
#define FIELD_NAMES "fields.cfg"
#define FIELD_VALUES "framework.dat"
char **fieldNames;
int fieldsCount, fieldsCounter;

//________________________________________________________________
// Function to count and load lines. 

char **loadLines(char *fileName)
{
    char **lines, line[MAX_LENGTH];
    int linesCount = 0, linesCounter;
    FILE *fpLines;
    fpLines = fopen(fileName, "r");
    while (fgets(line, MAX_LENGTH, fpLines) != '\0')
    {
        linesCount++;
    }
    lines = malloc((linesCount + 1) * sizeof(char*));
    lines[0] = malloc(MAX_LENGTH);
    itoa(linesCount, lines[0], 10);
    rewind(fpLines);
    for (linesCounter = 1; linesCounter <= linesCount; linesCounter++)
    {
        lines[linesCounter] = malloc(MAX_LENGTH);
        fgets(lines[linesCounter], MAX_LENGTH, fpLines);
    }
    fclose(fpLines);
    return lines;
}

//_____________________________________________________________________
// Main Function.

main()
{
    fieldNames = loadLines(FIELD_NAMES);
    fieldsCount = atoi(fieldNames[0]);
    for (fieldsCounter = 1; fieldsCounter <= fieldsCount; fieldsCounter++)
    {
        removeNewLine(fieldNames[fieldsCounter]);
    }
    showMenu();
}

//____________________________________________________________________
//Function to show menu. 

int showMenu()
{
    int choice, linesCounter, linesCount;
    char **menuLines;
    menuLines = loadLines(MENU);
    linesCount = atoi(menuLines[0]);
    do
    {
        for (linesCounter = 1; linesCounter <= linesCount; linesCounter++)
        {
            printf("%s", menuLines[linesCounter]);
        }
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice)
        {
            case 1:
                createRecord();
                break;
            case 2:
                showRecords();
                break;
            case 3:
                searchRecord();
                break;
            case 4:
                exit(0);
            default:
                printf("Enter the Correct Choice!\n");

        }
    } while (choice != 3);
}

//____________________________________________________________________
// Function to create a new Record. 

int createRecord()
{
    FILE *fpData;
    fpData = fopen(FIELD_VALUES, "a");
    char fieldValue[MAX_LENGTH];
    fieldsCount = atoi(fieldNames[0]);
    for (fieldsCounter = 1; fieldsCounter <= fieldsCount; fieldsCounter++)
    {
        printf("Enter the %s: ", fieldNames[fieldsCounter]);
        fgets(fieldValue, MAX_LENGTH, stdin);
        fwrite(fieldValue, MAX_LENGTH, 1, fpData);
    }
    printf("\n");
    fclose(fpData);
}

//___________________________________________________________________________
// Function to display the records.

/*int showRecords()
{

    FILE *fpData;
    fpData = fopen(FIELD_VALUES, "r");
    char fieldValue[MAX_LENGTH];
    fieldsCount = atoi(fieldNames[0]);
    int printStatus = 0;
    for (fieldsCounter = 1; fread(fieldValue, MAX_LENGTH, 1, fpData) != '\0'; fieldsCounter++)
    {
        printf("%s: %s", fieldNames[fieldsCounter], fieldValue);
        if (fieldsCounter == fieldsCount)
        {
            fieldsCounter = 0;
            printf("\n");
        }
        printStatus = 1;
    }
    if (printStatus == 0)
    {
        printf("No Records Found!\n");
    }
    fclose(fpData);
}
*/
//_______________________________________________________________________
// Function to search a record. 

int searchRecord()
{
    FILE *fpData;
    fpData = fopen(FIELD_VALUES, "r");
    char fieldValue[MAX_LENGTH];
    char searchTerm[MAX_LENGTH];
    fieldNames = loadLines(FIELD_NAMES);
    fieldsCount = atoi(fieldNames[0]);
    int comparedStrings = 0, printStatus = 0;
    removeNewLine(fieldNames[1]);
    printf("Enter the %s: ", fieldNames[1]);
    fgets(searchTerm, MAX_LENGTH, stdin);
    while (fread(fieldValue, MAX_LENGTH, 1, fpData) != '\0')
    {
        comparedStrings = strcmp(fieldValue, searchTerm);
        if (comparedStrings == 0)
        {
            printf("\n");
            for(fieldsCounter = 1; fieldsCounter <= fieldsCount; fieldsCounter++)
            {
                removeNewLine(fieldNames[fieldsCounter]);
                printf("%s : %s", fieldNames[fieldsCounter], fieldValue);
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

// Function to show records.

/*int showRecords()
{
    FILE *fpData;
    fpData = fopen(FIELD_VALUES, "r");
    char fieldValue[MAX_LENGTH];
    fieldsCount = atoi(fieldNames[0]);
    int printStatus = 0;
    while (fread(fieldValue, MAX_LENGTH, 1, fpData) != '\0')
    { 
        for(fieldsCounter = 1; fieldsCounter <= fieldsCount; fieldsCounter++)
        {
            printf("%s : %s", fieldNames[fieldsCounter], fieldValue);
            fread(fieldValue, MAX_LENGTH, 1, fpData);
        }
        printf("\n");
        if (fread(fieldValue, MAX_LENGTH, 1, fpData) != '\0')
        {
            fseek(fpData, -2 *(MAX_LENGTH + 1), SEEK_CUR);
        }
        printStatus = 1;
    }
    if (printStatus != 1)
    {
        printf("No Records Found!\n");
    }
    printf("\n");
    fclose(fpData);
}*/

int showRecords()
{

    FILE *fpData;
    fpData = fopen(FIELD_VALUES, "r");
    char fieldValue[MAX_LENGTH];
    fieldsCount = atoi(fieldNames[0]);
    int printStatus = 0;
    for (fieldsCounter = 1; fieldsCounter <= fieldsCount; fieldsCounter++)
    {
        if (fread(fieldValue, MAX_LENGTH, 1, fpData) != '\0')
        {
            printf("%s: %s", fieldNames[fieldsCounter], fieldValue);
            if (fieldsCounter == fieldsCount)
            {
                printf("\n");
                fieldsCounter = 0;
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

