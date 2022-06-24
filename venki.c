// Program to feel the memory allocation. 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MEMORY_ALLOCATION "malloc.dat"
//#define FILE_NEW "test.dat"
//#define MAX_LENGTH 20
/*main()
{
	FILE *fpTest;
	fpTest = fopen(FILE_NEW, "r");
	char name;
	fwrite(&name, MAX_LENGTH, 1, stdin);
	fread(&name, MAX_LENGTH, 1, fpTest);
	fread(&name, MAX_LENGTH, 1, fpTest);
	fread(&name, MAX_LENGTH, 1, fpTest);
	fread(&name, MAX_LENGTH, 1, fpTest);
	fclose(fpTest);
}*/


/*main()
{
	FILE *fpData;
	fpData = fopen(MEMORY_ALLOCATION, "w");
	int count = 1145258561, counter;
	fwrite(&count, sizeof(count), 1, fpData);
	fclose(fpData);
}*/

/*int main()
{
	int count = 16961;
	char *ptr;
	ptr = (char*)&count;
	printf("%s\n", ptr);
}*/


main()
{
	char name[5] = "A";
	int *ptr;
	ptr = (int*)name;
	printf("%u", *ptr);
}


/*main()
{
	char array[10];
	printf("Enter the array: ");
	fgets(array, 10, stdin);
	printf("%s", array);
}
*/


/*#include <stdio.h>
#include <string.h>
main()
{
	char sentence[50];
	char removedWord[3] = " ";
	char *token;
	printf("Enter the sentence: ");
	fgets(sentence, 50, stdin);
	token = strtok(sentence, removedWord);
	while (token != '\0')
	{
		printf("%s\n", token);
		token = strtok('\0', removedWord);
	}
}*/