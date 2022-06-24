//To print names and marks of students using structures.

#include <stdio.h>
#include <string.h>
#define NAME_LENGTH 20
int main()
{
	int studentCounter, studentsCount, totalMarks;
	printf("How many students are there in a class? ");
	scanf("%d", &studentsCount);
	printf("Enter the total marks for the exam conducted: ");
	scanf("%d", &totalMarks);
	fflush(stdin);
	struct studentsData
	{
		char name[NAME_LENGTH];
		int rollNumber, marks;
	}student[studentsCount];
	for(studentCounter = 0; studentCounter < studentsCount; studentCounter++)
	{
		printf("Enter the roll number of a student: ");
		scanf("%d", &student[studentCounter].rollNumber);
		fflush(stdin);
		printf("Enter the name of the student with roll number-%d: ", student[studentCounter].rollNumber);
		fgets(student[studentCounter].name, NAME_LENGTH, stdin);
		removeNewLine(student[studentCounter].name);
		printf("Enter the marks of %s who is with roll number-%d: ", student[studentCounter].name, student[studentCounter].rollNumber);
		scanf("%d", &student[studentCounter].marks);
		fflush(stdin);
		printf("\n");
	}
	printf("\n\n");
	printf("The Data contains roll numbers, names and marks of the Students: \n");
	for(studentCounter = 0; studentCounter < studentsCount; studentCounter++)
	{
		printf("The student with roll number-%d is %s and he got %d out of %d marks.\n", student[studentCounter].rollNumber, student[studentCounter].name, student[studentCounter].marks, totalMarks);
	}
}
int removeNewLine(char *anyName)
{
	anyName[strlen(anyName) - 1] = '\0';
}