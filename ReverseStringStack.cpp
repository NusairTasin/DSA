#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class FixedStack {
private:
    int top;
    char items[MAX_SIZE];

public:
    FixedStack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void push(char item) {
        if (!isFull()) {
            items[++top] = item;
        } else {
            cout << "Stack is full\n";
        }
    }

    char pop() {
        if (!isEmpty()) {
            return items[top--];
        } else {
            return '\0'; // Return null character if stack is empty
        }
    }

    char peek() {
        if (!isEmpty()) {
            return items[top];
        } else {
            return '\0';
        }
    }

    int size() {
        return top + 1;
    }
};


string reverseString(const string &inputString) { 
    FixedStack stack; // Push all characters of the string to the stack 
    for (char ch : inputString) { stack.push(ch); } // Pop all characters from the stack and form the reversed string 
    string reversedString; 
    while (!stack.isEmpty()) { reversedString += stack.pop(); } 
    return reversedString; 
} 
int main() { 
    string userInput; 
    cout << "Enter a string to reverse: "; 
    getline(cin, userInput); 
    string reversed = reverseString(userInput); 
    cout << "Reversed string: " << reversed << endl; 
    return 0;
}