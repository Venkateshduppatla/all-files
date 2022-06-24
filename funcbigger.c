// Function to read two numbers and print bigger one.

#include <stdio.h>
int examineBiggerNumber(int *number1, int *number2)
{
	if(*number1 == *number2)
	{
		printf("%d is equal to %d.", number1, number2);
		return;
	}
	if(number1 < number2)
	{
		*number2 = *number1 + *number2;
		*number1 = *number2 - *number1;
		*number2 = *number2 - *number1;
	}
}