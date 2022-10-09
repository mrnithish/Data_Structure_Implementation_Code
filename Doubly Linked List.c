#include<stdio.h>
#include<stdlib.h>
typedef struct node* nn;
struct node {
    int data;
    nn next;
    nn prev;
};
nn Head=NULL;
int option,x;
void mainMenu(){
    printf("\nDoubly Linked List\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter the option:");
    scanf("%d",&option);
}
void insert(){
    if(Head==NULL){
        insertBegin();
    }
    else{
    subMenu:
    printf("\n1.Insert Begin\n2.Insert End\nEnter the choice:");
    scanf("%d",&option);
    switch(option){
        case 1:
        insertBegin();
        break;
        case 2:
        insertEnd();
        break;
        default:
        printf("\nInvalid.......\n");
        goto subMenu;
    }
    }
}
void insertBegin(){
    printf("Enter the element:");
    scanf("%d",&x);
    nn newnode=malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=Head;
    newnode->prev=NULL;
    if(Head!=NULL){
        Head->prev=newnode;
    }
   Head=newnode;
    printf("Element  %d is inserted.",x);
}
void insertEnd(){
    printf("Enter the element:");
    scanf("%d",&x);
    nn newnode=malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    nn temp=Head;
    if(Head==NULL){
        newnode->prev=NULL;
        Head=newnode;
    }
    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
    }
    printf("Element  %d is inserted.",x);
    
}

void delete(){
    if(Head==NULL){
    printf("Empty List");
    }
    else{
    subMenu:
    printf("\n1.Delete Begin\n2.Delete End\nEnter the choice:");
    scanf("%d",&option);
    switch(option){
        case 1:
        deleteBegin();
        break;
        case 2:
        deleteEnd();
        break;
        default:
        printf("\nInvalid.......\n");
        goto subMenu;
    }
    }
}
void deleteBegin(){
    nn temp=Head;
    if(Head==NULL){
    printf("Empty List");
    }
    else if(Head->next==NULL){
        printf("%d is deleted ",Head->data);
        Head=NULL;
        free(Head);
    }
    else{
        printf("%d is deleted ",Head->data);
        Head=Head->next;
        Head->prev=NULL;
        free(temp);
    }
    
}
void deleteEnd(){
  nn temp=Head;
    if(Head==NULL){
    printf("Empty List");
    }
    else if(Head->next==NULL){
        Head=NULL;
        free(Head);
    }
    else{
        temp=Head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        printf("%d is deleted ",temp->data);
        temp->prev->next=NULL;
        free(temp);
    }
}
void display(){
    nn temp=Head;
    if(temp==NULL){
        printf("List is empty");
    }
    else
    {   printf("List\n");
        while(temp!=NULL){
            printf("%d\t",temp->data);
            temp=temp->next;
        }
    }
}
void main(){
    do
    {
        mainMenu();
        switch(option)
        {
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
            printf("Exited.................");
            exit(0);
            break;
            default:
            mainMenu();
            break;
        }
    }while(1);
}