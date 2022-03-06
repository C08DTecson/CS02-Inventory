// #include "linkedList.h"
// #include "linkedListUI.h"
#include "mainMenu.h"

// #include <stdio.h>
// #include <stdlib.h>


int main()
{
    initializeList();
    importCsv();
    

    // struct Node* head = getHead();
    // head = mergeSort(head);
    // print(head);
    
    // addInventory("00123","aaa","aaa","aaaa","aaaaa");
    // struct Node* sample;
    // setId(sample,"14105");
    // sample = getNode(sample);
    // printf("%s<>%s",sample->Id,sample->Desc);

    // strncpy(sample->Id,"12102",5);
    // sample->Id[5]= '\0';
    // printf(">>>%s<<<\n",sample->Id);

    // Display();
    // exportCsv();

    menuMain();

    exportCsv();


    return 0;
}
