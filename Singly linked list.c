#include<stdio.h>
#include<stdlib.h>
#include<math.h>


typedef struct node* nn;
nn head = NULL;

struct node{
    int data;
    nn next;
};
int option,x,position;
void mainMenu(){
    printf("\nSingly Linked List\n1.Insert\n2.Delete\n3.Display\n4.Delete List\n5.Exit\nEnter the option:");
    scanf("%d",&option);
}
void main()
{
   
    do{
        mainMenu();
        switch(option){
        case 1: 
                insert();
                break;
        case 2: 
                delete();
                break;
               
        case 3: 
                display();
                break;
        case 4: 
                if(head==NULL){
                printf("List is not created");
                }
                else{
                deleteList();
                }
                break;
        case 5:
                printf("Exited.................");
                exit(0);
                break;
        default: 
                printf("Invalid option that your picked \nPlease Enter the correct option..");
        }
    }while(1);
}
void insert(){
    if(head==NULL){
        insertBegin();
    }
    else{
    subMenu:
    printf("\n1.Insert Begin\n2.Insert End\n3.Insert Position\nEnter the choice:");
    scanf("%d",&option);
    switch(option){
        case 1:
        insertBegin();
        break;
        case 2:
        insertEnd();
        break;
        case 3:
        if(head==NULL)
        {
        printf("No element is inserted\n");
        }
        else
        {
        printf("Enter the Position: ");
        scanf("%d", &position);
        printf("Enter the data: ");
        scanf("%d", &x);
        if(position==0){
            insertBegin();
           }
        else{
            insertPosition(position,x);
            }
        }
        break;
        default:
        printf("\nInvalid.......\n");
        goto subMenu;
    }
    }
}
void delete(){
    if(head==NULL){
        printf("\nList is empty..");
    }
    else{
     subMenu:
    printf("\n1.Delete Begin\n2.Delete End\n3.Delete Position\nEnter the choice:");
    scanf("%d",&option);
    switch(option){
        case 1:
        deleteBegin();
        break;
        case 2:
        deleteEnd();
        break;
        case 3:
         if(head==NULL)
                 {
                 printf("No element is inserted\n");
                 }
                else
                {
                printf("Enter the Position: ");
                scanf("%d", &position);
                if(position<0){
                    printf("Invalid position");
                    break;
                }
                  deleteposition(position);
                }
                break;
        break;
        default:
        printf("\nInvalid.......\n");
        goto subMenu;
    }
    }
}
void deleteBegin(){
    if(head==NULL){
        printf("List is empty");
    }
    else{
        nn temp=head;
        printf("%d is deleted ",head->data);
        head=head->next;
        free(temp);
    }
}
void deleteEnd(){
    if(head==NULL){
        printf("List is empty");
    }
    else{
        nn three;
        nn temp=head;
        while(temp->next!=NULL){
            three=temp;
            temp=temp->next;
        }
        printf("%d is deleted ",temp->data);
        three->next=NULL;
        free(temp);
    }
}
void deleteposition(int position){
    int i;
    nn temp = head;
    nn prev;
    if(head==NULL){
        printf("No element is insserted");
        return;
    }
    if(position==0){
        head = head->next;
        printf("Deleted %d",temp->data);
        free(temp);
        return;
    }
    for(i=1;i<=position;i++){
        prev = temp;
        temp = temp->next;
        if(temp==NULL){
            printf("Invalid position\n");
            return;
        }
    }
    prev->next = temp->next;
    printf("Deleted %d",temp->data);
    free(temp);
}

void insertBegin(){
    printf("Enter the data: ");
    scanf("%d", &x);
    nn newNode=(nn)malloc(sizeof(struct node));
    newNode->data = x;
    
    if(head == NULL){
        newNode->next = NULL;
        head = newNode;
    }
    else{
        newNode->next = head;
        head = newNode;
    }
    printf("Element  %d is inserted.",x);
}
void insertEnd(){
     printf("Enter the data: ");
    scanf("%d", &x);
    nn newNode=(nn)malloc(sizeof(struct node));
    newNode->data = x;
    if(head == NULL){
        newNode->next = NULL;
        head = newNode;
    }
    else{
        nn temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
}
void insertPosition(int position, int x){
    int i;
    nn newNode=(nn)malloc(sizeof(struct node));
    if(newNode!=NULL){
    newNode->data = x;
    nn temp = head;
    for(i=1;i<=position-1;i++)
    {
        temp = temp->next;
        if(temp==NULL)
        {
            printf("Invalid position\n");
            return;
        }
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Element %d is inserted in position %d", x,position);
}
}
void display(){
    if(head==NULL){
        printf("No element is inserted");
    }
    else
    {
    nn temp = head;
    printf("Elements in the list are:   ");
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp = temp->next;
    }
    }
}
void deleteList()
{
    printf("List is deleted....");
    head=NULL;
    
}
