#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
int LargestNum(int A[],int n){
    int lar=A[0];
    for(int i=0;i<n;i++){
        if(A[i]>lar){
            lar=A[i];
        }
    }
    int count=0;
    for(int i=0;i<n;i++){
        count++;
        lar=lar/10;
    }
    return count;
}
void radixSort(int A[],int n){
    struct node *bean[10];
    struct node* left[10];
    int f=1;
    int digit=LargestNum(A,n);
    while(digit--){
        for( int i=0;i<n;i++){
            bean[i]=NULL;
            left[i]=NULL;
        }
        for(int i=0;i<n;i++){
            int index=(A[i]/f)%10;
            struct node* temp=(struct node*)malloc(sizeof(struct node));
            temp->data=A[i];
            temp->next=NULL;

            if(bean[index]==NULL){
                bean[index]=temp;
                left[index]=A[i];
            }
            else{
                left[index]->next=temp;
                left[index]=temp;
            }
        }
        int j=0;
        for(int i=0;i<10;i++){
            struct node*temp=bean[i];
            
        }
    }
}

