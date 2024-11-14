#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct node{
    int data;
    int priority;
    struct node* next;

};

void info(){
    time_t t;
    time(&t);
    printf("Shresth Singh Chandel\nBT23CSH024\n\n%s\n", ctime(&t));
    return;
}

void display(struct node* head){
    while(head!=NULL){
        printf("Data: %d it's priority: %d \n",head->data,head->priority);
        head=head->next;
    }
}
struct node* create(struct node* head,int p,int d){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    struct node* temp=head;
    ptr->data=d;
    ptr->priority=p;
    ptr->next=NULL;
    if(head==NULL){
        head=ptr;
    }
    else if(head->priority<p){
        ptr->next=head;
        head=ptr;
    }
    else{
        while (temp->next!=NULL && temp->next->priority >= p){
            temp=temp->next;
        }
        ptr->next=temp->next;
        temp->next=ptr;
        
    }
    return head;
    
}

int pop(struct node** head){
    if(*head==NULL){
        printf("Queue is Empty");
        return -1;
    }
    else{
        struct node* temp=*head;
        int poop=temp->data;
        *head=(*head)->next;
        free(temp);
        return poop;
    }
    
}
int main(){
    info();
    struct node*head=NULL;
    head=create(head,1,12);
    head=create(head,5,52);
    head=create(head,3,11);
    head=create(head,4,22);
    head=create(head,2,23);
    display(head);
    printf("\n");

    
    pop(&head);
    display(head);
    printf("\n");
    pop(&head);
    display(head);

}