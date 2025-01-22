#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *next;
};
Node* head = NULL;

void insert(int data) {
    Node *temp = new Node();
    temp->data = data;
    temp->next = head;
    head = temp;
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
            for (int i = 0; i < pos - 1; i++) {
                temp = temp->next;
            }
            Node *temp2 = temp->next;
            temp->next = temp2->next;
            delete temp2;
        }
    }
}
void insertAt(int pos, int data) {
    Node *temp = new Node();
    temp->data = data;
    temp->next = NULL;
    if (pos == 0) {
        temp->next = head;
        head = temp;
    } else {
        Node *temp2 = head;
        for (int i = 0; i < pos - 1; i++) {
            temp2 = temp2->next;
        }
        temp->next = temp2->next;
        temp2->next = temp;
    }
}
void insertAtTail(int data) {
    Node *temp = new Node();
    temp->data = data;
    temp->next = NULL;
    if (head == NULL) {
        head = temp;
    } else {
        Node *temp2 = head;
        while (temp2->next != NULL) {
            temp2 = temp2->next;
        }
        temp2->next = temp;
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
    remove();
    display();
    removeAt(2);
    display();
    insertAt(2, 6);
    display();
    return 0;
}