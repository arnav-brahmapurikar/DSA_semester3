#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *link;
};

struct node *insert(struct node *head, int n) {
    for (int i = 0; i < n; i++) {
        int d;
        printf("Enter digit %d: ", i + 1);
        scanf("%d", &d);
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data = d;
        temp->link = head;
        head = temp;
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

bool checkIfNull(const struct node *A[], int n) {
    for (int i = 0; i < n; i++) {
        if (A[i] != NULL) {
            return true;
        }
    }
    return false;
}

struct node *add(struct node *head1, struct node *head2) {
    struct node *result = NULL;
    int carry = 0;
    
    head1 = reverse(head1);
    head2 = reverse(head2);

    while (head1 != NULL || head2 != NULL || carry) {
        int sum = carry;
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

struct node *multiply(struct node *head1, struct node *head2) {
    struct node *result = NULL;
    int multiplier = 0;
    head1 = reverse(head1);
    head2 = reverse(head2);
    struct node *temp1 = head1;
    while (temp1 != NULL) {
        struct node *temp2 = head2;
        int carry = 0;
        struct node *partialResult = NULL;
        int zeros = multiplier;
        
        while (zeros--) {
            struct node *zeroNode = (struct node *)malloc(sizeof(struct node));
            zeroNode->data = 0;
            zeroNode->link = partialResult;
            partialResult = zeroNode;
        }

        while (temp2 != NULL || carry != 0) {
            int mul = (temp1->data) * (temp2 ? temp2->data : 0) + carry;
            carry = mul / 10;
            mul = mul % 10;

            struct node *newNode = (struct node *)malloc(sizeof(struct node));
            newNode->data = mul;
            newNode->link = partialResult;
            partialResult = newNode;

            if (temp2)
                temp2 = temp2->link;
        }

        result = add(result, partialResult);

        multiplier++;
        temp1 = temp1->link;
    }

    // result = reverse(result);
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

    printf("Enter the number of digits for number 1: ");
    scanf("%d", &n1);
    head1 = insert(head1, n1);
    display(head1);

    printf("Enter the number of digits for number 2: ");
    scanf("%d", &n2);
    head2 = insert(head2, n2);
    display(head2);

    struct node *result = multiply(head1, head2);

    printf("The multiplication is: ");
    display(result);

    freeList(head1);
    freeList(head2);
    freeList(result);

    return 0;
}