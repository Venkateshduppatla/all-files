//Program to maintain Employee pay records.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mytools.c"
#define  MAX_LENGTH 25
#define PATIENT_RECORDS "patients.dat"

//______________________________________________________________
// Structure Declaration.

struct patientsRecords
{	
	char patientID[MAX_LENGTH];
	char patientName[MAX_LENGTH];
	char patientProblem[MAX_LENGTH];
	char gaurdianPhoneNumber[MAX_LENGTH];
	float patientBill;
	char patientStatus;
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
	printf("\n1. Create Patient Record.\n2. Diplay all the Patients Records.\n");
	printf("3. Search for a Patient Record.\n4. Update the patient Record.\n5. Status of  Patient.\n");
	printf("6. Exit\nEnter your choice: ");
	scanf("%d", &choice);
	fflush(stdin);
	switch (choice)
	{
		case 1:
			createPatient();
			break;
		case 2:
			showPatientsRecords();
			break;
		case 3:
			searchPatientRecord();
			break;
		case 4:
			updatePatientRecord();
			break;
		case 5:
			patientStatus();
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

createPatient()
{
	struct patientsRecords patient;
	FILE *fpPatient;
	fpPatient = fopen(PATIENT_RECORDS, "a");
	printf("Enter the patient ID: ");
	fgets(patient.patientID, MAX_LENGTH, stdin);
	removeNewLine(patient.patientID);
	printf("Enter the Patient Name: ");
	fgets(patient.patientName, MAX_LENGTH, stdin);
	removeNewLine(patient.patientName);
	printf("Enter the health problem of Patient: ");
	fgets(patient.patientProblem, MAX_LENGTH, stdin);
	removeNewLine(patient.patientProblem);
	printf("Enter the Phone number of gaurdian: ");
	fgets(patient.gaurdianPhoneNumber, MAX_LENGTH, stdin);
	removeNewLine(patient.gaurdianPhoneNumber);
	printf("Enter the Bill Amount: ");
	scanf("%f", &patient.patientBill);
	fflush(stdin);
	patient.patientStatus = 'A';
	printf("\n");
	fwrite(&patient, sizeof(patient), 1, fpPatient);
	fclose(fpPatient);
}

//___________________________________________________________________
// Function to show all the patients.

showPatientsRecords()
{
	struct patientsRecords patient;
	FILE *fpPatient;
	fpPatient = fopen(PATIENT_RECORDS, "r");
	if (fread(&patient, sizeof(patient), 1, fpPatient) == '\0')
	{
		printf("\nNo Patient Record Exists!\n");
	}
	else
	{
		printf("\nPatient Details are:\n ");
		do
		{
			printf("Patient ID: %s\nPatient Name: %s\n Patient Health Problem: %s\n", patient.patientID, patient.patientName, patient.patientProblem);
			printf("Gaurdian Phone Number: %s\nBill Payment: %f\n", patient.gaurdianPhoneNumber, patient.patientBill);
			if (patient.patientStatus = 'D')
			{
				printf("Patient Status: Discharge!\n\n");
			}
			else
			{
				printf("Patient Status: Active!\n\n");
			}
		} while (fread(&patient, sizeof(patient), 1, fpPatient) != '\0');
	}
	fclose(fpPatient);
}

//_____________________________________________________________________________________________________
// Function to search a patient.

searchPatientRecord()
{
	FILE *fpPatient;
	fpPatient = fopen(PATIENT_RECORDS, "r");
	struct patientsRecords patient;
	int compareStatus = 0;
	char searchID[MAX_LENGTH];
	printf("Enter the Patient ID which you need details: ");
	fgets(searchID, MAX_LENGTH, stdin);
	removeNewLine(searchID);
	while (fread(&patient, sizeof(patient), 1, fpPatient) != '\0')
	{
		int comparedStrings = compareStrings(patient.patientID, searchID);
		if (comparedStrings == 0)
		{
			printf("\nPatient Name: %s\n Patient Health Problem: %s\n", patient.patientName, patient.patientProblem);
			printf("Gaurdian Phone Number: %s\nBill Payment: %f\n", patient.gaurdianPhoneNumber, patient.patientBill);
			if (patient.patientStatus = 'D')
			{
				printf("Patient Status: Discharged!\n\n");
			}
			else
			{
				printf("Patient Status: Active!\n\n");
				compareStatus = 1;
				break;
			}
		}
	}
	if (compareStatus != 1)
	{
			printf("No Record Founds or Enter the correct ID!\n\n");
	}
	fclose(fpPatient);
}

//_________________________________________________________________________________________
// Function to update a patient.

updatePatientRecord()
{
	FILE *fpPatient;
	fpPatient = fopen(PATIENT_RECORDS, "r");
	struct patientsRecords patient;
	int compareStatus = 0;
	char searchID[MAX_LENGTH];
	printf("Enter the Patient ID which you need details: ");
	fgets(searchID, MAX_LENGTH, stdin);
	removeNewLine(searchID);
	while (fread(&patient, sizeof(patient), 1, fpPatient) != '\0')
	{
		int comparedStrings = compareStrings(patient.patientID, searchID);
		if (comparedStrings == 0)
		{
			fseek(fpPatient, -sizeof(patient), SEEK_CUR);
			printf("Enter the Patient Name: ");
			fgets(patient.patientName, MAX_LENGTH, stdin);
			removeNewLine(patient.patientName);
			printf("Enter the Phone number of gaurdian: ");
			fgets(patient.gaurdianPhoneNumber, MAX_LENGTH, stdin);
			removeNewLine(patient.gaurdianPhoneNumber);
			printf("Enter the Bill Amount: ");
			scanf("%f", &patient.patientBill);
			fflush(stdin);
			printf("\n");
			fwrite(&patient, sizeof(patient), 1, fpPatient);
			compareStatus = 1;
			break;
		}
	}
	if (compareStatus != 1)
	{
			printf("No Record Founds or Enter the correct record!\n\n");
	}
	fclose(fpPatient);
}

//__________________________________________________________________________________________________________
// Function to Close a record. 

patientStatus()
{
	FILE *fpPatient;
	fpPatient = fopen(PATIENT_RECORDS, "r");
	struct patientsRecords patient;
	int compareStatus = 0, closeStatus = 'D';
	char searchID[MAX_LENGTH];
	printf("Enter the Patient ID which you need details: ");
	fgets(searchID, MAX_LENGTH, stdin);
	removeNewLine(searchID);
	while (fread(&patient, sizeof(patient), 1, fpPatient) != '\0')
	{
		int comparedStrings = compareStrings(patient.patientID, searchID);
		if (comparedStrings == 0)
		{
			fseek(fpPatient, -sizeof(patient), SEEK_CUR);
			patient.patientStatus = closeStatus;
			printf("Patient Status: Discharged!\n");
			printf("\n");
			fwrite(&patient, sizeof(patient), 1, fpPatient);
			compareStatus = 1;
			break;
		}
	}
	if (compareStatus != 1)
	{
			printf("No Record Founds or Enter the correct record!\n\n");
	}
	fclose(fpPatient);
}


removePatient()
{
	FILE *fpPatient;
	fpPatient = fopen(PATIENT_RECORDS, "w");
	fclose(fpPatient);
}