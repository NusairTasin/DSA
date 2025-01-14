#include <iostream>
#include <string>
using namespace std;

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

bool isPalindrome(const string &inputString) { 
    FixedStack stack; // Push all characters of the string to the stack 
    for (char ch : inputString) { stack.push(ch); } // Pop characters from the stack and compare with the input string 
    for (char ch : inputString) { 
        if (ch != stack.pop()) { return false; } 
    } return true; 
} 
int main() { 
    string userInput; 
    cout << "Enter a string to check if it's a palindrome: "; 
    getline(cin, userInput); 
    if (isPalindrome(userInput)) { cout << "The string is a palindrome." << endl; } 
    else { cout << "The string is not a palindrome." << endl; } 
    return 0; 
}
