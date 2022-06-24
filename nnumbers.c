// Print N natural numbers using single variable.

#include <stdio.h>

int main()
{
	int count;
	printf("Enter the end natural number: ");
	scanf("%d", &count);
	display(count);
}

void display(int count)
{
	if (count)
	{
		display(count - 1);
	}
	else
	{
		return;
	}
	printf("%d\n", count);
}