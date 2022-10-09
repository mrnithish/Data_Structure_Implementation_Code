#include<stdio.h>
#include<stdlib.h>

typedef struct node* nn;
struct node {
    int data;
    nn next;
};
nn front=NULL,rear=NULL;
int option,x;
void mainMenu(){
    printf("\nQueue Linked List\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter the option:");
    scanf("%d",&option);
}
void enqueue(){
    printf("Enter the element:");
    scanf("%d",&x);
    nn newnode=malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    if(rear==NULL){
        rear=newnode;
        front=newnode;
    }
    else
    {
     rear->next=newnode;
     rear=newnode;
     } 
     printf("%d is enqueued...",x);
     
    
}
void dequeue(){
    if(front==NULL){
        printf("Underflow..");
    }
    else{
        nn temp=front;
        int y=front->data;
        front=front->next;
        free(temp);
        printf("%d is dequeued...",y);
    }
}
void display(){
    nn temp=front;
    if(temp==NULL){
        printf("Queue is empty");
    }
    else
    {   printf("Queue\n");
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
            enqueue();
            break;
            case 2:
            dequeue();
            break;
            case 3:
            display();
            break;
            case 4:
            printf("Exited.....");
            exit(0);
            break;
            default:
            printf("Invalid Selection");
        }
    }while(1);
}