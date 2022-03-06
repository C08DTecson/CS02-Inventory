#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int addItem();
int priceCheck, existID;
char* checking[6];
char str1[255], str2[8], idCheck[5];
int x;
bool scan = true;

typedef struct item
{
	int quan;
	int id;
	int mm, dd, yy;
	float price;
	char desc[100];

} item;

int addItem()
{
	FILE* inven;
	struct item invenItem;
	inven = fopen("inventory.csv", "a+");
	//ID System
	do
	{
		printf("Enter the Product ID: ");
		scanf(" %6d", &invenItem.id);
		getchar();

		if ((invenItem.id < 9999) || (invenItem.id > 99999) || (invenItem.id <= 0))
		{
			printf("Invalid ID format, Please input valid ID format:\n");
			continue;

		}

		else
		{
			break;
		}

	} while (scan == true);


	//DESCRIPTION
	printf("Enter the Product Description: ");
	scanf(" %[^\n]s", &invenItem.desc);
	getchar();
	


	//QUIANTITY
	while (scan == true)
	{
		printf("Please enter the amount of items: ");
		scanf(" %6d", &invenItem.quan);
		getchar();

		if (invenItem.quan < 0)
		{
			printf("Invalid quantity, please try again:\n");
			continue;
		}

		else
		{
			break;
		}

	}



	//EXPIRY DATE
	getchar();
	printf("Please Enter the Expiry Date (YYYY-MM-DD)\n");
	while (scan == true)
	{
		printf("Year: ");
		scanf(" %5d", &invenItem.yy);
		getchar();

		if ((invenItem.yy < 1) || (invenItem.yy > 9999))
		{
			printf("Invalid year, Please try again:\n");
			continue;
		}

		else
		{
			while (scan == true)
			{
				printf("Month: ");
				scanf(" %3d", &invenItem.mm);
				getchar();

				if ((invenItem.mm >= 1) && (invenItem.mm <= 12))
				{
					while (scan == true)
					{
						printf("Date: ");
						scanf(" %3d", &invenItem.dd);
						getchar();

						if ((invenItem.dd >= 1 && invenItem.dd <= 31) && (invenItem.mm == 1 || invenItem.mm == 3 || invenItem.mm == 5 || invenItem.mm == 7 || invenItem.mm == 8 || invenItem.mm == 10 || invenItem.mm == 12))
						{
							//printf("Date is valid.\n");
							break;
						}

						else if ((invenItem.dd >= 1 && invenItem.dd <= 30) && (invenItem.mm == 4 || invenItem.mm == 6 || invenItem.mm == 9 || invenItem.mm == 11))
						{
							//printf("Date is valid.\n");
							break;
						}

						else if ((invenItem.dd >= 1 && invenItem.dd <= 28) && (invenItem.mm == 2))
						{
							//printf("Date is valid.\n");
							break;

						}

						else
						{
							printf("Invalid date please input again:\n");
							continue;

						}
					}

					break;
				}

				else
				{
					printf("Invalid month, please input again:\n");
					continue;
				}
			}
		}

		break;

	}
	printf("Expiry date is %d-%d-%d\n", invenItem.yy, invenItem.mm, invenItem.dd);//check


	//PRICE
	while (scan == true)
	{
		printf("Please enter the item price: ");
		scanf(" %f", &invenItem.price);
		getchar();
		priceCheck = invenItem.price;


		if (priceCheck <= 0)
		{
			printf("Invalid item price, please try again:\n ");
			continue;
		}

		else
		{
			break;
		}
	}
	invenItem.price = fabs(invenItem.price);

	_itoa(invenItem.id, idCheck, 10);

	while (!feof(inven))
	{
		x = getc(inven);
		fgets(str1, 255, inven);
		strncpy(str2, str1, 5);
		existID = strcmp(idCheck, str2);
		if (existID == 0)
		{
			printf("Product ID already Exists. Please try again.\n");
			break;
		}

	}

	if (existID != 0)
	{
		fprintf(inven, "\n\"%d\", \"%s\", \"%d\", \"%d-%d-%d\", \"%0.2f\"", invenItem.id, invenItem.desc, invenItem.quan, invenItem.yy, invenItem.mm, invenItem.dd, invenItem.price);
		printf("Successfully added a new product to the inventory:\n");
		printf("\"%d\", \"%s\", \"%d\", \"%d-%d-%d\", \"%0.2f\"", invenItem.id, invenItem.desc, invenItem.quan, invenItem.yy, invenItem.mm, invenItem.dd, invenItem.price);
	}
	fclose(inven);
}