#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertHead(Node*& head) {
    Node* new_node = new Node;
    new_node->data = 4;

    new_node->next = head;
    head = new_node;
}

void traverse(Node* head) {
    Node* current = head;

    while(current != nullptr) {
        cout<<current->data<<" ";
        current = current->next;
    }
}

int main() {
    Node* head = new Node{1};
    Node* second = new Node{2};
    Node* third = new Node{3};

    head->next = second;
    second->next = third;

    insertHead(head);
    traverse(head);

    delete head;
    delete second;
    delete third;

    return 0;
}