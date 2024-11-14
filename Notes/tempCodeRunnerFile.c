#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node* left;
    struct node*right;
    int data;
    int height;

};
void PreOrder(struct node* N){
    if(N!=NULL){
    printf("%d ",N->data);
    PreOrder(N->left);
    PreOrder(N->right);
    printf("\n");
    }
}
int max(int a,int b){
    if(a>=b){
        return a;
    }
    else{
        return b;
    }
}
int getHeight(struct node* N){
    if(N==NULL){
        return 0;
    }
    return N->height;
}
struct node* Create(int data){
    struct node* new=(struct node*)malloc(sizeof(struct node));
    new->data=data;
    new->left=NULL;
    new->right=NULL;
    new->height=1;
    return new;
}
struct node* RightRotate(struct node* y){
    struct node*x=y->left;
    struct node*T2=x->right;
    x->right=y;
    y->left=T2;
    x->height=max(getHeight(x->left),getHeight(x->right))+1;
    y->height=max(getHeight(y->left),getHeight(y->right))+1;
    return x;
}
struct node* LeftRotate(struct node* y){
    struct node*x=y->right;
    struct node*T2=x->left;
    x->left=y;
    y->right=T2;
    x->height=max(getHeight(x->left),getHeight(x->right))+1;
    y->height=max(getHeight(y->left),getHeight(y->right))+1;
    return x;
}
int BalanceFactor(struct node*N){
    if(N==NULL){
        return 0;
    }
    else{
        return getHeight(N->left)-getHeight(N->right);
    }
}
struct node*Insert(struct node*N,int data){
    int balanceFactor;
    if(N==NULL){
        return Create(data);
    }
    if(data<N->data){
        N->left=Insert(N->left,data);
    }
    else if(data>N->data){
        N->right=Insert(N->right,data);
    }
    else{
        return N;
    }
    N->height=max(getHeight(N->left),getHeight(N->right))+1;
    balanceFactor=BalanceFactor(N);
    if(balanceFactor>1 && data<N->left->data){
        return RightRotate(N);
    }
    if(balanceFactor<-1 && data>N->right->data){
        return LeftRotate(N);
    }
    if(balanceFactor>1 && data>N->left->data){
        N->left=LeftRotate(N->left);
        return RightRotate(N);
    }
    if(balanceFactor<-1 && data<N->right->data){
        N->right=RightRotate(N->right);
        return LeftRotate(N);
    }
    return N;
}
int main (){
    struct node* root=NULL;

    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 30);
    root = Insert(root, 40);
    root = Insert(root, 50);
    root = Insert(root, 25); 
    printf("\n");
    printf("Traversal:");
    printf("\n");
    PreOrder(root);
    root = Insert(root, 23); 
    printf("\n");
    printf("Traversal:");
    printf("\n");
    PreOrder(root);



}