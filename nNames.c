//Read and print k names without using pointers

#include <stdio.h>
void main()
{
	int counter, count;
	printf("To read names of students. \n");
	printf("How many names of students should be read and print? ");
	scanf("%d", &count);
	char names[count][15];
	printf("Enter the names of students: \n");
	for(counter = 0; counter < count; counter++)
	{
		printf("The name of the student-%d: ",counter + 1);
		scanf("%s", &names[counter]);
	}
	printf("\nNames of the students are: \n");
	for(counter = 0; counter < count; counter++)
	{
		printf("The name of the Student-%d is %s.\n", counter + 1, names[counter]);
	}
}