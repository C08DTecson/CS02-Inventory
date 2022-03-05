//#include "addItemV2.h"
//#include "searchFunc.h"
#include "searchItem.h"

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
		
		gets(userIn);
		if (strlen(userIn) == 1)
		{
			switch (userIn[0])
			{
			case 'a':
			case 'A':
				printf("Adding Inventory Item\n");
				system("cls");
				//addItem();
				// Display();
				// exportCsv();
				break;

			case 'b':
			case 'B':
				system("cls");
                searchItem();
				break;

			case 'c':
			case 'C':
				printf("Viewing Inventory List\n");
				
				// struct Node* head = getHead();
				head = mergeSort(head);	
				print(head);
				// Display();
				break;

            case 'd':
            case 'D':
                system("cls");
                //updateItem();

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