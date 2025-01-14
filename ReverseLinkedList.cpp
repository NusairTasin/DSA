#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
Node *head = NULL;

void insertAtHead (int value) {
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void print() {
    Node *temp = head;
    while(temp != NULL) {
        cout<<"->"<<temp->data;
        temp = temp->next;
    }
    cout<<endl;
}

void reverseList() {
    Node *prev = nullptr;
    Node *cur = head;
    Node *nxt = nullptr;
    while(cur!=NULL) {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;  
    }
    head = prev;
}

int main() {
    insertAtHead(10);
    insertAtHead(20);
    insertAtHead(30);
    insertAtHead(40);
    insertAtHead(50);
    print();
    cout<<head->data<<endl;
    reverseList();
    cout<<head->data<<endl;
    print();
}
