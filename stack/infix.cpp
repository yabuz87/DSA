#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct Stack {
    static const int length = 100; // Define a constant for the stack size
    char num[length];
    int pointer;

    Stack() : pointer(0) {} // Constructor to initialize pointer

    void push(char val) {
        if (pointer == length) {
            cout << "Stack Overflow\n\n";
        } else {
            num[pointer] = val;
            pointer++;
        }
    }

    char pop() {
        if (pointer == 0) {
            cout << "Stack Underflow\n";
            return '\0';
        } else {
            pointer--;
            return num[pointer];
        }
    }

    char peek() {
        if (pointer == 0) {
            cout << "Stack is empty\n";
            return '\0';
        } else {
            return num[pointer - 1];
        }
    }

    bool isEmpty() {
        return pointer == 0;
    }
};

int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}

string infixToPostfix(string infix) {
    Stack s;
    string postfix = "";

    for (char &c : infix) {
        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                postfix += s.pop();
            }
            s.pop(); // Remove '('
        } else {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(c)) {
                postfix += s.pop();
            }
            s.push(c);
        }
    }

    while (!s.isEmpty()) {
        postfix += s.pop();
    }

    return postfix;
}

int main() {
    string infix = "A+B*(C^D-E)";
    cout << "Infix: " << infix << endl;
    cout << "Postfix: " << infixToPostfix(infix) << endl;
    return 0;
}
