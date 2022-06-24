// To read and print k marks of students using pointers with increment

#include <stdio.h>
#include <stdlib.h>
int main()
{
	int *marks, *storeMarks;
	int marksCount, marksCounter;
	printf("Enter the number of student marks: ");
	scanf("%d", &marksCount);
	marks = malloc(marksCount * sizeof(int));
	printf("To read the marks of students.\n");
	printf("Enter the marks of students: \n");
	storeMarks = marks;
	for(marksCounter = 0; marksCounter < marksCount; marksCounter++)
		{
		printf("The marks of Student-%d of %d: ", marksCounter + 1, marksCount);
		scanf("%d", storeMarks + marksCounter);
		}
	printf("\nMarks of the students are: \n");
	//storeMarks = marks;
	for(marksCounter = 0; marksCounter < marksCount; marksCounter++)
	{
		printf("The marks of the student-%d: %d \n", marksCounter + 1, *(marks + marksCounter));
	}
}