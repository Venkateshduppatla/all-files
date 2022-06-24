//Program to maintain Store products records.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mytools.c"
#define  MAX_LENGTH 30
#define STORE_RECORDS "store.dat"

//______________________________________________________________
// Structure Declaration.

struct storeProductRecords
{	
	char productID[MAX_LENGTH];
	char productName[MAX_LENGTH];
	int numberOfProducts;
	float productPrice;
	char productStatus;
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
	printf("\n1. Create a Product Record.\n2. Diplay all the Product Records.\n");
	printf("3. Seach for Product.\n4. Update a Product .\n5. Product Status.\n");
	printf("6. Exit\nEnter your choice: ");
	scanf("%d", &choice);
	fflush(stdin);
	switch (choice)
	{
		case 1:
			createProduct();
			break;
		case 2:
			showProductRecords();
			break;
		case 3:
			searchProduct();
			break;
		case 4:
			updateProductDetails();
			break;
		case 5:
			productAvailabilityStatus();
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
// Function to create a product record.

createProduct()
{
	struct storeProductRecords product; 
	FILE *fpProduct;
	fpProduct = fopen(STORE_RECORDS, "a");
	printf("Enter the Product ID: ");
	fgets(product.productID, MAX_LENGTH, stdin);
	removeNewLine(product.productID);
	printf("Enter the Product Name: ");
	fgets(product.productName, MAX_LENGTH, stdin);
	removeNewLine(product.productName);
	printf("Enter Number Of Products: ");
	scanf("%d", &product.numberOfProducts);
	fflush(stdin);
	printf("Enter Product Price: ");
	scanf("%f", &product.productPrice);
	fflush(stdin);
	product.productStatus = 'A';
	printf("\n");
	fwrite(&product, sizeof(product), 1, fpProduct);
	fclose(fpProduct);
}
//_______________________________________________________________
// Function to show all employee records. 

showProductRecords()
{
	struct storeProductRecords product;
	FILE *fpProduct;
	fpProduct = fopen(STORE_RECORDS, "r");
	if (fread(&product, sizeof(product), 1, fpProduct) == '\0')
	{
		printf("\nNo Product Record Exists!\n");
	}
	else
	{
		printf("\nProduct Details are:\n ");
		do
		{
			printf("product ID: %s\nProduct Name: %s\nNumber of Product Available: %d\n", product.productID, product.productName, product.numberOfProducts);
			printf("Product Price: %f\n", product.productPrice);
			if (product.productStatus = 'A')
			{
				printf("Product Status: Available!\n\n");
			}
			else
			{
				printf("Product Status: Not Available!\n\n");
			}
		} while (fread(&product, sizeof(product), 1, fpProduct) != '\0');
	}
	fclose(fpProduct);
}

//____________________________________________________________________
// Function to search a product.

searchProduct()
{
	struct storeProductRecords product;
	FILE *fpProduct;
	fpProduct = fopen(STORE_RECORDS, "r");
	int compareStatus = 0;
	char searchproductID[MAX_LENGTH];
	printf("Enter the Product ID: ");
	fgets(searchproductID, MAX_LENGTH, stdin);
	removeNewLine(searchproductID);
	while (fread(&product, sizeof(product), 1, fpProduct) != '\0')
	{
		int comparedProductID = strcmp(searchproductID, product.productID);
		if (comparedProductID == 0)
		{
			printf("\nOne Record Exists!\n");
			printf("product ID: %s\nProduct Name: %s\nNumber of Product Available: %d\n", product.productID, product.productName, product.numberOfProducts);
			printf("Product Price: %f", product.productPrice);
			if (product.productStatus = 'A')
			{
				printf("Product Status: Available!\n\n");
			}
			else
			{
				printf("Product Status: Not Available!\n\n");
			}
			compareStatus = 1;
			break;
		}
	}
	if (compareStatus != 1)
	{
		printf("No Record Found or Enter the Correct Record!");
	}
	fclose(fpProduct);
}

//_______________________________________________________________
//Function to Update a product record.

updateProductDetails()
{
	struct storeProductRecords product;
	FILE *fpProduct;
	fpProduct = fopen(STORE_RECORDS, "r+");
	int compareStatus = 0;
	char searchproductID[MAX_LENGTH];
	printf("Enter the Product ID: ");
	fgets(searchproductID, MAX_LENGTH, stdin);
	removeNewLine(searchproductID);
	while (fread(&product, sizeof(product), 1, fpProduct) != '\0')
	{
		int comparedProductID = strcmp(searchproductID, product.productID);
		if (comparedProductID == 0)
		{
			fseek(fpProduct, -sizeof(product), SEEK_CUR);
			printf("Enter the Product Name: ");
			fgets(product.productName, MAX_LENGTH, stdin);
			removeNewLine(product.productName);
			printf("Enter Number Of Products: ");
			scanf("%d", &product.numberOfProducts);
			fflush(stdin);
			printf("Enter Product Price: ");
			scanf("%f", &product.productPrice);
			fflush(stdin);
			fwrite(&product, sizeof(product), 1, fpProduct);
			printf("\nDetails Updated!\n\n");
			compareStatus = 1;
			break;
		}
	}
	if (compareStatus != 1)
	{
		printf("No Record Found or Enter the Correct Record!\n");
	}
	fclose(fpProduct);
}

//____________________________________________________________
//Function to Check the product availability status.

productAvailabilityStatus()
{
	struct storeProductRecords product;
	FILE *fpProduct;
	fpProduct = fopen(STORE_RECORDS, "r+");
	int compareStatus = 0, availableStatus = 'N';
	char searchproductID[MAX_LENGTH];
	printf("Enter the Product ID: ");
	fgets(searchproductID, MAX_LENGTH, stdin);
	removeNewLine(searchproductID);
	while (fread(&product, sizeof(product), 1, fpProduct) != '\0')
	{
		int comparedProductID = strcmp(searchproductID, product.productID);
		if (comparedProductID == 0)
		{
			fseek(fpProduct, -sizeof(product), SEEK_CUR);
			product.productStatus = availableStatus;
			printf("Product Status: Not Avaiable!\n");
			fwrite(&product, sizeof(product), 1, fpProduct);
			compareStatus = 1;
			break;
		}
	}
	if (compareStatus != 1)
	{
		printf("No Record Found or Enter the Correct Record!");
	}
	fclose(fpProduct);
}