#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include "linkedListUI.h"

int addItem();
int priceCheck, existID, num, idInt;
char* checking[6];
char str1[255], str2[8], idCheck[5], dig;
int yyHolder, mmHolder, ddHolder;
char buf[50] = { '\0' };
int x, check, ch;
bool scan = true;

typedef struct item
{
    char quan[255];
    char id[255];
    char mm[255], dd[255], yy[255];
    float price;
    char desc[100];

} item;

int addItem()
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
        scanf(invenItem.id, 255);
        // scanf("%s", &invenItem.id);
        // printf("%s", &invenItem.id);

        
        for (x = 0; x != 5; x++)
        {
            if ((isdigit(invenItem.id[x]) == 0) || strlen(invenItem.id) != 5 || (invenItem.id == '\0'))
            {
                printf("Invalid ID format, please try again.\n");
                break;
            }

            else
            {
                check = check + 1;
            }

        }

        if (strlen(invenItem.id) == 5)
        {
            printf("ID Accepted\n");
            break;
        }
        else
        {
            printf("Invalid Format\n");

        }

    } while (scan == true);



    //Item Desc
    printf("Enter the Item Description: ");
    scanf(" %[^\n]s", &invenItem.desc);
    getchar();
    printf("Successfully added Item Description.\n");

    //Product Quan
    do
    {
        printf("Product Quantity: ");
        scanf(invenItem.quan, 255);
        check = 0;
        for (x = 0; x != strlen(invenItem.quan); x++)
        {
            if ((isdigit(invenItem.quan[x]) == 0) || (invenItem.quan == '\0'))
            {
                printf("Invalid quantity, please try again.\n");
                break;
            }

            else
            {
                check = check + 1;
            }
        }

        if (check == strlen(invenItem.quan))
        {
            printf("Valid product Quantity.\n");
            break;
        }
    } while (scan == true);


    //Expiry Date
    printf("Enter Product Expiry(YYYY/MM/DD):\n");
    while (scan == true)
    {
        printf("Year: ");
        scanf(invenItem.yy, 255);
        check = 0;
        for (x = 0; x != 4; x++)
        {
            if ((isdigit(invenItem.yy[x]) == 0) || strlen(invenItem.yy) != 4 || (invenItem.yy == '\0'))
            {
                printf("Invalid year, please try again.\n");
                break;
            }

            else
            {
                check = check + 1;
            }

        }

        if (check == 4)
        {
            while (scan == true)
            {
                printf("Month: ");
                scanf(invenItem.mm, 255);
                mmHolder = atoi(invenItem.mm);
                for (x = 0; x != 2; x++)
                {
                    if ((isdigit(invenItem.mm[x]) == 0) || strlen(invenItem.dd) < 2 || (mmHolder > 12))
                    {
                        printf("Invalid Month, please try again.\n");
                        break;
                    }

                    else
                    {
                    }
                }

                if ((strlen(invenItem.mm) == 2) && (mmHolder >= 1) && (mmHolder <= 12))
                {
                    while (scan == true)
                    {
                        printf("Date: ");
                        scanf(invenItem.dd, 255);
                        ddHolder = atoi(invenItem.dd);
                        check = 0;
                        for (x = 0; x != 2; x++)
                        {
                            if ((isdigit(invenItem.dd[x]) == 0) || strlen(invenItem.dd) < 2 || (invenItem.dd == '\0') || (ddHolder > 31))
                            {
                                printf("Invalid Date, please try again.\n");
                                break;
                            }

                            else
                            {
                            }
                        }

                        if ((strlen(invenItem.dd) == 2) && (ddHolder >= 1 && ddHolder <= 31) && (mmHolder == 1 || mmHolder == 3 || mmHolder == 5 || mmHolder == 7 || mmHolder == 8 || mmHolder == 10 || mmHolder == 12))
                        {
                            printf("Date is valid.\n");
                            break;
                        }

                        else if ((strlen(invenItem.dd) == 2) && (ddHolder >= 1 && ddHolder <= 30) && (mmHolder == 4 || mmHolder == 6 || mmHolder == 9 || mmHolder == 11))
                        {
                            printf("Date is valid.\n");
                            break;
                        }

                        else if ((strlen(invenItem.dd) == 2) && (ddHolder >= 1 && ddHolder <= 28) && (mmHolder == 2))
                        {

                            printf("Date is valid.\n");
                            break;
                        }

                    }
                    break;
                }

                else
                {
                }
            }
            break;
        }

        else
        {

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

    // _itoa(invenItem.id, idCheck, 10); //convert int input to string
    // ID Checking if Product Exists
    while (!feof(inven))
    {
        x = getc(inven);
        fgets(str1, 255, inven);
        strncpy(str2, str1, 5);
        existID = strcmp(invenItem.id, str2);



        if (existID == 0)
        {
            printf("Product ID already Exists. Please try again.\n");
            break;
        }
    }

    if (existID != 0)
    {
        fprintf(inven, "\n\"%s\", \"%s\", \"%s\", \"%s-%s-%s\", \"%0.2f\"", invenItem.id, invenItem.desc, invenItem.quan, invenItem.yy, invenItem.mm, invenItem.dd, invenItem.price);
        printf("Successfully added a new product to the inventory.\n");
        printf("\n\"%s\", \"%s\", \"%s\", \"%s-%s-%s\", \"%0.2f\"", invenItem.id, invenItem.desc, invenItem.quan, invenItem.yy, invenItem.mm, invenItem.dd, invenItem.price);
    }
        
    
    
    

    fclose(inven);

}


void addItem2()
{
    char UId[32];
    char Desc[32];
    char Quantity[32];
    char DateExp[32];
    char Price[32];
    printf("-----------------------------\n");
    printf("   ADDING INVENTORY ITEM\n");
    printf("-----------------------------\n");
    
    printf("Enter Item ID: ");
    scanf("%s", &UId);
    printf("Enter Description: ");
    scanf("%s", &Desc);
    printf("Enter Quantity: ");
    scanf("%s", &Quantity);
    printf("Enter Date Expirey: ");
    scanf("%s", &DateExp);
    printf("Enter Price: ");
    scanf("%s", &Price);

    addInventory(UId,Desc,Quantity,DateExp,Price);

    // Display();



}

