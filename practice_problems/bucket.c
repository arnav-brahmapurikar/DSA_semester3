#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Bucket structure containing pointers to head and tail of the linked list
struct Bucket {
    struct Node* head;
    struct Node* tail;
};

// Function to insert a node at the end of the linked list
void insertNode(struct Bucket* bucket, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (bucket->tail == NULL) {
        bucket->head = newNode;
        bucket->tail = newNode;
    } else {
        bucket->tail->next = newNode;
        bucket->tail = newNode;
    }
}

// Function to delete all nodes in the linked list
void deleteNodes(struct Bucket* bucket) {
    struct Node* current = bucket->head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    bucket->head = NULL;
    bucket->tail = NULL;
}

// Function to collect nodes from the buckets back into the array
void collectNodes(struct Bucket* buckets, int numBuckets, int* A) {
    int index = 0;
    for (int i = 0; i < numBuckets; i++) {
        struct Node* current = buckets[i].head;
        while (current != NULL) {
            A[index++] = current->data;
            current = current->next;
        }
        deleteNodes(&buckets[i]);
    }
}

// Function to find the maximum value in the array
int getMax(int A[], int n) {
    int maxVal = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] > maxVal) {
            maxVal = A[i];
        }
    }
    return maxVal;
}

// Radix Sort function
void radixSort(int A[], int n) {
    int maxVal = getMax(A, n);
    struct Bucket buckets[10];
    
    // Initialize buckets
    for (int i = 0; i < 10; i++) {
        buckets[i].head = NULL;
        buckets[i].tail = NULL;
    }

    // Sorting process
    for (int pos = 1; maxVal / pos > 0; pos *= 10) {
        // Distribute elements into buckets based on the current digit
        for (int i = 0; i < n; i++) {
            int digit = (A[i] / pos) % 10;
            insertNode(&buckets[digit], A[i]);
        }

        // Collect elements from buckets back into the array
        collectNodes(buckets, 10, A);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int* A = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    radixSort(A, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    free(A);
    return 0;
}
