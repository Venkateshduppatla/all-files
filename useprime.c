// user prime program

#include <stdio.h>
#include "checkprime.c"
int main()
{
	int number;
	printf("To check whether the given number is prime or not.\n");
	printf("Enter the number: ");
	scanf("%d", &number);
	if(isPrime(number)==0)
	{
		printf("%d is not a prime number", number);
	}
	else
	{
		printf("%d is a prime number", number);
	}
}
