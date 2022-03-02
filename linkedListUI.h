#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node* head = NULL;
struct Node* ptr;

char *strtok(char *str, const char *delim);


void initializeList()
{
    head = NULL;
    head = addToEmpty(head,0,"ID","Desc","Quantity","DateExp","Price");

}

void addInventory(char *UId,char *Desc,char *Quantity,char *DateExp,char *Price){
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
    fp = fopen("Inventory_ST_NoBOM.csv", "r");
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
        printf("%s",str);       
        /* get the first token */
        token = strtok(str, s);
        
        /* walk through other tokens */
        addInventory("UId","Desc","Quantity","DateExp","Price");
        int count = 0;
        while( token != NULL ) {
            
            printf( "*%s\n", token );
            getLast();
            
            
            // printf("?%s\n",ptr->Id);

            switch (count)
            {
            case 0:
                strncpy(UId, &token[0],strlen(token));
                UId[strlen(token)] = '\0';
                printf("pass");
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
        printf("%d,%s,%s,%s,%s,%s\n",ptr->data,ptr->Id,ptr->Desc,ptr->Quantity,ptr->DateExp,ptr->Price);
        ptr = ptr->next;
    }
}
