#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};

struct node* Insert(struct node* head,int data){
	struct node*ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=data;
	ptr->next=NULL;
	if(head==NULL){
		head=ptr;
	}
	else{
		struct node* p=head;
		while(p->next!=NULL){
			p=p->next;
		}
		p->next=ptr;
	}
	return head;
}
int getMax(int A[],int n)
{
    int maxVal=A[0];
    for (int i=1;i<n;i++)
    {
        if (A[i]>maxVal)
        {
            maxVal=A[i];
        }
    }
    return maxVal;
}
int RadixLL(int A[],int n,int pos){
    // int count[10]={0};
    struct node* bucket=(struct node*)malloc(sizeof(struct node));
    struct node* head=(struct node*)malloc(sizeof(struct node));
    bucket[10];
    for(int i=0;i<10;i++){
        bucket[i]=NULL;
    }
    for(int i=0;i<n;i++){
      bucket[(A[i]/pos)%10]=Insert(head,A[i]);  
    }

}


int main(){

}