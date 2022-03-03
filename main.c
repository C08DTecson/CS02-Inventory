// #include "linkedList.h"
#include "linkedListUI.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
        DELTE THIS ONCE PUSHING TO DEV
    */
    initializeList();
    importCsv();
    addInventory("000123","aaa","aaa","aaaa","aaaaa");
    struct Node* sample;

    strncpy(sample->Id,"11107",5);
    sample->Id[5]= '\0';

    printf("%s\n",sample->Id);

    sample = getNode(sample);
    printf("%s<>%s",sample->Id,sample->Desc);

    
    // Display();
    // exportCsv();

    return 0;
}