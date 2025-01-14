#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void find(Node* head, bool found) {
    Node* current = head;

    while(current != nullptr) {
        if(current->data == 69) found = true;
        
        current = current->next;
    }
    (found == true) ? cout<<"The value is found" : cout<<"The value is missing";
}

int main() {
    Node* head = new Node{1};
    Node* second = new Node{69};
    Node* third = new Node{3};

    head->next = second;
    second->next = third;

    bool found = false;

    find(head,found);

    delete head;
    delete second;
    delete third;

    return 0;
}