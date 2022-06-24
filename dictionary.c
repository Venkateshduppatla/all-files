//Program to find meaning of a word.

#include <stdio.h>
#include <string.h>
#include "mytools.c"
#define MAX_LENGTH 30
#define COMMAND_LINE_LENGTH 200
#define WORD_DATA_LENGTH 1000

int main()
{
	char word[MAX_LENGTH];
	char commandLine[COMMAND_LINE_LENGTH];
	printf("Enter the word:");
	fgets(word, MAX_LENGTH, stdin);
	removeNewLine(word);
	sprintf(commandLine, "curl -k \"https://api.dictionaryapi.dev/api/v2/entries/en/%s\" >dictionary.txt", word);
	//printf("%s", commandLine);
	system(commandLine);
	char *meaning;
	//char *audioCommand;
	char wordMeaning[WORD_DATA_LENGTH], pronounciation[COMMAND_LINE_LENGTH];
	int comparedStrings = 0;
	FILE *fpWordMeaning;
	fpWordMeaning = fopen("dictionary.txt", "r");
	//fread(wordMeaning, WORD_DATA_LENGTH, 1, fpWordMeaning);
	meaning = strtok(wordMeaning, ":");
	while (meaning != '\0')
	{
		meaning = strtok('\0', ":");
		comparedStrings = strcmp(meaning, "\"https\"");
		if (comparedStrings == 0)
		{
			meaning = strtok('\0', "\"");
			sprintf(pronounciation, "vlc \"https:%s\"", meaning);
			system(pronounciation);
			break;
		}
		meaning = strtok('\0', ",:");
	}
	//meaning = strtok(NULL, ":");
	while (meaning != '\0')
	{
		if (strcmp(meaning, "[{\"definition\"") == 0)
		{
			meaning = strtok('\0', ",");
			printf("Meaning : %s", meaning);
			break;
		}
		meaning = strtok('\0', ":");
	}
	fclose(fpWordMeaning);
}