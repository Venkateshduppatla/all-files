//calling a  function and print whether the given number is prime or not.

#include <stdio.h>
#include <math.h>
void main()
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
int isPrime(int number)
{
	int factor = 2, primeStatus, squareRoot, remainder;
	if(number < factor)
	{
		primeStatus = 0;
	}
	else if(number == factor)
	{
		primeStatus = 1;
	}	
	else if(number % factor == 0)
	{
		primeStatus = 0;
	}
	else
	{
		squareRoot = sqrt(number);
		for(factor = 3; factor <= squareRoot; factor += 2)
		{
			remainder = number % factor;
			if(remainder == 0)
			{
				primeStatus = 0;
				break;
			}
		}
	}
	return primeStatus;
}
