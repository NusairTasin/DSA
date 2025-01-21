#include<bits/stdc++.h>
using namespace std;

class CircularQueue {
    int front = 0, rear = 0, max = 100;
    char que[100];
    public:
    bool isEmpty() {
        return front == rear;
    }
    bool isFull() {
        return (rear + 1) % max == front;
    }
    void enqueue(char c) {
        if (isFull()) {
            cout << "Overflow" << endl;
        } else {
            que[rear] = c;
            rear = (rear + 1) % max;
        }
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Underflow" << endl;
        } else {
            front = (front + 1) % max;
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
        for (int i = front; i != rear; i = (i + 1) % max) {
            cout << que[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q1;
}