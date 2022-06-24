#include  <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_LENGTH 5
int main()
{
	char longName[2][NAME_LENGTH];
	printf("Enter the name-1");
	scanf("%4s", longName[1]);
	printf("Enter the name-2");
	scanf("%5s", longName[2]);
	printf("%s\n%s", longName[1], longName[2]);
}