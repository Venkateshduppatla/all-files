//Program to find meaning of a word.

#include <stdio.h>
#include <string.h>
#include "mytools.c"
#define MAX_LENGTH 30
#define COMMAND_LINE_LENGTH 200
#define CODE_DATA_LENGTH 30000

int main()
{
	char word[MAX_LENGTH];
	char commandLine[COMMAND_LINE_LENGTH];
	printf("Enter the word:");
	fgets(word, MAX_LENGTH, stdin);
	removeNewLine(word);
	sprintf(commandLine, "curl -k \"https://dict.hinkhoj.com/shabdkhoj.php?word=%s&ie=UTF-8\" >telugudictionary.txt", word);
	system(commandLine);
	char *hindiMeaning;
	char htmlCodeForHindiMeaning[CODE_DATA_LENGTH];
	FILE *fpHindiMeaning;
	fpHindiMeaning = fopen("telugudictionary.txt", "r");
	fread(htmlCodeForHindiMeaning, CODE_DATA_LENGTH, 1, fpHindiMeaning);
		hindiMeaning = strtok(htmlCodeForHindiMeaning, "><.:");
		while (hindiMeaning != '\0')
		{
			hindiMeaning = strtok('\0', "><.:");
			if (strcmp(hindiMeaning, " Know answer of question ") == 0)
			{
				hindiMeaning = strtok('\0', ".");
				hindiMeaning = strtok('\0', ".");
				printf("%s.\n", hindiMeaning);
				break;
			}
		}
	fclose(fpHindiMeaning);
}