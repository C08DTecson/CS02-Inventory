#include <stdio.h>

struct item{
	int ID;
	char *Description;
	int Quantity;
	char *ExpiryDate;
	float Price; 
};

int menuAddItem()
{
	char str[20];
    struct item item1;
	printf("\n\n-----------------------------\n");
	printf("    ADDING INVENTORY ITEM\n");
	printf("-----------------------------\n\n");
	//Enter ID
	printf("a.) Enter your Item ID: ");
	scanf("%d", &item1.ID);
	//Enter Item Description
	printf("\nb.) Enter your Item Description: ");
	scanf("%[^\n]s", str);
	printf("%s", str);
	//Enter Quantity
	printf("\nc.) Enter Quantity: ");
	scanf("%d", &item1.Quantity);
	//Enter Expiry Date
	printf("\nd.) Enter Expiry Date: ");
	scanf("%[^\n]s",str);
	printf("%s", str);
	//Enter Price
	printf("\ne.) Enter Price: ");
	scanf("%f", &item1.Price);	
	printf("\nItem ID = %s\n", item1.ID);
	printf("Item Description = %s\n", item1.Description);
	printf("Item Quantity = %d\n", item1.Quantity);
	printf("Item Expiry Date = %s\n", item1.ExpiryDate);
    printf("Item Price = %f\n", item1.Price);
    return 0;
}