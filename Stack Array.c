#include<stdio.h>
int stack[100],option,n,top,x,i;
int main()
{
    top=-1;
    printf("\n Enter the size of STACK:");
    scanf("%d",&n);
    do
    {
    printf("\n STACK OPERATIONS");
    printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT");
        printf("\n Enter the Choice:");
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
void push()
{
    if(top>=n-1)
    {
        printf("\nOverflow");
        
    }
    else
    {
        printf(" Enter the element:");
        scanf("%d",&x);
        top++;
        stack[top]=x;
        printf(" %d  Successfully Inserted.. ",x);
    }
}
void pop()
{
    if(top<=-1)
    {
        printf("\nUnderflow");
    }
    else
    {
        printf("\n %d is popped ",stack[top]);
        top--;
    }
}
void display()
{
    if(top>=0)
    {
        printf("\n The elements in the STACK are ");
        for(i=top; i>=0; i--)
            printf("%d \t",stack[i]);
    }
    else
    {
        printf("\n The STACK is empty");
    }
   
}
