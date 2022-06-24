// User program to print k terms of series: 1, 4, 27, 256, ...

#include <stdio.h>
#include "printseries.c"
void main()
{
	int seriesCount;
	printf("The series consists of terms as K to the power of K.\n");
	printf("How many terms do you require to be printed in the series? ");
	scanf("%d", &seriesCount);
	printf("The series is: ");
	printKToThePowerOfKSeries(seriesCount);
}