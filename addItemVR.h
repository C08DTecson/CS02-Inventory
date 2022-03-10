#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int addItem();
int priceCheck, existID, num, idInt;
char* checking[6];
char str1[255], str2[8], idCheck[5], userIn[2];
int yyHolder, mmHolder, ddHolder;
char buf[50] = { '\0' };
int x, check, ch;
bool scanID = true, scanDesc = true, scanQuan = true, scanPrice = true, scanDate = true;

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
        gets(invenItem.id);
        check = 0;
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

        if (check == 5)
        {
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
                printf("ID accepted.\n");
                break;
            }
        }

    } while (scanID == true);



    //Item Desc
    while (scanDesc == true)
    {
        printf("Enter the Item Description: ");
        gets(invenItem.desc);

        if (strlen(invenItem.desc) > 100)
        {
            printf("Character Limit exceeded\n");
        }

        else
        {
            printf("Successfully added Item Description.\n");
            break;
        }
    }
    //Product Quan
    do
    {
        printf("Product Quantity: ");
        gets(invenItem.quan);
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
    } while (scanQuan == true);


    //Expiry Date
    printf("Enter Product Expiry(YYYY/MM/DD):\n");
    while (scanDate == true)
    {
        printf("Year: ");
        gets(invenItem.yy);
        check = 0;
        for (x = 0; x != 4; x++)
        {
            if ((isdigit(invenItem.yy[x]) == 0) || strlen(invenItem.yy) != 4 || (invenItem.yy == '\0')|| strlen(invenItem.yy) <= 0)
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
            printf("Valid Year.\n");
            while (scanDate == true)
            {
                printf("Month: ");
                gets(invenItem.mm);
                mmHolder = atoi(invenItem.mm);
                for (x = 0; x != 2; x++)
                {
                    if ((isdigit(invenItem.mm[x]) == 0) || strlen(invenItem.mm) < 2 || (mmHolder > 12))
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
                    while (scanDate == true)
                    {
                        printf("Date: ");
                        gets(invenItem.dd);
                        ddHolder = atoi(invenItem.dd);
                        check = 0;
                        for (x = 0; x != 2; x++)
                        {
                            if ((isdigit(invenItem.dd[x]) == 0) || (strlen(invenItem.dd) < 2) || (ddHolder > 31))
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

                        else if ((strlen(invenItem.dd) == 2) && (ddHolder == 29 ) && (mmHolder == 2) && ((yyHolder % 400 == 0) || (yyHolder % 4 == 0) && (yyHolder % 100 != 0)))
                        {

                            printf("Date is valid (Leap Year).\n");
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
    while (scanPrice == true)
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

    //_itoa(invenItem.id, idCheck, 10); //convert int input to string
    
    //ID Checking if Product Exists
   
    fprintf(inven, "\n\"%s\",\"%s\",\"%s\",\"%s-%s-%s\",\"%0.2f\"", invenItem.id, invenItem.desc, invenItem.quan, invenItem.yy, invenItem.mm, invenItem.dd, invenItem.price);
    printf("Successfully added a new product to the inventory.\n");
    printf("\"%s\",\"%s\",\"%s\",\"%s-%s-%s\",\"%0.2f\"", invenItem.id, invenItem.desc, invenItem.quan, invenItem.yy, invenItem.mm, invenItem.dd, invenItem.price);
    fclose(inven);

    printf("\nWould you like to add another item? (Y/N): ");
    gets(userIn);
    if (strlen(userIn) == 1)
    {
        switch (userIn[0])
        {
            case 'Y':
            case 'y':
                system("cls");
                addItem();
                break;

            case 'N':
            case 'n':
                system("cls");
                menuMain();
                break;

        }
    }

    else
    {
        printf("Invalid input, please try again.");
    }
}

