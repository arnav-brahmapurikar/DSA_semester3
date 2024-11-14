#include<iostream>

using namespace std;

struct Node{
    int data;
    int priority;
    Node* next;
};

Node* createNode(int data,int priority){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = nullptr;
    return newNode;
}

void insertBeginning(Node** head, int data, int priority){
    Node* newNode = createNode(data,priority);
    if(*head == nullptr){
        *head = newNode;
    }else{
        newNode->next = *head;
        *head = newNode;
    }
}

void insertNode(struct Node** head, int data, int priority){
    if(*head == nullptr || (*head)->priority < priority){
        insertBeginning(head, data, priority);
    }else{
        Node* ptr = *head;
        while(ptr->next != nullptr && ptr->next->priority > priority){
            ptr = ptr->next;
        }
        Node* newNode = createNode(data, priority);
        newNode->next = ptr->next;
        ptr->next = newNode;
    }
}


void printList(Node* head){
    Node* ptr = head;
    while(ptr != nullptr){
        cout<<ptr->data<<","<<ptr->priority<<(ptr->next!=nullptr?" -> ":"");
        ptr = ptr->next;
    }
    cout<<endl;
}

int main(){
    Node* head = nullptr;
    insertNode(&head, 4, 2);
    insertNode(&head, 6, 1);
    insertNode(&head, 12, 4);
    insertNode(&head, 78, 7);
    insertNode(&head, 34, 9);
    insertNode(&head, 98, 2);
    insertNode(&head, 11, 6);
    insertNode(&head, 7, 5);
    insertNode(&head, 8, 8);

    printList(head);
}