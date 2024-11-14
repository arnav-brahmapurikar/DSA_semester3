#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct bucket{
    int index;
    struct node* value;
    struct bucket* next;
};

int GetMax(int A[],int n){
    int lar=A[0];
    for(int i=0;i<n;i++){
        if(A[i]>lar){
            lar=A[i];
        }
    }
    return lar;
}

int count(int n){
    int count=0;
    while(n){
        count++;
        n=n/10;
    }
    return count;
}
struct bucket *createBucket(struct node* head,int index,int A){
struct bucket* bucket=

}
 void radixSort(int A[],int n){
    int L=GetMax(A,n);
    int f=count(L);
    struct bucket* bucket=NULL;
    int place=1;
    while(f--){
        for(int i=0;i<n;i++){
            int index=(A[i]/place)%10;
            struct node* temp= (struct node *)malloc(sizeof(struct node));
            temp->data=A[i];
            temp->next=NULL;
            if(bucket[index]==NULL){
                bucket[index]=temp;
                leftLL=temp;
            }
            else{

            }
            
        }
    }
 }
int main(){

}