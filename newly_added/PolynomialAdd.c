#include<stdio.h>
#include<stdlib.h>
struct node{
    int coeff;
    int expo;
    struct node* next;
};
void print(struct node* head){
    if(head==NULL){
        printf("No Polynomial");
    }
    else{
        struct node* temp=head;
        while(temp!=NULL){
            printf("%d^%d",temp->coeff,temp->expo);
            temp=temp->next;
            if(temp!=NULL){
                printf("+");
            }
            else{
                printf("\n");
            }
        }
    }
}
struct node* insert(struct node* head,int coeff,int expo){
    struct node* new=malloc(sizeof(struct node));
    new->coeff=coeff;
    new->expo=expo;
    new->next=NULL;
    struct node* temp=head;
    if(head==NULL || expo>head->expo){
        new->next=head;
        head=new;
        return head;
    }
    else{
        while(temp->next!=NULL && temp->next->expo>expo){
            temp=temp->next;
        }
        new->next=temp->next;
        temp->next=new;
    }
    return head;
}
struct node* create(struct node* head){
    int i,n,expo;
    float coeff;
    printf("Enter Number of terms");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter the Coeff");
        scanf("%f",&coeff);
        printf("Enter the Power");
        scanf("%d",&expo);
        head=insert(head,coeff,expo);
    }
    return head;
}
void polyAdd(struct node* head1,struct node* head2){
    struct node* ptr1=head1;
    struct node* ptr2=head2;
    struct node* head3=NULL;
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->expo==ptr2->expo){
            head3=insert(head3,ptr1->coeff+ptr2->coeff,ptr1->expo);
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
         else if(ptr1->expo>ptr2->expo){
            head3=insert(head3,ptr1->coeff,ptr1->expo);
            ptr1=ptr1->next;
            }
        
        else if(ptr2->expo>ptr1->expo){
            head3=insert(head3,ptr2->coeff,ptr2->expo);
            ptr2=ptr2->next;
            }
}
while(ptr1!=NULL){
    head3=insert(head3,ptr1->coeff,ptr1->expo);
    ptr1=ptr1->next;
}
while(ptr2!=NULL){
    head3=insert(head3,ptr2->coeff,ptr2->expo);
    ptr2=ptr2->next;
}
    
printf("The Polynomial is:");
print(head3);
}

int main(){
    struct node* head1=NULL;
    struct node* head2=NULL;
    head1=create(head1);
    print(head1);
    head2=create(head2);
    print(head2);
    polyAdd(head1,head2);
    
}