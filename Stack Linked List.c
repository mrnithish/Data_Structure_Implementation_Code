#include <stdio.h>  
#include <stdlib.h>  
typedef struct node* nn;
struct node   
{  
int data;  
nn next;  
};  
nn head;  
 int option;
void main ()  
{  

    do
    {  
        printf("Stack Operations Linked list");  
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit");  
        printf("\n Enter the option:");        
        scanf("%d",&option);  
        switch(option)  
        {  
            case 1:  
            {   
                push();  
                break;  
            }  
            case 2:  
            {  
                pop();  
                break;  
            }  
            case 3:  
            {  
                display();  
                break;  
            }  
            case 4:   
            {  
                exit(0);
                prinf("Exitted................");
                break;   
            }  
            default:  
            {  
                printf("Invalid Choice \n");  
            }   
    }
}while(1); 
}  
void push ()  
{  
    int x;  
    nn newnode = (nn)malloc(sizeof(struct node));   
    if(newnode == NULL)  
    {  
        printf("No element is inserted...\n");   
    }  
    else   
    {  
        printf("Enter the element:");  
        scanf("%d",&x);  
        if(head==NULL)  
        {         
            newnode->data = x;  
            newnode -> next = NULL;  
            head=newnode;  
        }   
        else   
        {  
            newnode->data = x;  
            newnode->next = head;  
            head=newnode;  
               
        }  
        printf("%d is pushed \n",x);  
          
    }  
}  
  
void pop()  
{  
    int x;  
    nn newnode;  
    if (head == NULL)  
    {  
        printf("Underflow\n");  
    }  
    else  
    {  
        x = head->data;  
        printf("%d is popped\n",x);  
        newnode = head;  
        head = head->next;  
        free(newnode);  
          
    }  
}  
void display()  
{  
    int i;  
    nn newnode;  
    newnode=head;  
    if(newnode == NULL)  
    {  
        printf("Stack is empty\n");  
    }  
    else  
    {  
        printf("The elements in the stack are ");  
        while(newnode!=NULL)  
        {  
            printf("%d\t",newnode->data);  
            newnode = newnode->next;  
        } 
        printf("\n");
    }  
}  