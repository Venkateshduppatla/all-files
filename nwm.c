// To read and print names of a student and total marks for each.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_LENGTH 20
int main()
{
	int studentDataCount, namesCounter;
	printf("Enter the number of names do you want to read and print: ");
	scanf("%d", &studentDataCount);
	char *names;
	names = malloc(studentDataCount * NAME_LENGTH);
	fflush(stdin);
	for(namesCounter = 0; namesCounter < studentDataCount; namesCounter++)
	{
		printf("Enter the name of the student-%d of %d: ", namesCounter + 1, studentDataCount);
		fgets(names + (NAME_LENGTH * namesCounter), NAME_LENGTH, stdin);
		removeNewLine(names + (NAME_LENGTH * namesCounter));
	}
	int marksCounter, totalMarks;
	int marks[studentDataCount];
	printf("Enter the total marks of Students: ");
	scanf("%d", &totalMarks);
	for(namesCounter = 0; namesCounter < studentDataCount; namesCounter++)
	{
		printf("Enter the marks obtained by %s: ", names + (NAME_LENGTH * namesCounter));
		for(marksCounter = 0; marksCounter < (namesCounter + 1); marksCounter++)
		{
			scanf("%d", marks[marksCounter]);
		}
	}
	for(namesCounter = 0; namesCounter < studentDataCount; namesCounter++)
	{
		printf("Enter the total marks of %s: ", names + (NAME_LENGTH * namesCounter));
		for(marksCounter = 0; marksCounter < studentDataCount; marksCounter++)
		{
			printf("The marks of %s are %d out of total marks.\n", names + (NAME_LENGTH * namesCounter), marks[marksCounter]);
		}
	}	
}
removeNewLine(char *anyName)
{
	anyName[strlen(anyName) - 1] = '\0';
}