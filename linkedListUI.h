#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node* head = NULL;
struct Node* ptr;

char *strtok(char *str, const char *delim);
int strcmp (const char* str1, const char* str2);


void initializeList()
{
    head = NULL;
    head = addToEmpty(head,0,"ID","Desc","Quantity","DateExp","Price");

}

void addInventory(char *UId,char *Desc,char *Quantity,char *DateExp,char *Price)
{
    head = addAtEnd(head,0,UId,Desc,Quantity,DateExp,Price);
}

struct Node* getLast()
{
    ptr=head;
    while (ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    
    return ptr;
}

struct Node* getNode(struct Node* temp)
{
   ptr=head;

//    while (strcmp(ptr->Id, temp->Id))
//    {
//        printf("%s ,- %s\n",ptr->Id,temp->Id);
//        if (ptr->next==NULL)
//        {
//            break;
//        }
//        if (ptr->Id == temp->Id)
//        {   
//             break;
//        }
//        ptr=ptr->next;
//    }

    // int a;   
    // sscanf(ptr->Id, "%d", &a);//parses address into int
    // int b;
    // sscanf(temp->Id, "%d", &b);//parses address into int

    // int idCheck = b;
    // int mid, low = 0, high = intLimit;
    // for (int test=0; test < (99999/2); test++)
    // {
    //     mid = (low + high)/2;
    //     if (idCheck == invenData[mid]){
    //         printf("Valid ID Found");
    //         break;
    //     }
    //     else if (idCheck > invenData[mid]){
    //         low = mid + 1;
    //     }
    //     else{
    //         high = mid - 1;
    //     }
    // }

   return ptr;
}

void setId(struct Node* ptr,char *UId)
{
    strcpy(ptr->Id, UId);
}

void setDes(struct Node* ptr,char *Desc)
{
    strcpy(ptr->Desc, Desc);
}

void setQuantity(struct Node* ptr,char *Quantity)
{
    strcpy(ptr->Quantity,Quantity);
}

void setExp(struct Node* ptr,char *DateExp)
{
    strcpy(ptr->DateExp,DateExp);
}

void setPrice(struct Node* ptr,char *Price)
{
    strcpy(ptr->Price,Price);
}

void importCsv()
{
    char str[255];
    FILE *fp;
    fp = fopen("Inventory.csv", "r");
    const char s[2] = ",";

    char *token;

    char UId[32];
    char Desc[32];
    char Quantity[32];
    char DateExp[32];
    char Price[32];

    

    if(fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    while( fgets(str, 255, fp) != NULL )
    {
        //this print is used to identify line
        // printf("%s",str);       
        /* get the first token */
        token = strtok(str, s);
        
        /* walk through other tokens */
        addInventory("UId","Desc","Quantity","DateExp","Price");
        int count = 0;
        while( token != NULL ) {
            
            //this print is used to identify token
            // printf( "*%s\n", token );
            getLast();
            // printf("?%s\n",ptr->Id);

            switch (count)
            {
            case 0:
                strncpy(UId, &token[1],5);
                UId[5] = '\0';
                setId(ptr,UId);
                break;
            case 1:
                strncpy(Desc, &token[0],strlen(token));
                Desc[strlen(token)] = '\0';

                setDes(ptr,Desc);
                break;
            case 2:
                strncpy(Quantity, &token[0],strlen(token));
                Quantity[strlen(token)] = '\0';

                setQuantity(ptr,Quantity);
                break;
            case 3:
                strncpy(DateExp,&token[0],strlen(token));
                DateExp[strlen(token)] = '\0';

                setExp(ptr,DateExp);
                break;
            case 4:
                strncpy(Price,&token[0],strlen(token));
                Price[strlen(token)-1] = '\n';
                Price[strlen(token)] = '\0';

                setPrice(ptr,Price);
                
                break;
            
            default:
                count = 0;
                break;
            }
            token = strtok(NULL, s);
            count++;
        }
        
    }

    fclose(fp);
}

void Display()
{
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d,%s,%s,%s,%s,%s",ptr->data,ptr->Id,ptr->Desc,ptr->Quantity,ptr->DateExp,ptr->Price);
        ptr = ptr->next;
    }
}

void exportCsv()
{
    char str[255];
    FILE *fp;
    fp = fopen("Inventory_ST_NoBOM1.csv", "w");

    ptr = head->next;
    while (ptr != NULL)
    {
        fprintf(fp,"%d,%s,%s,%s,%s,%s",ptr->data,ptr->Id,ptr->Desc,ptr->Quantity,ptr->DateExp,ptr->Price);
        ptr = ptr->next;
    }
    fclose(fp);
}
