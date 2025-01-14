#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* reverse(Node* &head) {
    Node* prev = NULL;
    Node* cur = head;
    Node* nex;

    while(cur != NULL) {
        nex = cur->next;
        cur->next = prev;

        prev = cur;
        cur = nex;
    }
    return prev;
}

Node* recursiverev(Node* &head) {
    if(head == NULL || head->next == NULL) return head;

    Node* newnode = recursiverev(head->next);

    head->next->next = head;
    head->next = NULL;
    return newnode;
}

void print(Node* head) {
    Node* current = head;
    while(current != nullptr) {
        cout<<" -> "<<current->data;
        current = current->next;
    }
    cout<<endl;
}


int main() {
    Node* head = new Node{1};
    Node* second = new Node{2};
    Node* third = new Node{3};
    Node* fourth = new Node{4};
    Node* fifth = new Node{5};
    Node* sixth = new Node{6};

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    
    
    print(head);

    Node* newhead = recursiverev(head);

    print(newhead);

    delete head;
    delete third;

    return 0;
}