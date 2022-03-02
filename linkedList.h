#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
  char Id[32];
  char Desc[32];
  char Quantity[32];
  char DateExp[32];
  char Price[32];

  int data;
  struct Node *next;
  struct Node *prev;
};


/*  Function Name   :
    Description     :
    Parameters      :
    Returns         :
    Remarks         :
*/

/*  Function Name   : addToEmpty
    Description     : This happens when the list is 
                        empty so it adds the first 
                        node and assigns it to the head   
    Parameters      : (struct Node, int)
    Returns         : Node head
    Remarks         : We return the node in order to 
                        assign it to the Node that was 
                        initialized because the things 
                        that happen in this function 
                        stay local and passing them 
                        will "affect" global variables
    
*/
struct Node* addToEmpty(struct Node* head, int data, char *Id, char *Desc, char *Quantity, char *DateExp, char *Price)
{
    struct Node* temp = malloc(sizeof(struct Node));
    temp->next = NULL;
    temp->prev = NULL;
    temp->data = data;
    //printf("%s,%s,%s,%s,%s first Node Insert\n",Id,Desc,Quantity,DateExp,Price);
    strcpy(temp->Id, Id);
    strcpy(temp->Desc, Desc);
    strcpy(temp->Quantity, Quantity);
    strcpy(temp->DateExp, DateExp);
    strcpy(temp->Price, Price);

    head = temp;
    return head;
}

/*  Function Name   : addAtBeginning
    Description     : Adds a new node at the head of the list
    Parameters      :
    Returns         :
    Remarks         :
*/
struct Node* addAtBeg(struct Node* head, int data, char *Id, char *Desc, char *Quantity, char *DateExp, char *Price)
{
    struct Node* temp = malloc(sizeof(struct Node));
    temp->next = NULL;
    temp->prev = NULL;
    temp->data = data;
    strcpy(temp->Id, Id);
    strcpy(temp->Desc, Desc);
    strcpy(temp->Quantity, Quantity);
    strcpy(temp->DateExp, DateExp);
    strcpy(temp->Price, Price);

    temp->next = head;
    head = temp;
    return head;
}

/*  Function Name   : addAfterPos
    Description     :
    Parameters      :
    Returns         :
    Remarks         :
*/
struct Node* addAfterPos(struct Node* head, int data, int pos, char *Id, char *Desc, char *Quantity, char *DateExp, char *Price)
{
    struct Node* newP = NULL;
    struct Node* temp = head;       //this one is used to traverse the list
    struct Node* temp2 = NULL;      //this one is the node where to stop
    newP = addToEmpty(newP,data,Id,Desc,Quantity,DateExp,Price);   //head is now transferred to the new node while temp points at head. the node is created and not garbaged since may ga reference sa iya

    while (pos != 1)
    {
        temp= temp->next;
        pos--;
    }
    if (temp->next==NULL)
    {
        temp->next= newP;
        newP->prev= temp;
    }
    else
    {
        temp2 = temp->next;
        temp->next = newP;
        temp2->prev = newP;
        
        newP->next = temp2;
        newP->prev = temp;
    }
    return head;
}

/*  Function Name   : addBeforePos
    Description     :
    Parameters      :
    Returns         :
    Remarks         :
*/
struct Node* addBeforePos(struct Node* head, int data, int pos, char *Id, char *Desc, char *Quantity, char *DateExp, char *Price)
{
    struct Node* newP = NULL;
    struct Node* temp = head;
    struct Node* temp2 = NULL;

    newP = addToEmpty(newP,data,Id,Desc,Quantity,DateExp,Price);

    int position = pos;
    while (position>2)
    {
        temp = temp->next;
        pos--;
    }
    if (position == 1)
    {
        head = addAtBeg(head,data,Id,Desc,Quantity,DateExp,Price);
    }
    else
    {
        temp2 = temp->next;
        temp->next = newP;
        temp2->prev = newP;

        newP->next = temp2;
        newP->prev = temp;
    }

    return head;
}

/*  Function Name   : addAtEnd
    Description     :
    Parameters      :
    Returns         :
    Remarks         :
*/
struct Node* addAtEnd(struct Node* head, int data, char *Id, char *Desc, char *Quantity, char *DateExp, char *Price)
{
    struct Node* temp, *tp;
    temp = malloc(sizeof(struct Node));
    
    temp->prev = NULL;
    temp->next = NULL;
    temp->data = data;
    strcpy(temp->Id, Id);
    strcpy(temp->Desc, Desc);
    strcpy(temp->Quantity, Quantity);
    strcpy(temp->DateExp, DateExp);
    strcpy(temp->Price, Price);

    // printf("%s,%s,%s,%s,%s End Node Insert\n",Id,Desc,Quantity,DateExp,Price);

    tp = head;

    while (tp->next != NULL)
    {
        tp = tp->next;
    }

    tp->next = temp;
    temp->prev = tp;

    return head;
    
}

/*  Function Name   : strtok
    Description     : needed for tokenizer when spliting data
    Parameters      :
    Returns         :
    Remarks         :
*/
char *strtok(char *str, const char *delim);

