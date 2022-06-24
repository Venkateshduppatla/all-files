//Program to check whether the given number is prime or not.

#include  <math.h>
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
