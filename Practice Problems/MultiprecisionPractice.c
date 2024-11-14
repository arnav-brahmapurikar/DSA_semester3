#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct node {
    int data;
    struct node *link;
};
struct node* create(int n,struct node* head){
    struct node* new=malloc(sizeof(struct node));
    new->data=n;
    new->link=head;
    head=new;
    return head;
}
struct node * createll(char name[]){
    struct node* head=NULL;
    for(int i=0;i<strlen(name);i++){
        head=create(name[i]-'0',head);
    }
    return head;
}
struct node *reverse(struct node *head) {
    struct node *prev = NULL, *next = NULL, *curr = head;
    while (curr != NULL) {
        next = curr->link;
        curr->link = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

struct node *add(struct node *head1, struct node *head2) {
    struct node *result = NULL;
    int sum, carry = 0;

    while (head1 != NULL || head2 != NULL || carry) {
        sum = carry;
        if (head1 != NULL) {
            sum += head1->data;
            head1 = head1->link;
        }
        if (head2 != NULL) {
            sum += head2->data;
            head2 = head2->link;
        }
        carry = sum / 10;
        sum = sum % 10;

        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data = sum;
        temp->link = result;
        result = temp;
    }

    return result;
}

void freeList(struct node *head) {
    struct node *temp;
    while (head != NULL) {
        temp = head;
        head = head->link;
        free(temp);
    }
}

int main() {
    char name1[100];
    char name2[100];

    scanf("%s",name1);
    scanf("%s",name2);

    struct node *head1=createll(name1);
    struct node *head2=createll(name2);
    struct node *res=add(head1,head2);

    while(res !=NULL)
    {
        printf("%d",res->data);
        res=res->link;
    }

    return 0;
}