
#include "addItemV3.h"
//#include "addItemV2.h"
//#include "searchFunc.h"
#include "searchItem.h"
#include "updateItem.h"

int menuMain();
char userIn[2];
bool running = true;

int menuMain()
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

	do
	{
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

				break;

			case 'b':
			case 'B':
        //Estoconing
				//system("cls");
        //updateItem();

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
				break;

			case 'c':
			case 'C':
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
				break;

            case 'd':
            case 'D':
                system("cls");
				searchItem();
				break;


			case 'x':
			case 'X':
				printf("Thank you for using the G1 Inventory System!\n");
				break;

			default:
				printf("Invalid Input, please try again.\n");
				continue;
			}
			break;
		}

		else
		{
			printf("Invalid input, please try again.\n");
		}
		
		;//exits the do while loop when a valid input is selected.
	} while (running == true); //To keep entering an input until it is valid

}