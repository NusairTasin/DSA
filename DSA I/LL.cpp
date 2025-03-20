#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *next;
    Node(int d) {
        data = d;
        next = nullptr;
    }
};

Node* head = NULL;

void insert(int data) {
    if(head == nullptr) {
        Node* newNode = new Node(data);
        head = newNode;
    }
    else {
        Node* temp = head;
        while(temp->next != nullptr) {
            temp = temp->next;
        }
        Node* newNode = new Node(data);
        temp->next = newNode;
    }
}

void insert(int data, int position) {
    if(head == nullptr) {
        insert(data);
        return;
    }
    Node* current = head;
    int count = 0;
    while(count < position - 1 && current->next != nullptr) {
        current = current->next;
        count++;
    }
    if(count == position - 1) {
        Node* newNode = new Node(data);
        newNode->next = current->next;
        current->next = newNode;
    }
    else cout << "Position not found" << endl;
}

void remove() {
    if (head == NULL) {
        cout << "Underflow" << endl;
    } else {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

void removeAt(int pos) {
    if (head == NULL) {
        cout << "Underflow" << endl;
    } else {
        Node *temp = head;
        if (pos == 0) {
            head = head->next;
            delete temp;
        } else {
            for (int i = 0; i < pos - 1 && temp->next != nullptr; i++) {
                temp = temp->next;
            }
            if (temp->next == nullptr) {
                cout << "Position not found" << endl;
                return;
            }
            Node *temp2 = temp->next;
            temp->next = temp2->next;
            delete temp2;
        }
    }
}

void display() {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main() {
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    display();
    insert(10,2);
    display();
    remove();
    display();
    removeAt(2);
    display();
    display();
    return 0;
}