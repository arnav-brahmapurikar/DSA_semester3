#include <stdio.h>
#include <stdlib.h>

struct node {
    float coeff;
    int expo;
    struct node* next;
};

void print(struct node* head) {
    if (head == NULL) {
        printf("No Polynomial\n");
    } else {
        struct node* temp = head;
        while (temp != NULL) {
            printf("%.1fx^%d", temp->coeff, temp->expo);  // use .1f for one decimal place
            temp = temp->next;
            if (temp != NULL) {
                printf(" + ");
            } else {
                printf("\n");
            }
        }
    }
}

struct node* insert(struct node* head, float co, int exp) {
    struct node* temp;
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->coeff = co;
    new_node->expo = exp;
    new_node->next = NULL;

    if (head == NULL || exp > head->expo) {
        new_node->next = head;
        head = new_node;
        return head;
    } else {
        temp = head;
        while (temp->next != NULL && temp->next->expo > exp) {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
    return head;
}

struct node* create(struct node* head) {
    int i, n, expo;
    float coeff;
    printf("Enter Number of terms: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter the Coeff: ");
        scanf("%f", &coeff);
        printf("Enter the Power: ");
        scanf("%d", &expo);
        head = insert(head, coeff, expo);
    }
    return head;
}

void polyAdd(struct node* head1, struct node* head2) {
    struct node* ptr1 = head1;
    struct node* ptr2 = head2;
    struct node* head3 = NULL;

    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->expo == ptr2->expo) {
            head3 = insert(head3, ptr1->coeff + ptr2->coeff, ptr1->expo);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        } else if (ptr1->expo > ptr2->expo) {
            head3 = insert(head3, ptr1->coeff, ptr1->expo);
            ptr1 = ptr1->next;
        } else {
            head3 = insert(head3, ptr2->coeff, ptr2->expo);
            ptr2 = ptr2->next;
        }
    }

    while (ptr1 != NULL) {
        head3 = insert(head3, ptr1->coeff, ptr1->expo);
        ptr1 = ptr1->next;
    }

    while (ptr2 != NULL) {
        head3 = insert(head3, ptr2->coeff, ptr2->expo);
        ptr2 = ptr2->next;
    }

    printf("The Polynomial is: ");
    print(head3);
}

int main() {
    struct node* head1 = NULL;
    struct node* head2 = NULL;

    printf("Create first polynomial:\n");
    head1 = create(head1);
    printf("First polynomial: ");
    print(head1);

    printf("Create second polynomial:\n");
    head2 = create(head2);
    printf("Second polynomial: ");
    print(head2);

    printf("Sum of polynomials:\n");
    polyAdd(head1, head2);

    return 0;
}
