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
    head = addToEmpty(head,0,"\"99999\"","Desc","Quantity","DateExp","Price\n");

}

void addInventory(char *UId,char *Desc,char *Quantity,char *DateExp,char *Price)
{
    head = addAtEnd(head,0,UId,Desc,Quantity,DateExp,Price);
}
struct Node* getHead()
{
    return head;
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

    while (strcmp(ptr->Id, temp->Id))
    {
//        printf("%s ,- %s\n",ptr->Id,temp->Id);
        if (ptr->next==NULL)
        {
            ptr=head;
            printf("This ID does not exist\n");
            break;
        }
//        if (strcmp(ptr->Id, temp->Id))
//        {   
//            break;
//        }
        ptr=ptr->next;
	}

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

void setId(struct Node* ptr,char UId[32])
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
                strncpy(UId, &token[0],7);
                UId[7] = '\0';
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
//                Price[strlen(token)-2] = '\"';
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
    // printf("pass\n"); 
    ptr = head;
    while (ptr != NULL)
    {
        printf("%s,%s,%s,%s,%s",ptr->Id,ptr->Desc,ptr->Quantity,ptr->DateExp,ptr->Price);
        ptr = ptr->next;
    }
}
/* Failed Sort
struct Node* getMid()
{
    struct Node* slow = head;
    struct Node* fast = head->next;

    while (fast!=NULL&&fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
    
    
}

struct Node* Merge(struct Node* first, struct Node* second)
{
    struct Node* dummy;
    struct Node* tail = getLast();

    int listVal1;
    int listVal2;

    sscanf(first->Id, "%d", &listVal1);//parses address into int
    sscanf(second->Id, "%d", &listVal2);//parses address into int

    while (first != NULL && second != NULL)
    {
        
        if (listVal1<listVal2)
        {   
            
            first -> next = Merge(first->next,second);
            first -> next -> prev = first;
            first -> prev = NULL;
            return first;
        }
        else
        {
            second->next = Merge(first,second->next);
            second->next->prev = second;
            second->prev = NULL;
            return second;
        }
    }
}

struct Node* Sort(struct Node* head)
{
    if (head==NULL)
    {
        // return head;
    }
    if (head->next==NULL)
    {
        // return head;
    }
    struct Node* second = getMid();

    head=Sort(head);
    second = Sort(second);

    return Merge(head,second);

}*/

void exportCsv()
{
    char str[255];
    FILE *fp;
    fp = fopen("Inventory_ST_NoBOM.csv", "w");
	/*
    ptr = head->next;
    while (ptr != NULL)
    {
        fprintf(fp,"%d,%s,%s,%s,%s,%s",ptr->data,ptr->Id,ptr->Desc,ptr->Quantity,ptr->DateExp,ptr->Price);
        ptr = ptr->next;
    }
    */
    struct Node *temp = head;
    // printf("Forward Traversal using next pointer\n");
    
    while (head)
    {	
    	if(strcmp(head->Id,"\"99999\"")){
    		fprintf(fp,"%s,%s,%s,%s,%s",head->Id,head->Desc,head->Quantity,head->DateExp,head->Price);
			temp = head;
	    	head = head->next;	
//    		break;
		}
		else{
			
	    	printf("last call");
    		head = head->next;
		}
      	
        	
        
    }
    // printf("\nBackward Traversal using prev pointer\n");
//    while (temp)
//    {
//        fprintf(fp,"%s,%s,%s,%s,%s",temp->Id,temp->Desc,temp->Quantity,temp->DateExp,temp->Price);
//        temp = temp->prev;
//    }
    fclose(fp);
}

//start merge sort
struct Node *split(struct Node *head);

struct Node *merge(struct Node *first, struct Node *second)
{
//	printf("Merge\n");
    // If first linked list is empty
    if (!first)
        return second;
 
    // If second linked list is empty
    if (!second)
        return first;
 
    int listVal1;
    int listVal2;
    
    char str1[32];
    char str2[32];
    
    strncpy(str1,&first->Id[1],5);
    strncpy(str2,&second->Id[1],5);

    sscanf(str1, "%d", &listVal1);//parses address into int
    sscanf(str2, "%d", &listVal2);//parses address into int
//    printf("%s<--->%s\n",str2,str1);
//    printf("%d[===]%d\n",&listVal2,&listVal1);

    // Pick the smaller value
    if (listVal1 < listVal2)
    {
        first->next = merge(first->next,second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    }
    else
    {
        second->next = merge(first,second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    }
}

struct Node *mergeSort(struct Node *head)
{
//	printf("Mergesorting\n");
    if (!head || !head->next)
        return head;
    struct Node *second = split(head);
 
    // Recur for left and right halves
    head = mergeSort(head);
    second = mergeSort(second);
    // Merge the two sorted halves
    return merge(head,second);
}
void print(struct Node *head)
{
    struct Node *temp = head;
    // printf("Forward Traversal using next pointer\n");
    while (head)
    {
//        printf("%s,%s,%s,%s,%s",head->Id,head->Desc,head->Quantity,head->DateExp,head->Price);
		temp = head;
    	head = head->next;
        	
        
    }
    // printf("\nBackward Traversal using prev pointer\n");
    while (temp)
    {
        printf("%s,%s,%s,%s,%s",temp->Id,temp->Desc,temp->Quantity,temp->DateExp,temp->Price);
        temp = temp->prev;
    }
}


void swap(int *A, int *B)
{
    int temp = *A;
    *A = *B;
    *B = temp;
}

struct Node *split(struct Node *head)
{
    struct Node *fast = head,*slow = head;
    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    struct Node *temp = slow->next;
    slow->next = NULL;
    return temp;
}