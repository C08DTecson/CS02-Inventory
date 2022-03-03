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

int main()
{
    FILE* item;
    struct Inventory item1;
    item = fopen("inventory.csv", "r");
    char str1[255], str2[6];
    int invenData[255];
    int x, dataConv=0, intLimit=0;
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

    //binary searching for integers. IDs set at integer array
    printf("%d\n", intLimit);
    int idCheck = 31202, test;
    int mid, low = 0, high = intLimit;
    for (test=0;test<10; test++)
    {
        mid = (low + high)/2;
        if (idCheck == invenData[mid]){
            printf("Valid ID Found"); 
            break; //return mid;
        }
        else if (idCheck > invenData[mid]){
        low = mid + 1;
        }
        else {
        high = mid - 1;
        }
        if (low > high){
            printf("ID not found. Please Enter again.");
            break;
        }
    }

    //binary searching for strings
    char strArray[100], ID_str[8];
    low=0;
    high=strlen(strArray)-1;
    while(low<=high){
        mid=(low+high)/2;
        if (strcmp(ID_str,strArray[mid])==0)
        {
            printf("key found at the position %d\n",mid+1);
            break;
        }
        else if(strcmp(ID_str,strArray[mid])>0)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
        if (low>high){
            printf("ID not found\n");
            break;
        }
        
    }
    fclose(item);
    return 0;
}