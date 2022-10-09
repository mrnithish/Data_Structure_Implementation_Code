#include<stdio.h>
int queue[100],option,front,rear,x,i,n;
int main()
{
    rear=-1;
    front=0;
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
    if(rear>=n-1)
    {
        printf("\nOverflow");
        
    }
    else
    {
        printf(" Enter the element:");
        scanf("%d",&x);
        rear++;
        queue[rear]=x;
        printf(" %d  Successfully enqueued.. ",x);
    }
}
void dequeue()
{
    if(front==-1 || front>rear)
    {
        printf("\nUnderflow");
    }
    else
    {
        printf("\n %d is dequeued ",queue[front]);
        front++;
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
    }
   
}
