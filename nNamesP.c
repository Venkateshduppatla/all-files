//Read and print k names without using pointers

#include <stdio.h>
void main()
{
	int namesCounter, namesCount;
	printf("To read names of students. \n");
	printf("How many names of students should be read and print? ");
	scanf("%d", &namesCount);
	char names[namesCount][15];
	char *allNames = names[namesCount];
	printf("Enter the names of students: \n");
	for(namesCounter = 0; namesCounter < namesCount; namesCounter++)
	{
		printf("The name of the student-%d of %d: ", namesCounter + 1);
		scanf("%s", names[namesCounter]);
		allNames++;
	}
	printf("\nNames of the students are: \n");
	for(namesCounter = 0; namesCounter < namesCount; namesCounter++)
	{
		printf("The name of the Student-%d is %s.\n", namesCounter + 1, names[namesCounter]);
	}
} 