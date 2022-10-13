#include<stdio.h>
int queue[100],option,front,rear,x,i,n;
int main()
{
    rear=-1;
    front=-1;
    printf("\n Enter the size of Queue:");
    scanf("%d",&n);
    do
    {
    printf("\n Queue OPERATIONS");
    printf("\n1.Enqueue\n2.Dequeue\n3.DISPLAY\n4.EXIT");
        printf("\n Enter the Choice:");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
            {
                enqueue();
                break;
            }
            case 2:
            {
                dequeue();
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
                break;
            }
            default:
            {
                printf ("INVALID OPTION");
            }
                
        }
    }
    while(1);
    return 0;
}
void enqueue()
{
    
       
        if(rear==-1 && front==-1){
        printf(" Enter the element:");
        scanf("%d",&x);
            front=0;
            rear=0;
            queue[rear]=x;
            printf(" %d  Successfully enqueued.. ",x);
            printf("\nFront=   %d",front);
            printf("\nRear=   %d",rear);
        }
        else if((rear+1)%n==front){
            printf("Overflow");
        }
        else
        {
        printf(" Enter the element:");
        scanf("%d",&x);
        rear=(rear+1)%n;
        queue[rear]=x;
        printf(" %d  Successfully enqueued.. ",x);
        printf("\nFront=  %d",front);
        printf("\nRear=   %d",rear);
        }
    
}
void dequeue()
{
    if(front==-1 || front>rear)
    {
        printf("\nUnderflow");
    }
    else if(front==rear){
        printf("\n %d is dequeued ",queue[front]);
        front=-1;
        rear=-1;
        printf("\nFront=   %d",front);
        printf("\nRear=   %d",rear);
    }
    else
    {
        printf("\n %d is dequeued ",queue[front]);
        front=(front+1)%n;
        printf("\nFront=   %d",front);
        printf("\nRear=   %d",rear);
    }
}
void display()
{
    if(front==-1 || rear==-1)
    {
    printf("\n The Queue is empty");
    }
    else
    {
        printf("\n The elements in the Queue are ");
        for(i=front; i<=rear; i++)
        printf("%d \t",queue[i]);
        printf("\nFront=   %d",front);
        printf("\nRear=   %d",rear);
    }
   
}
