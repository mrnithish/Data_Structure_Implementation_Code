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
void minimum(nn T){
    if(T!=NULL)
    {
    while(T->left!=NULL){
        T=T->left;
    } 
    printf("\nMinimum:%d",T->data);
    }
}
void maximum(nn T){
    if(T!=NULL)
    {
    while(T->right!=NULL){
        T=T->right;
    } 
    printf("\nMaximum:%d",T->data);
    }
}
void inorder(nn T){
    if(T!=NULL)
    {
    inorder(T->left);
    printf("%d\t",T->data);
    inorder(T->right);
    }
}
void preorder(nn T){
    if(T!=NULL){
        printf("%d\t",T->data);
        preorder(T->left);
        preorder(T->right);
    }
}
void postorder(nn T){
    if(T!=NULL){
    postorder(T->left);
    postorder(T->right);
    printf("%d\t",T->data);
    }
}
int option;
void main(){
  do{
        printf("\nBinary Search Tree\n1.Insert\n2.Inorder\n3.preorder\n4.Postorder\n5.Minimum\n6.Maximum\n7.Exit\nEnter the choice:");
    scanf("%d",&option);
    switch(option)
    {
        case 1:
        printf("\nEnter the data:");
        scanf("%d",&x);
        T=insert(T,x);
        break;
        case 2:
        printf("Inorder:");
        inorder(T);
        break;
        case 3:
        printf("Preorder:");
        preorder(T);
        break;
        case 4:
        printf("Postorder:");
        postorder(T);
        break;
        case 5:
        minimum(T);
        break;
        case 6:
        maximum(T);
        break;
        case 7:
        exit(0);
        break;
    }
    }while(2);
}