/*
int main()
{
    /*
    // Creating Head
    strunt Node *head = malloc(sizeof(struct Node)); // Construct and Init

    head->next = NULL;  //default value
    head->prev = NULL;  //default value
    head->data = 0;     //default value
    

    struct Node* head = NULL;
    struct Node* ptr;

    //head = addToEmpty(head,45);
    //head = addAtBeg(head,34);
    //head = addAtBeg(head,36);
    //head = addAtBeg(head,37);

    ///* Start of FileAccess

    char line[255];
    FILE * fpointer = fopen("inventory.csv","r");
    
    //Used to write into code
    //fprintf(fpointer, "000001, Test, 100, 2022-01-01, 1.00\n"); 
    
    //Gets the sizeof
    // fseek(fpointer, 0L, SEEK_END);
    // int size = ftell(fpointer);
    // printf("%d\n",size);
    // fseek(fpointer, 0L, SEEK_SET);

    //Prints each line
    const char s[2]=",";
    char *token;
    char *token2;

    

    head = addToEmpty(head,0,"Id","Desc","Quantity","DateExp","Price");
    int once = 0;

    while (fgets(line, 255, fpointer)!=NULL)
    {
        int count=0;
        token = strtok(line,s);
        char UId[32];
        char Desc[32];
        char Quantity[32];
        char DateExp[32];
        char Price[32];

        while (token!=NULL)
        {
            switch (count)
            {
            case 0:
                if (once<1)
                {
                    printf("%c<<0>>%c --  %s\n",token[3],token[strlen(token)-1],token);
                    strncpy(UId, &token[4],(strlen(token)-5));
                    UId[(strlen(token)-5)] = '\0';
                    // printf("^^ %s ^^\n",token2);
                    // printf("%s,%s,%s,%s,%s\n",UId,Desc,Quantity,DateExp,Price);
                    // UId = token2;
                    once++;
                }
                else
                {
                    printf("%c<<>>%c --  %s\n",token[0],token[strlen(token)-1],token);
                    strncpy(UId, &token[1],(strlen(token)-2));
                    UId[(strlen(token)-2)] = '\0';
                    // printf("^^ %s ^^\n",token2);
                    // printf("%s,%s,%s,%s,%s\n",UId,Desc,Quantity,DateExp,Price);
                    // UId = token2;

                }
                break;
                  
            case 1:
                printf("%c<<1>>%c --  %s\n",token[0],token[strlen(token)-1],token);
                strncpy(Desc, &token[1],(strlen(token)-2));
                Desc[(strlen(token)-2)] = '\0';
                // printf("^^ %s ^^\n",token2);
                // Desc = token2;
                break;
            case 2:
                printf("%c<<2>>%c --  %s\n",token[0],token[strlen(token)-1],token);
                strncpy(Quantity, &token[1],(strlen(token)-2));
                Quantity[(strlen(token)-2)] = '\0';
                // printf("^^ %s ^^\n",token2);
                // Quantity = token2;
                break;
            case 3:
                printf("%c<<3>>%c --  %s\n",token[0],token[strlen(token)-1],token);
                strncpy(DateExp, &token[1],(strlen(token)-2));
                DateExp[(strlen(token)-2)] = '\0';
                // printf("^^ %s ^^\n",token2);
                // DateExp = token2;
                break;
            case 4:
                printf("%c<<4>>%c --  %s\n",token[0],token[strlen(token)-3],token);
                strncpy(Price, &token[1],(strlen(token)-4));
                Price[(strlen(token)-4)] = '\0';
                // printf("^^ %s ^^\n",token2);
                // Price = token2;
                printf("END NODE PRINT: %s,%s,%s,%s,%s\n",UId,Desc,Quantity,DateExp,Price);

                head = addAtEnd(head,0,UId,Desc,Quantity,DateExp,Price);
                break;
            default:
                    
                break;
            }
            token=strtok(NULL,s);
            count++;
        }

        // printf("ADD TO END:%s,%s,%s,%s,%s\n",UId,Desc,Quantity,DateExp,Price);
        // printf("%s",line);
        // head = addAtEnd(head,0,line);
        
        
    }
        
        //printf("%s\n",line);
    
    // head = NULL;
    // head = addToEmpty(head,0,"11101","Nat. Spring (500mL)","200","-","10.50");//testing
    // head = addAtEnd(head,0,"11201","Nat. Spring (1L)","100","-","16.00");
    // head = addAtEnd(head,0,"11202","Nat. Spring (1L)","300","-","16.50");
    // head = addAtEnd(head,0,"12101","Datu Puti Vinegar (1L)","100"  ,"2022-03-22","38.25");
    // head = addAtEnd(head,0,"51101","Nivea Silver Protect (50mL)","50","2023-08-31","45.00");

    ptr = head;
    while (ptr != NULL)
    {
        printf("%d,%s,%s,%s,%s,%s\n",ptr->data,ptr->Id,ptr->Desc,ptr->Quantity,ptr->DateExp,ptr->Price);
        ptr = ptr->next;
    }

    fclose(fpointer);
    //End of FileAccess
    
    return 0;

}*/