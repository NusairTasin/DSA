#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void insertAtHead(int a) {
    Node* newNode = new Node;
    newNode->data = a;
    newNode->next = head;  // New node points to the current head
    head = newNode;        // Head is now the new node
}

void insertAtTail(int a) {
    Node* newNode = new Node;
    newNode->data = a;
    newNode->next = nullptr;
    if (head == nullptr) { // If the list is empty
        head = newNode;
    } else {
        Node* cur = head;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = newNode;
    }
}

void deletion(int a) {
    if (head == nullptr) {
        cout << "Empty linked list!" << endl;
        return;
    }

    if (head->data == a) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* prev = head;
    while (prev->next != nullptr && prev->next->data != a) {
        prev = prev->next;
    }

    if (prev->next == nullptr) {
        cout << "Element not found!" << endl;
        return;
    }

    Node* deleteN = prev->next;
    prev->next = prev->next->next;
    delete deleteN;
}

void display() {
    Node* cur = head;
    while (cur != nullptr) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

int main() {
    insertAtHead(10);
    insertAtTail(20);
    insertAtTail(30);
    insertAtHead(5);

    cout << "Current List: ";
    display();

    deletion(30);
    cout << "After Deletion: ";
    display();

    return 0;
}
