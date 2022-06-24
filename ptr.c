#include <stdio.h>
#include <stdlib.h>
int main()
{
	int marks[3];
	int *ptrMarks, *nMarks;
	ptrMarks = malloc(3 * sizeof(int));
	printf("Enter the marks of student-1: ");
	scanf("%d", &marks[0]);
	marks[0] + 1;
	printf("Enter the marks of student-2: ");
	scanf("%d", &marks[1]);
	printf("Enter the marks of student-3: ");
	scanf("%d", ptrMarks);
	nMarks = ptrMarks;
	ptrMarks++;
	printf("Enter the marks of student-4: ");
	scanf("%d", ptrMarks);
	printf("The marks are:\nStudent-1- %d\nStudent-2- %d\nStudent-3- %d\nStudent-4- %d", marks[0], marks[1], *nMarks, *ptrMarks);
}