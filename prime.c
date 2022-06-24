// print whether the given number is prime or not

#include <stdio.h>
#include <math.h>
void main()
{
	int number, factor = 2, squareRoot, remainder, primeStatus;
	printf("To check whether the given number is prime or not.\n");
	printf("Enter the number: ");
	scanf("%d", &number);
	if(number < factor)
	{
		printf("%d is neither prime nor composite.", number);
		return;
	}
	if(number == factor)
	{
		primeStatus = 1;	
	}
	else if(number % factor == 0)
	{
		primeStatus = 0;
	}
	else if(number == factor + 1)
	{
		primeStatus = 1;
	}
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
	if(primeStatus == 0)
	{
		printf("%d is not a prime number.", number);
	}
	else
	{
		printf("%d is a prime number.", number);
	}
}