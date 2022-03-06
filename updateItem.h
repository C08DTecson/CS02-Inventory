#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedListUI.h"
#include <stdbool.h>

int updateItem();

int updateItem()
{
    printf("-----------------------------\n");
	printf("   UPDATING INVENTORY ITEM\n");
	printf("-----------------------------\n");

    int loopSearch=0, flushScan, verifyNo=0, lengthString=0;
    int chooseItem, loopUpdate=0, loopAnotherUpdate=0;
    char verify[2], update[2];
    char userInU[32];
	char userInA[32];
    char dataIn[128];
				
	// printf("%s\n",userInU);

	// searchItem();
	
	// char uSet[32]= "\"14105\"";
    while(loopSearch != 1)
        {
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
        struct Node* sampleU = malloc(sizeof(struct Node));
        setId(sampleU,userInU);
	    sampleU = getNode(sampleU);
        if (sampleU != head){
            printf("ID:%s\n[0]Description: %s\n[1]Quantity: %s\n[2]Expiry Date: %s\n[3]Price: %s\n",sample->Id,sample->Desc,sample->Quantity,sample->DateExp,sample->Price);
        }
        do
        {
            printf("What detail would you like to update [0-3]?\n");
            scanf("%1d", &chooseItem);
            while ((flushScan = fgetc(stdin)) != '\n' && flushScan != EOF); /* Flush stdin */
            printf("%d", chooseItem);
            switch (chooseItem)
            {
              case '0':
                    printf("---Updating Description---\n");
                    printf("Enter Data: ");
                    scanf("%[^\n]s", dataIn);
                    printf("%s", dataIn);
                    setDes(sampleU, dataIn);
                    break;
                case '1':
                    printf("---Updating Quantity---\n");
                    printf("Enter Data: ");
                    scanf("%[^\n]s", dataIn);
                    printf("%s", dataIn);
                    setQuantity(sampleU, dataIn);
                 break;
                case '2':
                    printf("---Updating Expiry Date---\n");
                    printf("Enter Data: ");
                    scanf("%[^\n]s", dataIn);
                    printf("%s", dataIn);
                    setExp(sampleU, dataIn);
                    break;
                case '3':
                    printf("---Updating Price---\n");
                    printf("Enter Data: ");
                    scanf("%[^\n]s", dataIn);
                    printf("%s", dataIn);
                    setPrice(sampleU, dataIn);
                   break;
            }
            do
            {
                printf("Would you like to update another detail [Y/N]?\n");
                scanf("%1s", &update);
                while ((flushScan = fgetc(stdin)) != '\n' && flushScan != EOF); /* Flush stdin */
                switch (update[0])
                    {
                        case 'Y':
                        case 'y':
                            loopUpdate = 2;
                            loopAnotherUpdate = 1;
                            break;

                        case 'N':
                        case 'n':
                            loopUpdate = 1;
                            loopAnotherUpdate = 1;
                            break;
                        default:
                            printf("Invalid input. please try again.\n");
                            loopAnotherUpdate = 2;
                            break;
                    }
            } while (loopAnotherUpdate !=1);
            
            
        } while (loopUpdate != 1);
        
        
        do
        {
            printf("Would you like to search for another item [Y/N]?\n");
            scanf("%1s", &verify);
            while ((flushScan = fgetc(stdin)) != '\n' && flushScan != EOF); /* Flush stdin */
            switch (verify[0])
                {
                    case 'Y':
                    case 'y':
                        lengthString = lengthString + 7;
                        verifyNo = 1;
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