//Program to maintain Employee pay records.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mytools.c"
#define  MAX_LENGTH 30
#define EMPLOYEE_RECORDS "employee.dat"

//______________________________________________________________
// Structure Declaration.

struct employeeRecords
{	
	char employeeID[MAX_LENGTH];
	char employeeName[MAX_LENGTH];
	char employeeBankAccountNumber[MAX_LENGTH];
	char employeeIFSCCode[MAX_LENGTH];
	float employeePay;
	char employeeStatus;
};

//______________________________________________________________
// Main Function. 

main()
{
	int choice;
	do
	{
		choice = showMenu();
	} while (choice != 6);
}

//______________________________________________________________
//Show Menu Function.

showMenu()
{
	int choice;
	printf("\n1. Create an Employee Record.\n2. Diplay all the Employee Records.\n");
	printf("3. Seach for an Employee Record.\n4. Update an Employee Record.\n5. Status of an Employee.\n");
	printf("6. Exit\nEnter your choice: ");
	scanf("%d", &choice);
	fflush(stdin);
	switch (choice)
	{
		case 1:
			createEmployee();
			break;
		case 2:
			showEmployeeRecords();
			break;
		case 3:
			searchEmployee();
			break;
		case 4:
			updateEmployeeDetails();
			break;
		case 5:
			employeePaymentStatus();
			break;
		case 6:
			printf("Session Ended!\n");
			exit(0);
			break;
		default:
			printf("\nEnter the correct choice.\n");
			break;
	}
	return choice;
}

//_____________________________________________________________
// Function to create an employee record.

createEmployee()
{
	struct employeeRecords employee; 
	FILE *fpEmployeeRecord;
	fpEmployeeRecord = fopen(EMPLOYEE_RECORDS, "a");
	printf("Enter the Employee ID: ");
	fgets(employee.employeeID, MAX_LENGTH, stdin);
	removeNewLine(employee.employeeID);
	printf("Enter the Employee Name: ");
	fgets(employee.employeeName, MAX_LENGTH, stdin);
	removeNewLine(employee.employeeName);
	printf("Enter the Bank Account Number: ");
	fgets(employee.employeeBankAccountNumber, MAX_LENGTH, stdin);
	removeNewLine(employee.employeeBankAccountNumber);
	printf("Enter the IFSC Code: ");
	fgets(employee.employeeIFSCCode, MAX_LENGTH, stdin);
	removeNewLine(employee.employeeIFSCCode);
	printf("Enter the Paid Amount: ");
	scanf("%f", &employee.employeePay);
	fflush(stdin);
	employee.employeeStatus = 'U';
	printf("\n");
	fwrite(&employee, sizeof(employee), 1, fpEmployeeRecord);
	fclose(fpEmployeeRecord);
}

//_______________________________________________________________
// Function to show all employee records. 

showEmployeeRecords()
{
	struct employeeRecords employee;
	FILE *fpEmployeeRecord;
	fpEmployeeRecord = fopen(EMPLOYEE_RECORDS, "r");
	if (fread(&employee, sizeof(employee), 1, fpEmployeeRecord) == '\0')
	{
		printf("\nNo Employee Record Exists!\n");
	}
	else
	{
		printf("\nEmployee Details are:\n ");
		do
		{
			printf("Employee ID: %s\nEmployee Name: %s\nEmployee BankAccount Number: %s\n", employee.employeeID, employee.employeeName, employee.employeeBankAccountNumber);
			printf("Employee IFSC Code: %s\nEmployee Salary: %f\n", employee.employeeIFSCCode, employee.employeePay);
			if (employee.employeeStatus = 'P')
			{
				printf("Salary Status: Paid!\n\n");
			}
			else
			{
				printf("Salary Status: Not Paid!\n\n");
			}
		} while (fread(&employee, sizeof(employee), 1, fpEmployeeRecord) != '\0');
	}
	fclose(fpEmployeeRecord);
}

// Function to search a record.

