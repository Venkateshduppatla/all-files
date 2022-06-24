// Function code to print the series of 1, 4, 27, 256, ...

int printKToThePowerOfKSeries(int seriesCount)
{
	int seriesCounter, product, counter;
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