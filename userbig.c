//User program to read two numbers and print the bigger one

#include <stdio.h>
#include "funcbigger.c"
int main()
{
	int number1, number2;
	printf("Enter two numbers to print the bigger one: ");
	scanf("%d%d", &number1, &number2);
	examineBiggerNumber(&number1, &number2);
	printf("%d is larger than %d.", number1, number2);

}