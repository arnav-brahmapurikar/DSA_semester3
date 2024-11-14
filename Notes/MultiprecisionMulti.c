#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *link;
};

struct node *create(int n, struct node *head)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = n;
    temp->link = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        struct node *ptr = head;
        while (ptr->link != NULL)
        {
            ptr = ptr->link;
        }
        ptr->link = temp;
    }
    return head;
}

struct node *linkedlist(char n[])
{
    struct node *head = NULL;
    for (int i = 0; i < strlen(n); i++)
    {
        head = create(n[i] - '0', head);
    }
    return head;
}

struct node *reverse(struct node *head)
{
    struct node *prev = NULL, *next = NULL, *curr = head;
    while (curr != NULL)
    {
        next = curr->link;
        curr->link = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

struct node *add(struct node *head1, struct node *head2)
{
    struct node *result = NULL;
    int carry = 0;

    head1 = reverse(head1);
    head2 = reverse(head2);

    while (head1 != NULL || head2 != NULL || carry)
    {
        int sum = carry;
        if (head1 != NULL)
        {
            sum += head1->data;
            head1 = head1->link;
        }
        if (head2 != NULL)
        {
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

struct node *multiply(struct node *head1, struct node *head2)
{

    struct node *result = NULL;
    int multiplier = 0;

    struct node *temp1 = reverse(head1);
    head2 = reverse(head2);
    while (temp1 != NULL)
    {
        struct node *temp2 = head2;
        int carry = 0;
        struct node *partialResult = NULL;
        int zeros = multiplier;

        while (zeros--)
        {
            struct node *zeroNode = (struct node *)malloc(sizeof(struct node));
            zeroNode->data = 0;
            zeroNode->link = partialResult;
            partialResult = zeroNode;
        }

        while (temp2 != NULL || carry != 0)
        {
            int mul = (temp1->data) * (temp2 ? temp2->data : 0) + carry;
            carry = mul / 10;
            mul = mul % 10;

            struct node *newNode = (struct node *)malloc(sizeof(struct node));
            newNode->data = mul;
            newNode->link = partialResult;
            partialResult = newNode;

            if (temp2 != NULL)
                temp2 = temp2->link;
        }

        result = add(result, partialResult);

        multiplier++;
        temp1 = temp1->link;
    }

    return result;
}

void display(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->link;
    }
    printf("\n");
    return;
}

void freeList(struct node *head)
{
    struct node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->link;
        free(temp);
    }
    return;
}

int main()
{
    char num1[100];
    char num2[100];

    printf("Enter number 1...");
    scanf("%s", num1);

    printf("Enter number 2...");
    scanf("%s", num2);

    struct node *head1 = NULL, *head2 = NULL;

    head1 = linkedlist(num1);
    display(head1);
    head2 = linkedlist(num2);
    display(head2);

    struct node *result = multiply(head1, head2);

    printf("The product is: ");
    display(result);

    freeList(head1);
    freeList(head2);
    freeList(result);

    return 0;
}