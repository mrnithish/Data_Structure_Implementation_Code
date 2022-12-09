#include<stdio.h>
#include<stdlib.h>
typedef struct tnode* nn;
int option,x;
nn root=NULL;
struct tnode{
    nn left;
    int data;
    nn right;
    int ht;
};
int height(nn T)
{
    int lh,rh;
    if(T==NULL)
        return(0);
    if(T->left==NULL)
        lh=0;
    else
        lh=1+T->left->ht;
    if(T->right==NULL)
        rh=0;
    else
        rh=1+T->right->ht;
    if(lh>rh)
        return(lh);
    return(rh);
}
int balanceFactor(nn T)
{
    int lh,rh;
    if(T==NULL)
        return(0);
    if(T->left==NULL)
        lh=0;
    else
        lh=1+T->left->ht;
    if(T->right==NULL)
        rh=0;
    else
        rh=1+T->right->ht;
    return(lh-rh);
}
nn  rotateright(nn x)
{
    nn y;
    y=x->left;
    x->left=y->right;
    y->right=x;
    x->ht=height(x);
    y->ht=height(y);
    return(y);
}
nn  rotateleft(nn x)
{
    nn y;
    y=x->right;
    x->right=y->left;
    y->left=x;
    x->ht=height(x);
    y->ht=height(y);
    return(y);
}
nn  RR(nn T)
{
    T=rotateleft(T);
    return(T);
}
nn  LL(nn T)
{
    T=rotateright(T);
    return(T);
}
nn  LR(nn T)
{
    T->left=rotateleft(T->left);
    T=rotateright(T);
    return(T);
}
nn  RL(nn T)
{
    T->right=rotateright(T->right);
    T=rotateleft(T);
    return(T);
}
nn insert(nn T,int x)
{
    if(T==NULL)
    {
        T=(nn)malloc(sizeof(struct tnode));
        T->data=x;
        T->left=NULL;
        T->right=NULL;
    }
    else
        if(x > T->data)        
        {
            T->right=insert(T->right,x);
            if(balanceFactor(T)==-2)
                if(x>T->right->data)
                    T=RR(T);
                else
                    T=RL(T);
        }
        else
            if(x<T->data)
            {
                T->left=insert(T->left,x);
                if(balanceFactor(T)==2)
                    if(x < T->left->data)
                        T=LL(T);
                    else
                        T=LR(T);
            }
        T->ht=height(T);
        return(T);
}
void inorder(nn root){
    if(root!=NULL)
    {
    inorder(root->left);
    printf("\n%d  Balance Factor:%d\n ",root->data,balanceFactor(root));
    inorder(root->right);
    }
}
void preorder(nn root){
    if(root!=NULL){
        printf("\n%d  Balance Factor:%d\n ",root->data,balanceFactor(root));
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(nn root){
    if(root!=NULL){
    postorder(root->left);
    postorder(root->right);
    printf("\n%d  Balance Factor:%d\n ",root->data,balanceFactor(root));
    }
}
void main(){
  do{
        printf("\nAVL Tree\n1.Insert\n2.Inorder\n3.preorder\n4.Postorder\n5.Exit\nEnter the choice:");
    scanf("%d",&option);
    switch(option)
    {
        case 1:
        printf("\nEnter the data:");
        scanf("%d",&x);
        root=insert(root,x);
        break;
        case 2:
        if(root!=NULL)
        {
        printf("Inorder:");
        inorder(root);
        }
        else{
            printf("Tree is empty");
        }
        
        break;
        case 3:
        if(root!=NULL)
        {
        printf("Preorder:");
        preorder(root);
        }
        else
        {
        printf("Tree is empty");
        }
        break;
        case 4:
        if(root!=NULL)
        {
        printf("Postorder:");
        postorder(root);
        }
        else
        {
        printf("Tree is empty");
        }
        break;
        case 5:
        exit(0);
        break;
        default:
        printf("Invalid..");
    }
  }while(23);
  
}
