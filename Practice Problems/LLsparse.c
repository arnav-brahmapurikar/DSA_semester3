#include<stdio.h>
#include<stdlib.h>

struct node {
    int val;
    int r;
    int c;
    struct node* next;
};

// Function to insert an element into the linked list representing a sparse matrix
struct node* Insert(struct node* head, int val, int r, int c) {
    struct node* temp = head;
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->c = c;
    new->r = r;
    new->val = val;
    new->next = NULL;

    if (head == NULL) {  // Fixed the comparison from head=NULL to head==NULL
        head = new;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new;
    }
    return head;
}

// Function to add two sparse matrices represented by linked lists
struct node* Addition(struct node* head1, struct node* head2) {
    struct node* result = NULL;
    struct node* temp1 = head1;
    struct node* temp2 = head2;

    while (temp1 != NULL || temp2 != NULL) {
        int r, c, val;
        if (temp1 != NULL && (temp2 == NULL || temp1->r < temp2->r || (temp1->r == temp2->r && temp1->c < temp2->c))) {
            r = temp1->r;
            c = temp1->c;
            val = temp1->val;
            temp1 = temp1->next;
        } else if (temp2 != NULL && (temp1 == NULL || temp2->r < temp1->r || (temp2->r == temp1->r && temp2->c < temp1->c))) {
            r = temp2->r;
            c = temp2->c;
            val = temp2->val;
            temp2 = temp2->next;
        } else {
            r = temp1->r;
            c = temp1->c;
            val = temp1->val + temp2->val;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        result = Insert(result, val, r, c);
    }

    return result;
}

// Function to input a sparse matrix and return its linked list representation
struct node* inputMatrix(int r, int c) {
    struct node* head = NULL;  // Initialize head to NULL
    printf("Enter elements...\n\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("Enter element for (%d,%d)...", i + 1, j + 1);
            int el;
            scanf("%d", &el);
            if (el != 0) {
                head = Insert(head, el, i, j);
            }
        }
    }
    return head;
}

// Function to print the linked list representation of a sparse matrix
void printMatrix(struct node* head) {
    struct node* temp = head;
    printf("Sparse Matrix Representation:\n");
    while (temp != NULL) {
        printf("Value: %d at Position (%d, %d)\n", temp->val, temp->r + 1, temp->c + 1);
        temp = temp->next;
    }
}

int main() {
    int m, n, p, q;
    printf("Enter row and column values respectively for 1st Matrix\n");
    scanf("%d %d", &m, &n);

    struct node* head1 = inputMatrix(m, n);

    printf("Enter row and column values respectively for 2nd Matrix\n");
    scanf("%d %d", &p, &q);

    if (m != p || n != q) {
        printf("Matrices cannot be added as their dimensions do not match.\n");
        return 1;
    }

    struct node* head2 = inputMatrix(p, q);

    struct node* result = Addition(head1, head2);

    printf("\nFirst Matrix:\n");
    printMatrix(head1);

    printf("\nSecond Matrix:\n");
    printMatrix(head2);

    printf("\nResultant Matrix after Addition:\n");
    printMatrix(result);

    return 0;
}
