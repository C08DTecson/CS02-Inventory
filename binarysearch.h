#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Inventory {
	int ID;
	char *Description;
	int Quantity;
	char *ExpiryDate;
	float Price; 
};

int searchItem()
{
    FILE* item;
    struct Inventory item1;
    item = fopen("inventory.csv", "r");
    char str1[255], str2[6];
    int invenData[255];
    int x, existID, dataConv=0, intLimit=0, test;
    int idCheck = 11202;
    while (!feof(item))
    {
        x = getc(item);
        fgets(str1,255,item);
        strncpy(str2,str1,5);
        //memmove(str2,str2 + 1, strlen(str2));
        //str2[sizeof(str2) - 1] = '\0';
        printf("%s\n", str2);
        dataConv = atoi(str2);
        invenData[intLimit++] = dataConv;
    }
    printf("%d\n", intLimit);
    int mid, low = 0, high = intLimit;
    for (test=0;test<10; test++)
    {
        mid = (low + high)/2;
        if (idCheck == invenData[mid]){
            printf("Valid ID Found");
            break;
        }
        else if (idCheck > invenData[mid]){
            low = mid + 1;
        }
        else if (idCheck < invenData[mid]){
            high = mid - 1;
        }
        else if (idCheck != invenData[mid]){
            printf("The ID does not exist.");
            break;
        }
    }
    fclose(item);
    return 0;
}