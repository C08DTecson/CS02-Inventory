#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedListUI.h"
#include <stdbool.h>

int searchItem();

int searchItem()
{
    int loopSearch=0, flushScan, verifyNo=0, lengthString=0;
    char verify[2];
    char userInI[32];
    char userInU[32];
	char userInA[32];
				
	// printf("%s\n",userInU);

	// searchItem();
	
	// char uSet[32]= "\"14105\"";
    while(loopSearch != 1)
    {
        printf("-----------------------------\n");
	    printf("  SEARCHING INVENTORY ITEM\n");
	    printf("-----------------------------\n");
        printf("Select Inventory Item: ");
        memset(userInU,0,strlen(userInU));
        scanf("%5s", &userInU);
        while ((flushScan = fgetc(stdin)) != '\n' && flushScan != EOF); /* Flush stdin */
	    strcat(userInA,"\"");
	    strcat(userInA,userInU);
	    strcat(userInA,"\"");
        //printf("%s\n", userInA);
        
        //if additional characters are received, change value of 0 in the next line.
	    strncpy(userInU,&userInA[0+lengthString],(7+lengthString)); 
        //printf("%s\n", userInU);
	    userInU[7] = '\0';
        //printf("%s\n", userInU);
        struct Node* sample = malloc(sizeof(struct Node));
        setId(sample,userInU);
	    sample = getNode(sample);
        if (sample != head){
            printf("ID:%s\n[0]Description: %s\n[1]Quantity: %s\n[2]Best Before Date: %s\n[3]Price: %s\n",sample->Id,sample->Desc,sample->Quantity,sample->DateExp,sample->Price);
        }
        do
        {
            printf("\nWould you like to search for another item [Y/N]? ");
            scanf("%1s", &verify);
            while ((flushScan = fgetc(stdin)) != '\n' && flushScan != EOF); /* Flush stdin */
            switch (verify[0])
                {
                    case 'Y':
                    case 'y':
                        lengthString = lengthString + 7;
                        verifyNo = 1;
                        system("cls");
                        break;

                    case 'N':
                    case 'n':
                        loopSearch = 1;
                        verifyNo = 1;
                        break;
                    default:
                        printf("Invalid input. please try again.\n");
                        verifyNo = 2;
                        break;
                }
        } while (verifyNo != 1);
        
    }
	
    return 0;
}