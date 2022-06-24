//test program to print k terms of series: 1, 4, 27, 256, ...

#include <stdio.h>
#include "printseries.c"
int main()
{
	printKToThePowerOfKSeries(5);
	printf("\n\n");
	printKToThePowerOfKSeries(10);
}