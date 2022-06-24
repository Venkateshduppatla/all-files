// To read and print k marks of students using pointers with index. 

#include <stdio.h>
#include <stdlib.h>
int main()
{
	//int *marks;
	int marksCount, marksCounter, allMarks;
	printf("Enter the number of student marks: ");
	scanf("%d", &marksCount);
	int marks[marksCount];
	//marks = malloc(marksCount * sizeof(int));
	printf("Enter the total marks of exams conducted: ");
	scanf("%d", &allMarks);
	printf("To read the marks of students.\n");
	printf("Enter the marks of students: \n");
	for(marksCounter = 0; marksCounter < marksCount; marksCounter++)
	{
		printf("The marks of Student-%d of %d: ", marksCounter + 1, marksCount);
		scanf("%d", &marks[marksCounter]);
	}
	printf("\nMarks of the students are: \n");
	for(marksCounter = 0; marksCounter < marksCount; marksCounter++)
	{
		printf("The marks of the student-%d: %d out of %d.\n", marksCounter + 1, marks[marksCounter], allMarks);
	}
}