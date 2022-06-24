// To print name using files.

#include <stdio.h>
int main()
{
	FILE *file;
	file = fopen("name.txt", "w");
	fprintf(file, "%s", "Venkatesh");
	fclose(file);
	//FILE *file;
	char name[10];
	file = fopen("name.txt", "r");
	printf("%s", fgets(name, 10, file));
	fclose(file);
}