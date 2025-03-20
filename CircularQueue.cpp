#include <iostream>
using namespace std;

class CircularQueue {
    int front, rear, max;
    char que[100];

public:
    CircularQueue(int max) {
        this->max = max;
        front = -1;
        rear = -1;
    }
    bool isEmpty() {
        return front == -1;
    }
    bool isFull() {
        return (rear + 1) % max == front;
    }
    void enqueue(char c) {
        if (isFull()) {
            cout << "Overflow" << endl;
        } else {
            if (front == -1) front = 0;
            rear = (rear + 1) % max;
            que[rear] = c;
        }
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Underflow" << endl;
        } else if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % max;
        }
    }
    char peek() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return 0;
        }
        return que[front];
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        } else {
            for (int i = front; i != rear; i = (i + 1) % max) {
                cout << que[i] << " ";
            }
            cout << que[rear] << endl;
        }
    }
};

int main() {
    CircularQueue q1(3);
    q1.enqueue('A');
    q1.enqueue('B');
    q1.enqueue('C');
    q1.display();
    q1.enqueue('D');
    q1.display();
    q1.dequeue();
    q1.display();
    return 0;
}
