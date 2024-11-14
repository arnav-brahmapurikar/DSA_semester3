#include<stdio.h>
struct node{
    float coeff;
    int expo;
    struct node* next;
};
void print(struct node* head){
    struct node* temp=head;
    while(temp!=NULL){
        printf("%fx^%d",head->coeff,head->expo);
        temp=temp->next;
        if(temp!=NULL){
            printf("+");
        }
        else{
            printf("\n");
        }
    }
}

struct node* insert(struct node*head,float coeff,int exp){
    struct node* new=malloc(sizeof(struct node));
    struct node* temp=head;
    new->coeff=coeff;
    new->expo=exp;
    new->next=NULL;
    if(head==NULL || exp>head->expo){
        new->next=head;
        head=new;
        return head;
    }
    else{
        while(temp->next!=NULL && temp->next->expo>=exp){
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
struct node* polyMultiplication(struct node*head1,struct node*head2){
    struct node*ptr1=head1;
    struct node*ptr2=head2;
    struct node*head3=NULL;
    while(ptr1!=NULL){
        while(ptr2!=NULL){
            head3=insert(head3,ptr1->coeff*ptr2->coeff,ptr1->expo+ptr2->expo);
            ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
        ptr2=head2;
    }
    print(head3);
}
