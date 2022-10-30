**********************************************Garbage Value retained need to find it**********************************************************************

#include<stdio.h>
#include<stdlib.h>
typedef struct tnode* nn;
int opt,x;
nn T=NULL;
struct tnode{
    nn left;
    int data;
    nn right;
};
nn insert(nn T,int x){
    if(T==NULL)
    {
        nn T =malloc(sizeof(struct tnode));
        if(T!=NULL)
        {
        T->data=x;
        T->left=NULL;
        T->right=NULL; 
       // printf("%d is inserted",x);
            return T;
        }
    }
    else
    {
        if(x<T->data)
        {
            T->left=insert(T->left,x);
          //  printf("%d is inserted in left",x);
                return T;
        }
        if(x>T->data)
        {
           T->right=insert(T->right,x);
       // printf("%d is inserted in right",x);
            return T;
        }
      
    }

    return T;
}
nn makeEmpty(nn T){
    if(T!=NULL)
    {
    makeEmpty(T->left);
    makeEmpty(T->right);
    free(T);
    }
     printf("Tree is empty");
    return NULL;
}
void inorder(nn T){
    if(T!=NULL)
    {
    inorder(T->left);
    printf("%d\t",T->data);
    inorder(T->right);
    }
}
void main(){
    while(1)
    {
    mainMenu:
    printf("\nBinary Search Tree\n1.Insert\n2.Inorder\n3.MakeEmpty\n4.Exit\nEnter the option:");
    scanf("%d",&opt);
    switch(opt){
    case 1:
    printf("\nEnter the element:");
    scanf("%d",&x);
    T=insert(T,x);
    break;
    case 2:
    inorder(T);
    break;
    case 3:
    makeEmpty(T);
    break;
    case 4:
    exit(0);
    break;
    default:
    printf("Invalid");
    }
    }
}
