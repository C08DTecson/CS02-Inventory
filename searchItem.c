    
    
    
    
    printf("Select Inventory Item: ");
				char userInU[32];
				char userInA[32];
				scanf("%s", &userInU);
				strcat(userInA,"\"");
				strcat(userInA,userInU);
				strcat(userInA,"\"");

				strncpy(userInU,&userInA[5],7);
				userInU[7] = '\0';
				
				// printf("%s\n",userInU);

				// searchItem();
				struct Node* sample = malloc(sizeof(struct Node));
				// char uSet[32]= "\"14105\"";
				setId(sample,userInU);
				sample = getNode(sample);
				printf("ID:%s\n[0]Description: %s\n[1]Quantity: %s\n[2]Best Before Date: %s\n[3]Price: %s\n[X]Cancel View\n",sample->Id,sample->Desc,sample->Quantity,sample->DateExp,sample->Price);
				break;