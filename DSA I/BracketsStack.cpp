#include <iostream>
using namespace std;

class Stack {
    int top = 0, max = 100;
    char stk[100];

public:
    void pop() {
        if (top == 0) {
            cout << "Underflow" << endl;
        } else {
            top--;
        }
    }

    void push(char c) {
        if (top == max) {
            cout << "Overflow" << endl;
        } else {
            stk[top++] = c;
        }
    }

    bool isEmpty() {
        return top == 0;
    }

    char peek() {
        if (top == 0) {
            cout << "Stack is empty" << endl;
            return 0;  // Sentinel value
        }
        return stk[top - 1];
    }

    bool isValid(const string &s) {
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                push(c);
            } else {
                if (isEmpty() || 
                    (c == ')' && peek() != '(') || 
                    (c == '}' && peek() != '{') ||
                    (c == ']' && peek() != '[')) {
                    return false;
                }
                pop();
            }
        }
        return isEmpty();
    }
};

int main() {
    Stack s1;
    string s = "((()))";  // Test input
    cout << (s1.isValid(s) ? "Balanced" : "Not balanced") << endl;
    return 0;
}
