// print k terms of series: 1, 4, 27, 256, ...

#include <stdio.h>
void main()
{
	int seriesCount, seriesCounter, productCounter, product;
	printf("The series is 1, 4, 27, 256...\n");
	printf("How many terms do you require to be printed in the series? ");
	scanf("%d", &seriesCount);
	printf("The series is: ");
	for (seriesCounter = 1; seriesCounter <= seriesCount; seriesCounter++)
	{
		product = 1;
		for (productCounter = 1; productCounter <= seriesCounter; productCounter++)
		{
			product = product * seriesCounter;
		}	
		printf("%d", product);
		if (seriesCounter < seriesCount)
		{
			printf(", ");
		}
		else if (seriesCounter = seriesCount)
		{
			printf(".");
		}
	}
}

