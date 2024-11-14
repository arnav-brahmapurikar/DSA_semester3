#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
int MaxCount(int A[],int n){
    int lar=A[0]; 
    for(int i=0;i<n;i++){
        if(A[i]>lar){
            lar=A[i];
        }
    }
    int count=0;
    while(lar>0){
        count++;
        lar=lar/10;
    }
    return count;
}
void RadixSort(int n,int A[]){
    int L=MaxCount(A,n);
    struct node* bucket[10];
    struct node* side[10];
    int f=1;
    while(L--){
        for(int i=0;i<10;i++){
            bucket[i]=NULL;
        }
        for(int i=0;i<n;i++){
            int index=(A[i]/f)%10;
            struct node*temp=(struct node *)malloc(sizeof(struct node));
            temp->data=A[i];
            temp->next=NULL;

            if(bucket[index]==NULL){
                bucket[index]=temp;
                side[index]=temp;
            }
            else{
                side[index]->next=temp;
                side[index]=temp;
            }
        }
        int j=0;
        for(int i=0;i<10;i++){
           struct node* temp= bucket[i];
           while(temp!=NULL){
            A[j++]=temp->data;
            struct node *ptr=temp;
            temp=temp->next;
            free(ptr);

           }
        }
        f*=10;
    }
    return;
}
int main(){
    int n;
    
    printf("Enter number of elements of array: ");
    scanf("%d", &n);
    int A[n];
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);  
    }
    printf("\n");
    int p=MaxCount(A,n);
    printf("%d",p);
    printf("\n");
    RadixSort(n,A);
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);  
    }
    return 0;
}