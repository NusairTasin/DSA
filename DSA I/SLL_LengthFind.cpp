#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void findLength(Node* head, int length) {
    Node* current = head;

    while(current != nullptr) {
        length++;
        
        current = current->next;
    }
    cout<<"The length of the linked list is : "<<length;
}

int main() {
    Node* head = new Node{1};
    Node* second = new Node{69};
    Node* third = new Node{3};

    head->next = second;
    second->next = third;

    int length = 0;

    findLength(head, length);

    delete head;
    delete second;
    delete third;

    return 0;
}