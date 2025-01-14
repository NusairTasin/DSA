#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
Node *head = NULL;

void insertAtHead(int value) {
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void print() {
    Node *temp = head;
    while (temp != NULL) {
        cout << "->" << temp->data;
        temp = temp->next;
    }
    cout << endl;
}

void reorderList(int value) {
    Node *prev = nullptr;
    Node *cur = head;

    // Find the node containing the value and reverse nodes before it
    while (cur != nullptr && cur->data != value) {
        Node *nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }

    // cur is now at the node with the specified value
    if (cur != nullptr) {
        // At this point, 'cur' is the node with the specified value.
        // Reverse part of the list before that node
        Node *temp = cur->next;
        cur->next = prev;  // Reverse the part before the node with 'value'

        Node* mainH = head;
        // Now, the new head is 'cur'
        head = cur;

        // Move 'cur' to the last node of the reversed part
        // while (cur->next != nullptr) {
        //     cur = cur->next;
        // }

        // Connect the remaining part of the list
        mainH->next = temp;
    }
}

int main() {
    insertAtHead(10);
    insertAtHead(20);
    insertAtHead(30);
    insertAtHead(40);
    insertAtHead(50);
    insertAtHead(60);
    insertAtHead(70);

    print();
    cout << head->data << endl;

    reorderList(40); // Reorder the list to make 40 the head
    
    cout << head->data << endl;
    print();
}
