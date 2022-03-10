#include "addItemV3.h"
//#include "addItemV2.h"
//#include "searchFunc.h"
#include "searchItem.h"
#include "updateItem.h"

int menuMain();
char userIn[2];


int menuMain()
{
	int running = 0;
	char verify1[2];
    do
	{
		system("cls");
		printf("-----------------------------\n");
		printf("  GROUP 1 INVENTORY SYSTEM\n");
		printf("-----------------------------\n");
		printf("MAIN MENU\n");
		printf("[A] Add Inventory Item\n");
		printf("[B] Update Inventory Item\n");
		printf("[C] View Inventory List\n");
		printf("[D] Search Inventory Item\n");
		printf("[X] Exit System\n\n");
		printf("Please enter your desired function:");

	
		
		gets(userIn);
		if (strlen(userIn) == 1)
		{
			switch (userIn[0])
			{
			case 'a':
			case 'A':
				printf("Adding Inventory Item\n");
				system("cls");
				addItem();

	//        addItemV3
				// Display();
				// exportCsv();
				running = 2;
				break;

			case 'b':
			case 'B':

				system("cls");
                updateItem();
				running = 2;

        		//Estoconing
				//system("cls");
        		//updateItem();
				
				/*
				printf("Select Inventory Item: ");
				char userInU[32];
				char userInA[32];
				scanf("%s", &userInU);
				strcat(userInA,"\"");
				strcat(userInA,userInU);
				strcat(userInA,"\"");

				strncpy(userInU,&userInA[3],7);
				userInU[7] = '\0';
				
//				printf("%s\n",userInU);

				// searchItem();
				struct Node* sample = malloc(sizeof(struct Node));
				// char uSet[32]= "\"14105\"";
				setId(sample,userInU);
				sample = getNode(sample);
//				printf("%s",sample->Id);

//				printf("%sSID\n",sample->Id);
				
				if(strcmp(sample->Id, "\"99999\""))
				{
//					printf("pass a\n");
					printf("ID:%s\n[0]Description: %s\n[1]Quantity: %s\n[2]Best Before Date: %s\n[3]Price: %s\n[X]Cancel View\n",sample->Id,sample->Desc,sample->Quantity,sample->DateExp,sample->Price);
				}
				else
				{
					printf("This does not exist\n");
//					printf("ID:%s\n[0]Description: %s\n[1]Quantity: %s\n[2]Best Before Date: %s\n[3]Price: %s\n[X]Cancel View\n",sample->Id,sample->Desc,sample->Quantity,sample->DateExp,sample->Price);
				}
				*/

				break;

			case 'c':
			case 'C':
				
				do
				{
					
					printf("Viewing Inventory List\n");
					// struct Node* head = getHead();
					if(head->next==NULL)
					{
						printf("This list is empty");
					}
					else
					{
						head = mergeSort(head);	
						print(head);
					}
					
					// Display();
					printf("[Input X to close list]");
					scanf("%1s", &verify1);
					
					
				}while(strcmp(&verify1[0],"x"));
				
				running = 2;
				break;

            case 'd':
            case 'D':
                system("cls");
				searchItem();
				running = 2;
				break;

			case 'x':
			case 'X':
				printf("Thank you for using the G1 Inventory System!\n");
				running = 1;
				break;

			default:
				printf("Invalid Input, please try again.\n");
				continue;
			}
		}

		else
		{
			printf("Invalid input, please try again.\n");
		}
		
		//exits the do while loop when a valid input is selected.
	} while (running != 1); //To keep entering an input until it is valid

}