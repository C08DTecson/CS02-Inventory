#include "addItemV2.h"
#include "searchFunc.h"

int menuMain();
char userIn[2];
bool running = true;

int menuMain()
{

	printf("-----------------------------\n");
	printf("  GROUP 1 INVENTORY SYSTEM\n");
	printf("-----------------------------\n");
	printf("MAIN MENU\n");
	printf("[A] Add Inventory Item\n");
	printf("[B] Search Inventory Item\n");
	printf("[C] View Inventory List\n");
	printf("[X] Exit System\n\n");
	printf("Please enter your desired function:");

	do
	{
		
		scanf("%c", &userIn);
		if (strlen(userIn) == 1)
		{
			switch (userIn[0])
			{
			case 'a':
			case 'A':
				printf("Adding Inventory Item\n");
				system("cls");
				addItem2();
				Display();
				exportCsv();
				break;

			case 'b':
			case 'B':
				printf("Select Inventory Item: ");
				char userInU[32];
				char userInA[32];
				scanf("%s", &userInU);
				strcat(userInA,"\"");
				strcat(userInA,userInU);
				strcat(userInA,"\"");

				strncpy(userInU,&userInA[5],7);
				userInU[7] = '\0';
				
				
				printf("%s\n",userInU);

				// searchItem();
				struct Node* sample = malloc(sizeof(struct Node));
				char uSet[32]= "\"14105\"";
				setId(sample,userInU);
				sample = getNode(sample);
				printf("ID:%s\n[0]Description: %s\n[1]Quantity: %s\n[2]Best Before Date: %s\n[3]Price: %s\n[X]Cancel Update\n",sample->Id,sample->Desc,sample->Quantity,sample->DateExp,sample->Price);
				break;

			case 'c':
			case 'C':
				printf("Viewing Inventory List\n");
				
				// struct Node* head = getHead();
				head = mergeSort(head);	
				Display();
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