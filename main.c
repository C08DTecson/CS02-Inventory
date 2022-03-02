// #include "linkedList.h"
#include "linkedListUI.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{

    initializeList();
    addInventory("123","aaa","aaa","aaaa","aaaaa");
    importCsv();
    Display();

    return 0;
}