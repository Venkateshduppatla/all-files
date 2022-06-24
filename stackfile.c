#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BANK_RECORDS "bankrecords.dat"
#define ACCOUNT_NUMBER_LENGTH 16
#define ACCOUNT_HOLDER_NAME_LENGTH 30
#define PHONE_NUMBER_LENGTH 12
struct bankRecords
	{
		char accountNumber[ACCOUNT_NUMBER_LENGTH];
		char gender;
		char phoneNumber[PHONE_NUMBER_LENGTH];
		float bankBalance;
		char name[ACCOUNT_HOLDER_NAME_LENGTH];
	};
main()
{
	int choice;
	do
	{
		showMenu();
	} while (choice != 4);
}
showMenu()
{
	int choice;
	printf("1. Save the customer details.\n2. Display all the existing records of bank.\n3. Remove customer records.\n4. Exit\nEnter your choice: ");
	scanf("%d", &choice);
	printf("\n");
	fflush(stdin);
	switch(choice)
		{
			case 1:
				saveBankRecord();
				break;
			case 2:
				showBankRecords();
				break;
			case 3:
				removeBankRecords();
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("Enter the correct choice: ");
		}
}
// Function to save  the bank customer details.

saveBankRecord()
{
	struct bankRecords bankRecord;
	FILE *fpBankRecords;
	fpBankRecords = fopen(BANK_RECORDS, "a");
	printf("Enter the bank account number: ");
	fgets(bankRecord.accountNumber, ACCOUNT_NUMBER_LENGTH, stdin);
	removeNewLine(bankRecord.accountNumber);
	printf("Enter the gender of the customer: ");
	scanf("%s", &bankRecord.gender);
	fflush(stdin);
	printf("Enter the phone number: ");
	fgets(bankRecord.phoneNumber, PHONE_NUMBER_LENGTH, stdin);
	removeNewLine(bankRecord.phoneNumber);
	printf("Enter the balance: ");
	scanf("%f", &bankRecord.bankBalance);
	printf("Enter the name of the bank customer: ");
	fgets(bankRecord.name, ACCOUNT_HOLDER_NAME_LENGTH, stdin);
	removeNewLine(bankRecord.name);
	printf("\n");
	fwrite(&bankRecord, sizeof(bankRecord), 1, fpBankRecords);
	fclose(fpBankRecords);
}
// Function to remove new line.

removeNewLine(char *anyName)
{
	anyName[strlen(anyName) - 1] = '\0';
}
// Function to show the bank details.

showBankRecords()
{
	struct bankRecords bankCustomers;
	FILE *fpBankRecords;
	fpBankRecords = fopen(BANK_RECORDS, "r");
	if (fread(&bankCustomers, sizeof(bankCustomers), 1, fpBankRecords) == '\0')
	{
		printf("\nNo Records found.\n\n");
	}
	else
	{
		do
		 {
			printf("Account Number: %s\nName of the Customer: %s\nGender: %c\n Phone Number: %s\nBank Balance: %f\n\n", bankCustomers.accountNumber, bankCustomers.name, bankCustomers.gender, bankCustomers.phoneNumber, bankCustomers.bankBalance);
		 } while ((fread(&bankCustomers, sizeof(bankCustomers), 1, fpBankRecords) != '\0')); 
	}
	fclose(fpBankRecords);
}
// Function to remove bank records.

removeBankRecords()
{
	FILE *fpBankRecords;
	fpBankRecords = fopen(BANK_RECORDS, "w");
	fclose(fpBankRecords);

}