//#include "addItemV2.h"
//#include "searchFunc.h"
#include "searchItem.h"
#include "updateItem.h"

int menuMain();
char userIn[2];


int menuMain()
{
	int running = 0;
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
				// Display();
				// exportCsv();
				running = 2;
				break;

			case 'b':
			case 'B':
				system("cls");
                updateItem();
				running = 2;
				break;

			case 'c':
			case 'C':
				printf("Viewing Inventory List\n");
				
				// struct Node* head = getHead();
				head = mergeSort(head);	
				print(head);
				// Display();
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