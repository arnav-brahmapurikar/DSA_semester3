#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* next;
};

struct node* create(struct node* head,int data){
    if(data==0){
    
    struct node* new=(struct node*)malloc(sizeof(struct node));
    new->data=data;
    new->next=head;
    head=new;
    return head;
    }
    while (data>0){
        struct node* new=(struct node*)malloc(sizeof(struct node));
        new->data=data%10;
        new->next=head;
        head=new;
        data=data/10;
    }
    return head;
}
struct node* reverse(struct node* head){
    struct node* current=head,*next=NULL,*prev=NULL;
  
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
        return prev;

}
struct node* addition(struct node* head1,struct node* head2){

    struct node* ptr1=reverse(head1);
    struct node* ptr2=reverse(head2);
    struct node* head3=NULL;
    int sum;
    int carry=0;

    while ((ptr1!=NULL || ptr2!=NULL ||carry))
    {
        sum=carry;
        if(ptr1!=NULL){
            sum+=ptr1->data;
            ptr1=ptr1->next;
        }
        if(ptr2!=NULL){
            sum+=ptr2->data;
            ptr2=ptr2->next;
        }
        carry=sum/10;
        sum=sum%10;
        struct node* temp=(struct node*)malloc(sizeof(struct node));
        temp->data=sum;
        temp->next=head3;
        head3=temp;
        

        
    }
    return head3;
}

struct node* Multiplication(struct node*head1,struct node* head2){
    head1=reverse(head1);
    head2=reverse(head2);

    struct node* temp1=head1;
    int multiplier=0;
    struct node* result=NULL;
    
    while(temp1!=NULL){
        struct node* temp2=head2;
        int carry =0;
        struct node* partialResult=NULL;
        while(multiplier--){
            struct node*lastNode=(struct node*)malloc(sizeof(struct node));
            lastNode->data=0;
            lastNode->next=partialResult;
            partialResult=lastNode;
        }
        while(temp2!=NULL || carry!=0){
            // int mul=temp2->data*temp1->data+carry;
            int mul = (temp1->data) * (temp2 ? temp2->data : 0) + carry;
            carry=mul/10;
            mul=mul%10;
            struct node*new=(struct node*)malloc(sizeof(struct node));
            new->data=mul;
            new->next=partialResult;
            partialResult=new;
            if(temp2!=NULL){
                temp2=temp2->next;
            }
          
        }
          result=addition(result,partialResult);
          multiplier++;
          temp1=temp1->next;
    }
    return result;
}
void display(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void freeList(struct node *head) {
    struct node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
int main(){
    struct node *head1 = NULL, *head2 = NULL;
    int n1, n2;
    
    printf("Enter number 1: ");
    scanf("%d", &n1);
    head1 = create(head1, n1);

    printf("Enter number 2: ");
    scanf("%d", &n2);
    head2 = create(head2, n2);

    struct node *result = addition(head1, head2);
    struct node *multiplication = Multiplication(head1,head2);
    printf("The sum is: ");
    display(result);

    printf("\n");

    printf("The Multiplication is: ");
    display(multiplication);
    
    freeList(head1);
    freeList(head2);
    freeList(result);

    return 0;
}