// Read and print the elements into the array. 

#include <stdio.h>
#define COUNT 3
void main()
{
	int marks[COUNT];
	int counter;
	printf("To read the marks of students.\n");
	printf("Enter the marks of students: \n");
	for(counter = 0; counter < COUNT; counter++)
	{
		printf("The marks of Student - %d: ", counter + 1);
		scanf("%d", &marks[counter]);
	}
	printf("\n Marks of the students are: \n");
	for(counter = 0; counter < COUNT; counter++)
	{
		printf("The marks of the student - %d: %d \n", counter + 1, marks[counter]);
		puts(usr);
	}
	printf("\n");
}