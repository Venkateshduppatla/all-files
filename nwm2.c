//To Print n names along with thier marks using only one pointer.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_LENGTH 20
int main()
{
	int studentsCount, studentsCounter, totalMarks;
	printf("Enter the number of students details do you want to read and print: ");
	scanf("%d", &studentsCount);
	char *names;
	names = malloc(studentsCount * NAME_LENGTH);
	int marks[studentsCount];
	printf("Enter the total marks of students: ");
	scanf("%d", &totalMarks);
	fflush(stdin);
	for(studentsCounter = 0; studentsCounter < studentsCount; studentsCounter++)
	{
		printf("Enter the name of the student-%d of %d: ", studentsCounter + 1, studentsCount);
		fgets(names + (NAME_LENGTH * studentsCounter), NAME_LENGTH, stdin);
		removeNewLine(names + (NAME_LENGTH * studentsCounter));
		printf("Enter the marks  of %s: ", (names + (NAME_LENGTH * studentsCounter)));
		scanf("%d", &marks[studentsCounter]);
		fflush(stdin);
	}
	printf("\n");
	for(studentsCounter = 0; studentsCounter < studentsCount; studentsCounter++)
	{
		printf("The marks of %s are %d out of %d.\n", names + (NAME_LENGTH * studentsCounter), marks[studentsCounter], totalMarks);
	}
}
removeNewLine(char *anyName)
{
	anyName[strlen(anyName) - 1] = '\0';
}