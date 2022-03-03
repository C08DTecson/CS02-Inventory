#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


int idInput();
int getInt();
int priceCheck, existID, ch, num;
char* checking[6];
char str1[255], str2[8], idCheck[5];
char buf[50] = { '\0' };
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

int idInput()
{
    FILE* inven;
    struct item invenItem;
    inven = fopen("inventory.csv", "a+");

    printf("-----------------------------\n");
    printf("   ADDING INVENTORY ITEM\n");
    printf("-----------------------------\n");

    //ID Code
    do
    {
        printf("Enter Item ID: ");
        invenItem.id = 0;
        invenItem.id = getInt();

        if ((invenItem.id <= 9999) || (invenItem.id >= 99999))
        {
            printf("Invalid ID format, try again.\n");
        }

        else
        {
            printf("\nItem ID accepted.\n");
            break;
        }
    } while (scan == true);
    printf("%d\n", invenItem.id);

    //Item Desc
    printf("Enter the Item Description: ");
    scanf(" %[^\n]s", &invenItem.desc);
    getchar();
    printf("%s\n", invenItem.desc); //checking
    printf("Successfully added Item Description.\n");

    //Product Quan
    printf("Enter Quantity: ");
    invenItem.quan = 0;
    invenItem.quan = getInt();
    printf("\n%d\n", invenItem.quan);
    printf("Item quantity accepted.\n");

    //Expiry Date
    printf("Enter Product Expiry(YYYY/MM/DD):\n");
    while (scan == true)
    {
        printf("Year: ");
        invenItem.yy = 0;
        invenItem.yy = getInt();

        if ((invenItem.yy <= 0) || (invenItem.yy > 9999))
        {
            printf("\nInvalid year, please try again.\n");
        }

        else
        {
            while (scan == true)
            {
                printf("\nMonth: ");
                invenItem.mm = 0;
                invenItem.mm = getInt();

                if ((invenItem.mm >= 1) && (invenItem.mm <= 12))
                {
                    while (scan == true)
                    {
                        printf("\nDate: ");
                        invenItem.dd = 0;
                        invenItem.dd = getInt();
                        if ((invenItem.dd >= 1 && invenItem.dd <= 31) && (invenItem.mm == 1 || invenItem.mm == 3 || invenItem.mm == 5 || invenItem.mm == 7 || invenItem.mm == 8 || invenItem.mm == 10 || invenItem.mm == 12))
                        {
                            printf("\nDate is valid.\n");
                            break;
                        }

                        else if ((invenItem.dd >= 1 && invenItem.dd <= 30) && (invenItem.mm == 4 || invenItem.mm == 6 || invenItem.mm == 9 || invenItem.mm == 11))
                        {
                            printf("\nDate is valid.\n");
                            break;
                        }

                        else if ((invenItem.dd >= 1 && invenItem.dd <= 28) && (invenItem.mm == 2))
                        {
                            printf("\nDate is valid.\n");
                            break;

                        }

                        else
                        {
                            printf("\nInvalid date, please input again.");
                        }
                    }
                    break;
                }

                else
                {
                    printf("\nInvalid month, please try again.");
                }
            }

            break;
        }
    }

    //Price
    while (scan == true)
    {
        invenItem.price = 0;
        printf("Enter Price: ");
        fgets(buf, 45, stdin);
        sscanf(buf, " %f", &invenItem.price);
        if (invenItem.price <= 0)
        {
            printf("Invalid price, please try again.\n");
        }

        else
        {
            break;
        }
    }

    _itoa(invenItem.id, idCheck, 10); //convert int input to string

    //ID Checking if Product Exists
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
        printf("Successfully added a new product to the inventory.\n");
    }
    fclose(inven);

}

int getInt()
{
    int num = 0;
    int ch;
    do {
        ch = getch();
        // Checks the ASCII code of '
        // digits 0 to 9
        if (ch >= 48 && ch <= 57)
        {
            printf("%c", ch);

            // To make a digit
            num = num * 10 + (ch - 48);
        }

        // 13 is carriage return it breaks
        // and return the input
        if (ch == 13)
        {
            break;
        }
    } while (1);

    return (num);
}
