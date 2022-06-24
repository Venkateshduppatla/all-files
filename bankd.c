// Bank Records Maintenance.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mytools.c"
#define ACCOUNT_NUMBER_LENGTH 18
#define NAME_LENGTH 20
#define AADHAR_NUMBER_LENGTH 13
#define PHONE_NUMBER_LENGTH 12
#define BANK_CUSTOMERS "bankcustomers.dat"
struct bankCustomer
{
	char accountNumber[ACCOUNT_NUMBER_LENGTH];
	char customerName[NAME_LENGTH];
	char gender;
	char aadharNumber[AADHAR_NUMBER_LENGTH];
	char phoneNumber[PHONE_NUMBER_LENGTH];
	float bankBalance;
	char customerStatus;
};
main()
{
	int choice;
	do
	{
		showMenu();
	} while (choice != 7);
}
//____________________________________________
// Function to show menu.

showMenu()
{
	int choice;
	printf("\n1. Save the customer details.\n2. Display all the existing records of the bank.\n3. Search for a customer.\n4. Update customer record.\n5. Close the customer record.\n6. Exit\nEnter your choice: ");
	scanf("%d", &choice);
	printf("\n");
	fflush(stdin);
	switch (choice)
	{
		case 1:
			saveCustomer();
			break;
		case 2:
			showCustomers();
			break;
		case 3:
			searchCustomer();
			break;
		case 4:
			updateCustomer();
			break;
		case 5:
			closeCustomer();
			break;
		case 6:
			printf("Session Ended!\n");
			exit(0);
			break;
		default:
			printf("Enter the correct choice!\n\n");
			break;
	}
}
// Function to save the customer details.

saveCustomer()
{
	struct bankCustomer customer;
	FILE *fpBankCustomer;
	fpBankCustomer = fopen(BANK_CUSTOMERS, "a");
	printf("Enter the Account Number: ");
	fgets(customer.accountNumber, ACCOUNT_NUMBER_LENGTH, stdin);
	removeNewLine(customer.accountNumber);
	printf("Enter the name of the customer: ");
	fgets(customer.customerName, NAME_LENGTH, stdin);
	removeNewLine(customer.customerName);
	printf("Enter the Gender: ");
	scanf("%c", &customer.gender);
	fflush(stdin);
	printf("Enter the Aadhar Number: ");
	fgets(customer.aadharNumber, NAME_LENGTH, stdin);
	removeNewLine(customer.aadharNumber);
	printf("Enter the phone number: ");
	fgets(customer.phoneNumber, PHONE_NUMBER_LENGTH, stdin);
	removeNewLine(customer.phoneNumber);
	printf("Enter the Bank Balance: ");
	scanf("%f", &customer.bankBalance);
	fflush(stdin);
	customer.customerStatus = 'O';
	printf("\n");
	fwrite(&customer, sizeof(customer), 1, fpBankCustomer);
	fclose(fpBankCustomer);
}
// Function to show all the records.

showCustomers()
{
	struct bankCustomer allCustomers;
	FILE *fpBankCustomer;
	int printStatus = 0;
	fpBankCustomer = fopen(BANK_CUSTOMERS, "r");
	printf("Customer Details: \n");
	while (fread(&allCustomers, sizeof(allCustomers), 1, fpBankCustomer) != '\0');
	{
		printf("Account Number: %s\nCustomer Name: %s\nGender: %c", allCustomers.accountNumber, allCustomers.customerName, allCustomers.gender);
		printf("\nAadhar Number: %s\nPhone Number: %s\nBalance Amount: %f\n", allCustomers.aadharNumber, allCustomers.phoneNumber, allCustomers.bankBalance);
		if (allCustomers.customerStatus == 'O')
		{
			printf("\nAccount Status : Opened.\n\n");
		}
		else
		{
			printf("\nAccount Status : Closed.\n\n");
		}
		printStatus = 1;
		//break;
	}
	if (printStatus = 0)
	{
		printf("\nNo Records Found!\n");
	}
	fclose(fpBankCustomer);

}

//Function to search a record.

