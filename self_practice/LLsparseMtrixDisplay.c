#include <stdio.h>
#include <stdlib.h>

struct nodeSparse {
    int val;
    int col;
    int row;
    struct nodeSparse *link;
};

struct matrixInfo {
    int rowNum;
    int colNum;
    struct nodeSparse *headAddress;
};

struct nodeSparse *create(struct nodeSparse *head, int n, int r, int c) {
    struct nodeSparse *temp = (struct nodeSparse *)malloc(sizeof(struct nodeSparse));
    temp->col = c;
    temp->row = r;
    temp->val = n;
    temp->link = NULL;

    if (head == NULL) {
        head = temp;
    } else {
        struct nodeSparse *ptr = head;
        while (ptr->link != NULL) {
            ptr = ptr->link;
        }
        ptr->link = temp;
    }
    return head;
}

struct nodeSparse *inputMatrix(int r, int c) {
    struct nodeSparse *head = NULL;
    printf("Enter elements...\n\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("Enter element for (%d,%d)...", i + 1, j + 1);
            int el;
            scanf("%d", &el);
            if (el != 0) {
                head = create(head, el, i, j);
            }
        }
    }
    return head;
}

void displayMatrix(struct matrixInfo m) {
    struct nodeSparse *temp = m.headAddress;
    int r = m.rowNum, c = m.colNum;
    printf("Matrix: \n\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (temp != NULL && temp->row == i && temp->col == j) {
                printf("%d\t", temp->val);
                temp = temp->link;
            } else {
                printf("0\t");
            }
        }
        printf("\n");
    }
}

void freeSparseMatrix(struct nodeSparse *head) {
    struct nodeSparse *temp;
    while (head != NULL) {
        temp = head;
        head = head->link;
        free(temp);
    }
}

int main() {
    int m, n;
    printf("Enter row and column values respectively...\n");
    scanf("%d %d", &m, &n);

    struct nodeSparse *head = inputMatrix(m, n);

    struct matrixInfo m1;
    m1.rowNum = m;
    m1.colNum = n;
    m1.headAddress = head;

    displayMatrix(m1);

    freeSparseMatrix(m1.headAddress);

    return 0;
}