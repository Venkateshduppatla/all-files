// print k terms of series: 1, 4, 27, 256, ...

#include <stdio.h>
void main()
{
	int seriesCount, seriesCounter, counter, product;
	printf("The series consists of terms as K to the power of K.\n");
	printf("How many terms do you require to be printed in the series? ");
	scanf("%d", &seriesCount);
	printf("The series is: ");
	for(seriesCounter = 1; seriesCounter <= seriesCount; seriesCounter++)
	{
		product = 1;
		for(counter = 1; counter<=seriesCounter; counter++)
		{
			product = product * seriesCounter;
		}	
		printf("%d", product);
		if(seriesCounter < seriesCount)
		{
			printf(", ");
		}
		else if(seriesCounter = seriesCount)
		{
			printf(".");
		}
	}
}