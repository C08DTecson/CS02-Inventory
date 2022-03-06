#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int searchItem();
int idVal;
int fileId, updtIn;
char idchVal[5], get1[255], get2[5];
bool scanning = true;

int searchItem()
{

	// FILE* inven;
	// struct item invenItem;
	// inven = fopen("inventory.csv", "a+");

	//ID System
	do
	{
		printf("Enter the Product ID: ");
		scanf(" %d", &idVal);
		// fseek(stdin, 0, SEEK_END);

		if ((idVal < 9999) || (idVal > 99999) || (idVal <= 0))
		{
			printf("Invalid ID format, Please input valid ID format:\n");
			continue;

		}

		else
		{
			break;
		}

	} while (scanning == true);
	
	// This block will be obsolete after implementation of linked list
	//printf("%d\n", idVal);

	// _itoa(idVal, idchVal, 10);
	//printf("%s\n", idchVal);//checking

	// while (!feof(inven))
	// {
	// 	fgets(get1, 255, inven);
	// 	//printf("%s\n", get1);
	// 	strncpy(get2, get1, 6);
	// 	//printf("%s\n", get2);
	// 	memmove(get2, get2 + 1, strlen(get2));
	// 	fileId = strcmp(idchVal, get2);
	// 	//printf("%d\n", fileId);

	// 	if (fileId == 0)
	// 	{
	// 		printf("Product Found:\n");
	// 		printf("%s\n", get1);
	// 		break;
	// 	}
	

	if (0 == 0)
	{
		printf("Please enter the data you want to edit:\n");
		printf("[1] Product Description\n[2] Product Quantity\n[3] Product Expiriy\n[4] Product Price\n");

		do
		{
			scanf("%d", &updtIn);
			scanf("%*[^\n]%*1[\n]"); //ignores all other buffering inputs aside from the first character.

			switch (updtIn)
			{
			case 1:
				printf("Changing Desc.");

			case 2:
				printf("Changing Q.");
				break;

			case 3:
				printf("Changing Exp");
				break;

			case 4:
				printf("Changing Price");
				break;

			default:
				printf("Tarongi ba\n");
				continue;
			}
		} while (scanning == true);
	}

	else
	{
		printf("Product not found, add product or enter an existing ID.\n");
	}
	// fclose(inven);
}


