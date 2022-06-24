//Read and print 4  names 

#include <stdio.h>
#define COUNT 4
void main()
{
	int counter;
	char names[COUNT][15];
	printf("To read names of students. \n");
	printf("Enter the names of students: \n");
	for(counter = 0; counter < COUNT; counter++)
	{
		printf("The name of the student-%d: ",counter + 1);
		scanf("%s", names[counter]);
	}
	printf("\nNames of the students are: \n");
	for(counter = 0; counter < COUNT; counter++)
	{
		printf("The name of the Student-%d is %s.\n", counter + 1, names[counter]);
	}
}
