#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    int data;
    struct node*next;
};

struct node* create(int a,struct node*head){
    struct node* new=malloc(sizeof(struct node));
    new->data=a;
    new->next=head;
    head=new;
    return head;
}
struct node* createLL(char num[]){
    struct node* head=NULL;
    for(int i=0;i<strlen(num);i++){
        head=create(num[i]-'0',head);
    }
    return head;
}
struct node* Addition(struct node*head1,struct node* head2){
    struct node* result=NULL;
    int sum=0;
    int carry=0;
    while(head1!=NULL||head2!=NULL||carry){
        sum=carry;
        if(head1!=NULL){
            sum+=head1->data;
            head1=head1->next;
        }
        if(head2!=NULL){
            sum+=head2->data;
            head2=head2->next;
        }
        carry=sum/10;
        sum=sum%10;
        struct node*temp=(struct node*)malloc(sizeof(struct node));
        temp->data=sum;
        temp->next=result;
        result=temp;
    }
    return result;
    
}
int main(){
    char num1[100];
    char num2[100];
    
    scanf("%s",num1);
    scanf("%s",num2);
    struct node* head1=createLL(num1);
    struct node* head2=createLL(num2);
    struct node*head3=Addition(head1,head2);
    while(head3!=NULL){
        printf("%d",head3->data);
        head3=head3->next;
    }
    return 0;
}