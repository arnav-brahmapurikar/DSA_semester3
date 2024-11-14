#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
    int height;
};
int getHeight(struct node* N){
    if (N==NULL)
    {
        return 0;
    }
    return N->height;
    
}
void PreOrder(struct node* N){
    if(N!=NULL){
    printf("%d ",N->data);
    PreOrder(N->left);
    PreOrder(N->right);
    // printf("\n");
    }
}
struct node* create(int data){
    struct node* N=(struct node*)malloc(sizeof(struct node));
    N->data=data;
    N->left=NULL;
    N->right=NULL;
    N->height=1;
    return N;

}
int GetMax(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
struct node* RightRotate(struct node* y){
    struct node* x=y->left;
    struct node* T2=x->right;
    x->right=y;
    y->left=T2;
    x->height=1+GetMax(getHeight(x->left),getHeight(x->right));
    y->height=1+GetMax(getHeight(y->left),getHeight(y->right));
}
struct node* LeftRotate(struct node* y){
    struct node* x=y->right;
    struct node* T2=x->left;
    x->left=y;
    y->right=T2;
    x->height=1+GetMax(getHeight(x->left),getHeight(x->right));
    y->height=1+GetMax(getHeight(y->left),getHeight(y->right));
}
int BalanceFactor(struct node* N){
    if (N==NULL)
    {
        return 0;
    }
    else
    {
        return getHeight(N->left)-getHeight(N->right);
    }
}
struct node* insert(struct node* N,int key){
    if (N==NULL)
    {
        return create(key);
    }
    if (key<N->data)    
    {
        N->left=insert(N->left,key);
    }
    else if(key>N->data){
        N->right=insert(N->right,key);
    }
    else{
        return N;
    }
    N->height=GetMax(getHeight(N->left),getHeight(N->right));
    int BalanceF=BalanceFactor(N);
    if(BalanceF>1 && key<N->left->data){
        return RightRotate(N);
    }
    if(BalanceF<-1 && key>N->right->data){
        return LeftRotate(N);
    }
    if(BalanceF>1 && key>N->left->data){
        N->left=LeftRotate(N->left);
        return RightRotate(N);
    }
    if(BalanceF>1 && key<N->left->data){
        N->right=RightRotate(N->right);
        return LeftRotate(N);
    }
    return N;
}

struct node* InOrderSuccessor(struct node*N){
    struct node*temp=N;
    while(temp!=NULL){
        temp=temp->left;
    }
    return temp;
}
struct node* Deletion(struct node* N,int key){
    if(N==NULL){
        return N;
    }
    if(key<N->data){
        N->left=Deletion(N->left,key);
    }
    else if(key>N->data){
        N->right=Deletion(N->right,key);
    }
    else{
        if(N->left==NULL||N->right==NULL){
            struct node*temp=NULL;
            if(N->left!=NULL){
                temp=N->left;
            }
            else {
                temp=N->right;
            }
            if(temp==NULL){
                temp=N;
                N=NULL;
            }
            else{
                N=temp;
                free(temp);
            }
        }
        else{
            struct node* temp=InOrderSuccessor(N);
            N->data=temp->data;
            N->left=Deletion(N->left,temp->data);
        }
    }
}
int main(){
    struct node* root=NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25); 
    printf("\n");
    printf("Traversal:");
    printf("\n");
    PreOrder(root);
    root = insert(root, 23); 
    printf("\n");
    printf("Traversal:");
    printf("\n");
    PreOrder(root);

}