#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void info(){
    time_t t;
    time(&t);
    printf("Shresth Singh Chandel\nBT23CSH024\n\n%s\n", ctime(&t));
    return;
}

struct node {
    float coeff;
    int expo;
    struct node *link;
};

void display(struct node *head){
    if(head == NULL) {
        printf("Polynomial is empty.\n");
        return;
    }
    
    //printf("Corresponding polynomial is...\n");
    struct node *temp = head;
    while(temp != NULL) {
        if(temp->expo!=0){
            printf("(%1.fx^%d) ", temp->coeff, temp->expo);
        }
        else{
            printf("(%1.f) ", temp->coeff);
        }
        if(temp->link != NULL)
            printf("+ ");
        temp = temp->link;
    }
    printf("\n");
}

struct node *merge(struct node *head){
    struct node *temp = head;
    while(temp != NULL){
        struct node *ptr = temp;
        while(ptr->link != NULL){
            if(temp->expo == ptr->link->expo){
                temp->coeff += ptr->link->coeff;
                struct node *del = ptr->link;
                ptr->link = ptr->link->link;
                free(del);
            }
            else{
                ptr = ptr->link;
            }
        }
        temp = temp->link;
    }
    return head;
}

struct node *sort(struct node *head, float coef,int exp ){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->coeff = coef;
    temp->expo = exp;
    temp->link = NULL;
    
    if(head == NULL || head->expo < temp->expo){
        temp->link = head;
        head = temp;
        return head;
    }
    
    struct  node *ptr = head;
    while(ptr->link != NULL && ptr->link->expo > temp->expo) {
        ptr = ptr->link;
    }
    
    temp->link = ptr->link;
    ptr->link = temp;
    
    return head;
}

struct node *create(struct node *head){
    //printf("Enter terms of the polynomial...\n");
    printf("\n");
    int n, exp;
    float coeff;
    //printf("Enter number of terms in the polynomial: ");
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++) {
        printf("\nEnter coeff for term %d: ", i + 1);
        scanf("%f", &coeff);
        printf("Enter exponent for term %d: ", i + 1);
        scanf("%d", &exp);
        head = sort(head,coeff,exp );
    }
    head = merge(head);
    return head;
}

struct node*AddTo(struct node *head,struct node* head2){
    //printf("Enter terms of the polynomial...\n");
    printf("\n");
    int n, exp;
    float coeff;
    //printf("Enter number of terms in the polynomial: ");
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++) {
        printf("\nEnter coeff for term %d: ", i + 1);
        scanf("%f", &coeff);
        printf("Enter exponent for term %d: ", i + 1);
        scanf("%d", &exp);
        head = sort(exp, coeff, head);
    }
    head = merge(head);
    return head;
}

struct node *add(struct node *head1, int coeff,int expo){
     struct node*ptr1=head1;
    while(ptr1!=NULL){
        if(ptr1->expo==expo){
            head1=sort(head1,ptr1->coeff+coeff,ptr1->expo);
                ptr1=ptr1->link;
            }
        else if(ptr1->expo>expo){
            head1=sort(head1,ptr1->coeff,ptr1->expo);
            ptr1=ptr1->link;
            }
        
        else if(expo>ptr1->expo){
            head1=sort(head1,coeff,expo);
            }
}
while(ptr1!=NULL){
    head1=sort(head1,ptr1->coeff,ptr1->expo);
    ptr1=ptr1->link;
}
 return head1;   
}

int main() {
    info();
    struct node *head1 = NULL;
    printf("Enter number of terms in the polynomial 1...\n");
    head1 = create(head1);
    printf("Corresponding polynomial 1 is...\n");
    display(head1);
    printf("Enter number of terms in the polynomial 2...\n"); 
    printf("\n");
    int n, exp;
    float coeff;   
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        printf("\nEnter coeff for term %d: ", i + 1);
        scanf("%f", &coeff);
        printf("Enter exponent for term %d: ", i + 1);
        scanf("%d", &exp);
        head1= add(head1, coeff,exp );
    }
    printf("Resultant polynomial is...\n");
    display(head1);
    return 0;
}




