// Read two numbers and print the bigger one

#include <stdio.h>
void main()
{
	int number1, number2;
	printf("Enter two numbers to print the bigger one: ");
	scanf("%d%d", &number1, &number2);
	if(number1 == number2)
	{
		printf("%d is equal to %d.", number1, number2);
		return;
	}
	if(number1 < number2)
	{
		number2 = number1 + number2;
		number1 = number2 - number1;
		number2 = number2 - number1;
	}
	printf("%d is larger than %d.", number1, number2);
}