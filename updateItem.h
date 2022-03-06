
int updateItem();

int updateItem()
{
    printf("-----------------------------\n");
	printf("   UPDATING INVENTORY ITEM\n");
	printf("-----------------------------\n");

    int chooseItem, flushScan, verifyUNo=0, lengthStringU=0;
    int loopSearchU = 0, loopUpdate=0, detailUpdate=0, loopAnotherUpdate=0, loopVerifyU=0;
    char verifyU[2], update[2];
    char userInX[32];
	char userInY[32];
    char dataIn[128];
				
	// printf("%s\n",userInX);

	// searchItem();
	
	// char uSet[32]= "\"14105\"";
    while(loopSearchU != 1)
        {
        printf("Select Inventory Item: ");
        memset(userInX,0,strlen(userInX));
        scanf("%5s", &userInX);
        while ((flushScan = fgetc(stdin)) != '\n' && flushScan != EOF); /* Flush stdin */
	    strcat(userInY,"\"");
	    strcat(userInY,userInX);
	    strcat(userInY,"\"");
        //printf("%s\n", userInY);
        
        //if additional characters are received, change value of 0 in the next line.
	    strncpy(userInX,&userInY[0+lengthStringU],(7+lengthStringU)); 
        //printf("%s\n", userInX);
	    userInX[7] = '\0';
        //printf("%s\n", userInX);
        struct Node* sampleU = malloc(sizeof(struct Node));
        setId(sampleU,userInX);
	    sampleU = getNode(sampleU);
        if (sampleU != head){
            printf("ID:%s\n[0]Description: %s\n[1]Quantity: %s\n[2]Expiry Date: %s\n[3]Price: %s\n",sampleU->Id,sampleU->Desc,sampleU->Quantity,sampleU->DateExp,sampleU->Price);
        }
        do
        {
            do
            {
                printf("What detail would you like to update [0-3]?\n");
                scanf("%1d", &chooseItem);
                while ((flushScan = fgetc(stdin)) != '\n' && flushScan != EOF); /* Flush stdin */
                if (chooseItem >= 0 && chooseItem < 4)
                {
                    switch (chooseItem)
                    {
                        case 0:
                            printf("---Updating Description---\n");
                            printf("Enter Data: ");
                            scanf("%[^\n]s", dataIn);
                            printf("%s\n", dataIn);
                            setDes(sampleU, dataIn);
                            break;
                        case 1:
                            printf("---Updating Quantity---\n");
                            printf("Enter Data: ");
                            scanf("%[^\n]s", dataIn);
                            printf("%s\n", dataIn);
                            setQuantity(sampleU, dataIn);
                            break;
                        case 2:
                            printf("---Updating Expiry Date---\n");
                            printf("Enter Data: ");
                            scanf("%[^\n]s", dataIn);
                            printf("%s\n", dataIn);
                            setExp(sampleU, dataIn);
                            break;
                        case 3:
                            printf("---Updating Price---\n");
                            printf("Enter Data: ");
                            scanf("%[^\n]s", dataIn);
                            printf("%s\n", dataIn);
                            setPrice(sampleU, dataIn);
                            break;
                    }

                    detailUpdate = 1;
                }
                else
                {
                    printf("Invalid Input. Please Try Again!");
                    detailUpdate = 2;
                }
                
            } while (detailUpdate !=1);
            
            
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
            scanf("%1s", &verifyU);
            while ((flushScan = fgetc(stdin)) != '\n' && flushScan != EOF); /* Flush stdin */
            switch (verifyU[0])
                {
                    case 'Y':
                    case 'y':
                        lengthStringU = lengthStringU + 7;
                        verifyUNo = 1;
                        break;

                    case 'N':
                    case 'n':
                        loopSearchU = 1;
                        verifyUNo = 1;
                        break;
                    default:
                        printf("Invalid input. please try again.\n");
                        verifyUNo = 2;
                        break;
                }
        } while (verifyUNo != 1);
        
    }
	
    return 0;
}