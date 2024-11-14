/*
here for collecting array back fifo is used
*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

int countDig(int n)
{
    int x = 0;
    while (n)
    {
        x++;
        n = n / 10;
    }
    return x;
}

int max(int n, int A[])
{
    int a = 0;
    for (int i = 0; i < n; i++)
    {
        int b = countDig(A[i]);
        if (b > a)
        {
            a = b;
        }
    }
    return a;
}

void radixSort(int n, int B[])
{
    struct node *bean[10];
    struct node *last[10]; // Array to track the last node in each bucket
    int f = 1;  
    int digit = max(n, B);

    while (digit--)
    {
        // Initialize the bean and last arrays for each pass
        for (int i = 0; i < 10; i++)
        {
            bean[i] = NULL;
            last[i] = NULL;
        }

        // Distribute elements based on the current digit
        for (int i = 0; i < n; i++)
        {
            int index = (B[i] / f) % 10;
            struct node *temp = (struct node *)malloc(sizeof(struct node));
            temp->data = B[i];
            temp->link = NULL;

            if (bean[index] == NULL)    
            {
                bean[index] = temp;
                last[index] = temp;
            }
            else
            {
                last[index]->link = temp;
                last[index] = temp;
            }
        }

        // Collect the elements back into the array in FIFO order
        int j = 0;
        for (int i = 0; i < 10; i++)
        {
            struct node *temp = bean[i];
            while (temp != NULL)
            {
                B[j++] = temp->data;
                struct node *ptr = temp;
                temp = temp->link;
                free(ptr);
            }
        }

        f *= 10;
    }
    return;
}

void display(int n, int A[])
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", A[i]);
    }
    printf("\n");
    return;
}

void input(int n, int A[])
{
    printf("Enter %d elements of the array...\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    return;
}

int main()
{
    int n;
    printf("Enter number of elements of array: ");
    scanf("%d", &n);
    int A[n];
    input(n, A);

    printf("Entered array is....\n");
    display(n, A);

    radixSort(n, A);

    printf("Sorted array is....\n");
    display(n, A);

    return 0;
}