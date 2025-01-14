#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void deletionAtHead(Node* &head) {
    Node* current = head;
    head = head->next;
    delete current;
}

void deletion(Node* &head, int val) {
    if(head->next == NULL) {
        deletionAtHead(head);
        return;
    }

    if(head == NULL) {
        return;
    }

    Node* current = head;

    while(current->next->data != val) current = current->next;

    Node* todelete = current->next;

    current->next = current->next->next;

    delete todelete;

}

void print(Node* head) {
    Node* current = head;
    while(current != nullptr) {
        cout<<" -> "<<current->data;
        current = current->next;
    }
}


int main() {
    Node* head = new Node{1};
    Node* second = new Node{2};
    Node* third = new Node{3};

    head->next = second;
    second->next = third;
    
    int val = 2;

    deletion(head,val);
    print(head);

    delete head;
    delete third;

    return 0;
}