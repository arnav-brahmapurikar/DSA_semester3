#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *create(struct node *head, int n) {
    if (n == 0) {  // Handle the edge case where n is 0
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data = 0;
        temp->link = head;
        head = temp;
        return head;
    }
    while (n > 0) {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data = n % 10;
        temp->link = head;
        head = temp;
        n = n / 10;
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
    head1 = reverse(head1);
    head2 = reverse(head2);
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

void display(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        temp = temp->link;
    }
    printf("\n");
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
    struct node *head1 = NULL, *head2 = NULL;
    int n1, n2;
    
    printf("Enter number 1: ");
    scanf("%d", &n1);
    head1 = create(head1, n1);

    printf("Enter number 2: ");
    scanf("%d", &n2);
    head2 = create(head2, n2);

    struct node *result = add(head1, head2);
    
    printf("The sum is: ");
    display(result);
    
    freeList(head1);
    freeList(head2);
    freeList(result);

    return 0;
}