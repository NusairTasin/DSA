#include<bits/stdc++.h>
using namespace std;

class Queue {
    int front = 0, rear = 0, max = 100;
    char que[100];
    public:
    bool isEmpty() {
        return front == rear;
    }
    bool isFull() {
        return rear == max;
    }
    void enqueue(char c) {
        if (isFull()) {
            cout << "Overflow" << endl;
        } else {
            que[rear++] = c;
        }
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Underflow" << endl;
        } else {
            front++;
        }
    }
    char peek() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return 0;  // Sentinel value
        }
        return que[front];
    }
    void display() {
        for (int i = front; i < rear; i++) {
            cout << que[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q1;
}