#include <stdio.h>
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
    int x;
    while (x != EOF)
    {
        x = getc(item);
        fgets(str1,255,item);
        printf("%s\n",str1);
        strncpy(str2,str1,5);
        str2[sizeof(str2)-1]='\0';
        printf("%s\n", str2);
    };
    fclose(item);
    return 0;
}