searchEmployee()
{
	struct employeeRecords employee;
	FILE *fpEmployeeRecord;
	fpEmployeeRecord = fopen(EMPLOYEE_RECORDS, "r");
	int compareStatus = 0;
	char searchEmployeeID[MAX_LENGTH];
	printf("Enter the Employee ID: ");
	fgets(searchEmployeeID, MAX_LENGTH, stdin);
	removeNewLine(searchEmployeeID);
	while (fread(&employee, sizeof(employee), 1, fpEmployeeRecord) != '\0')
	{
		int comparedEmployeeID = strcmp(searchEmployeeID, employee.employeeID);
		if (comparedEmployeeID == 0)
		{
			printf("One Employee Record Exists!\n");
			printf("Employee ID: %s.\nEmployee Name: %s\nEmployee BankAccount Number: %s\n", employee.employeeID, employee.employeeName, employee.employeeBankAccountNumber);
			printf("Employee IFSC Code: %s\nEmployee Salary: %f\n", employee.employeeIFSCCode, employee.employeePay);
			if (employee.employeeStatus == 'P')
			{
				printf("Salary Status: Paid!\n");
			}
			else
			{
				printf("Salary Status:Not Paid!\n");
			}
			compareStatus = 1;
			break;
		}
	}
	if (compareStatus != 1)
	{
		printf("No Record Found or Enter the Correct Record!");
	}
	fclose(fpEmployeeRecord);
}

//_______________________________________________________________
//Function to update an employee record.

updateEmployeeDetails()
{
	struct employeeRecords employee;
	FILE *fpEmployeeRecord;
	fpEmployeeRecord = fopen(EMPLOYEE_RECORDS, "r+");
	int compareStatus = 0;
	char searchEmployeeID[MAX_LENGTH];
	printf("Enter the Employee ID which you need to modify record: ");
	fgets(searchEmployeeID, MAX_LENGTH, stdin);
	removeNewLine(searchEmployeeID);
	while (fread(&employee, sizeof(employee), 1, fpEmployeeRecord) != '\0')
	{
		int comparedEmployeeID = strcmp(employee.employeeID, searchEmployeeID);
		if (comparedEmployeeID == 0)
		{
			fseek(fpEmployeeRecord, -sizeof(employee), SEEK_CUR);
			printf("Enter the Employee Name: ");
			fgets(employee.employeeName, MAX_LENGTH, stdin);
			removeNewLine(employee.employeeName);
			printf("Enter the Bank Account Number: ");
			fgets(employee.employeeBankAccountNumber, MAX_LENGTH, stdin);
			removeNewLine(employee.employeeBankAccountNumber);
			printf("Enter the IFSC Code: ");
			fgets(employee.employeeIFSCCode, MAX_LENGTH, stdin);
			removeNewLine(employee.employeeIFSCCode);
			printf("Enter the Paid Amount: ");
			scanf("%f", &employee.employeePay);
			fflush(stdin);
			fwrite(&employee, sizeof(employee), 1, fpEmployeeRecord);
			printf("\nDetails Updated!\n\n");
			compareStatus = 1;
			break;
		}
	}
	if (compareStatus != 1)
	{
		printf("No Record Found or Enter the Correct Record!\n");
	}
	fclose(fpEmployeeRecord);	
}

//____________________________________________________________
//Function to Check the Employee payment status.

employeePaymentStatus()
{
	struct employeeRecords employee;
	FILE *fpEmployeeRecord;
	fpEmployeeRecord = fopen(EMPLOYEE_RECORDS, "r+");
	int compareStatus = 0, paymentStatus = 'P';
	char searchEmployeeID[MAX_LENGTH];
	printf("Enter the Employee ID which you need to modify record: ");
	fgets(searchEmployeeID, MAX_LENGTH, stdin);
	removeNewLine(searchEmployeeID);
	while (fread(&employee, sizeof(employee), 1, fpEmployeeRecord) != '\0')
	{
		int comparedEmployeeID = strcmp(searchEmployeeID, employee.employeeID);
		if (comparedEmployeeID == 0)
		{
			fseek(fpEmployeeRecord, -sizeof(employee), SEEK_CUR);
			employee.employeeStatus = paymentStatus;
			printf("Salary Status: Paid!\n");
			fwrite(&employee, sizeof(employee), 1, fpEmployeeRecord);
			compareStatus = 1;
			break;
		}
	}
	if (compareStatus != 1)
	{
		printf("No Record Found or Enter the Correct Record!");
	}
	fclose(fpEmployeeRecord);
}

// Function to delete all the records.

removeEmployees()
{
	FILE *fpEmployeeRecord;
	fpEmployeeRecord = fopen(EMPLOYEE_RECORDS, "w");
	fclose(fpEmployeeRecord);
	printf("All the records are Deleted.\n\n");
}