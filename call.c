// Calling a function from main()

#include <stdio.h>
int add(int number1, int number2);
void main()
{
	int sum, number1, number2;
	printf("Enter the two number: ");
	scanf("%d%d",&number1,number2);
	sum = add(number1, number2);
	printf("The sum of %d and %d is %d.", number1, number2, sum);	
}
int add(int number1, int number2)
{
	int total;
	total = number1 + number2;
	return total;
}