#include <stdio.h>
#include<stdlib.h>
struct node
{
    int expo;
    int coeff;
    struct node *next;
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
    struct node* temp;
    struct node* newp =(struct node*)malloc(sizeof(struct node));
    newp->coeff=coeff;
    newp->expo=expo;
    newp->next=NULL;
    if(head==NULL|| expo>head->expo){
        newp->next=head;
        head=newp;
        
    }
    else{
        temp=head;
        while(temp->next!=NULL && temp->next->expo>expo){
            temp=temp->next;
        }
        newp->next=temp->next;
        temp->next=newp;
        
    }
return head;
}
struct node* merge(struct node* head){
    struct node* temp=head;
    while(temp!=NULL){
        struct node* ptr=temp;
        while(ptr->next!=NULL){
            if(ptr->next->expo==temp->expo){
                temp->coeff=ptr->coeff+temp->coeff;
                struct node* del=ptr->next;
                ptr->next=ptr->next->next;
                free(del);

            }
            else{
                ptr=ptr->next;
            }
        }
        temp=temp->next;
    }
    return head;
}
struct node *create(struct node *head)
{
    int n;
    int coeff,expo;
    printf("Enter the number of terms of Polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the coefficient: ");
        scanf("%d",&coeff);
        printf("Enter the exponent: ");
        scanf("%d",&expo);
        head=insert(head,coeff,expo);
    }
    head=merge(head);
    return head;
}

void polyAdd(struct node*head1,struct node*head2){
    struct node* ptr1=head1;
    struct node* ptr2=head2;
    struct node*head3=NULL;
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
head3=merge(head3);    
printf("The Polynomial is:");
print(head3); 
}
int main(){
    struct node*head1=NULL;
    struct node*head2=NULL;
    printf("Enter the 1st Polynomial: ");
    printf("\n");
    head1=create(head1);
    print(head1);
    printf("Enter the 2nd Polynomial: ");
    printf("\n");
    head2=create(head2);
    print(head2);
    printf("\n");
    printf("Sum Of Both:");
    polyAdd(head1,head2);

return 0;
}