searchCustomer()
{
	FILE *fpBankCustomer;
	fpBankCustomer = fopen(BANK_CUSTOMERS, "r");
	struct bankCustomer allCustomers;
	int compareStatus = 0;
	char searchTerm[ACCOUNT_NUMBER_LENGTH];
	printf("Enter the Account Number which you need details: ");
	fgets(searchTerm, ACCOUNT_NUMBER_LENGTH, stdin);
	removeNewLine(searchTerm);
	while (fread(&allCustomers, sizeof(allCustomers), 1, fpBankCustomer) != '\0')
	{
		int comparedStrings = compareStrings(allCustomers.accountNumber, searchTerm);
		if (comparedStrings == 0)
		{
			printf("One Record Exist.\n");
			printf("Account Number: %s\nCustomer Name: %s\nGender: %c", allCustomers.accountNumber, allCustomers.customerName, allCustomers.gender);
			printf("\nAadhar Number: %s\nPhone Number: %s\nBalance Amount: %f\n", allCustomers.aadharNumber, allCustomers.phoneNumber, allCustomers.bankBalance);
			if (allCustomers.customerStatus == 'O')
			{
				printf("\nAccount Status : Opened.\n\n");
			}
			else
			{
				printf("\nAccount Status : Closed.\n");
			}
			compareStatus = 1;
			break;
		}
	}
	if (compareStatus != 1)
	{
			printf("No Record Founds or Enter the correct record!\n\n");
	}
	fclose(fpBankCustomer);
}

// Function to update a record.

updateCustomer()
{
	FILE *fpBankCustomer;
	fpBankCustomer = fopen(BANK_CUSTOMERS, "r+");
	struct bankCustomer customer;
	int compareStatus = 0;
	char comparingTerm[ACCOUNT_NUMBER_LENGTH];
	printf("Enter the Account Number which you need update: ");
	fgets(comparingTerm, ACCOUNT_NUMBER_LENGTH, stdin);
	removeNewLine(comparingTerm);
	while (fread(&customer, sizeof(customer), 1, fpBankCustomer) != '\0')
	{
		int comparedAccountNumbers = compareStrings(customer.accountNumber, comparingTerm);
		if (comparedAccountNumbers == 0)
		{
			fseek(fpBankCustomer, -sizeof(customer), SEEK_CUR);
			printf("Enter the modified name of the customer: ");
			fgets(customer.customerName, NAME_LENGTH, stdin);
			removeNewLine(customer.customerName);
			printf("Enter the modified phone number: ");
			fgets(customer.phoneNumber, PHONE_NUMBER_LENGTH, stdin);
			removeNewLine(customer.phoneNumber);
			printf("Enter the current Bank Balance: ");
			scanf("%f", &customer.bankBalance);
			fflush(stdin);
			printf("\n");
			fwrite(&customer, sizeof(customer), 1, fpBankCustomer);
			compareStatus = 1;
			break;
		}
	}
	if (compareStatus != 1)
	{
			printf("No Record Founds or Enter the correct record!\n\n");
	}
	fclose(fpBankCustomer);
}

// Function to close a record.

closeCustomer()
{
	FILE *fpBankCustomer;
	fpBankCustomer = fopen(BANK_CUSTOMERS, "r+");
	struct bankCustomer customer;
	int compareStatus = 0, closeStatus = 'C';
	char comparingTerm[ACCOUNT_NUMBER_LENGTH];
	printf("Enter the Account Number which you need close: ");
	fgets(comparingTerm, ACCOUNT_NUMBER_LENGTH, stdin);
	removeNewLine(comparingTerm);
	while (fread(&customer, sizeof(customer), 1, fpBankCustomer) != '\0')
	{
		int comparedAccountNumbers = compareStrings(customer.accountNumber, comparingTerm);
		if (comparedAccountNumbers == 0)
		{
			fseek(fpBankCustomer, -sizeof(customer), SEEK_CUR);
			printf("Enter the Bank Balance: ");
			scanf("%f", &customer.bankBalance);
			fflush(stdin);
			customer.customerStatus = closeStatus;
			printf("Account is Closed!\n");
			printf("\n");
			fwrite(&customer, sizeof(customer), 1, fpBankCustomer);
			compareStatus = 1;
			break;
		}
	}
	if (compareStatus != 1)
	{
			printf("No Record Founds or Enter the correct record!\n\n");
	}
	fclose(fpBankCustomer);
}
