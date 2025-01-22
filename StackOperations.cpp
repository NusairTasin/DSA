#include<bits/stdc++.h>
using namespace std;

class Stack {
    int top = 0, max = 100;
    char stk[100];
    public:
    bool isEmpty() {
        return top == 0;
    }
    bool isFull() {
        return top == max;
    }
    void push(char c) {
        if (isFull()) {
            cout << "Overflow" << endl;
        } else {
            stk[top++] = c;
        }
    }
    void pop() {
        if (isEmpty()) {
            cout << "Underflow" << endl;
        } else {
            top--;
        }
    }
    char peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return 0;  // Sentinel value
        }
        return stk[top - 1];
    }
};

int main() {
    Stack s1;
}