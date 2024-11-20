#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

struct Stack {
    Node* top;

    Stack() : top(nullptr) {} // Constructor to initialize top

    void push(char val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = top;
        top = newNode;
    }

    char pop() {
        if (top == nullptr) {
            cout << "Stack Underflow\n";
            return '\0';
        } else {
            char data = top->data;
            Node* temp = top;
            top = top->next;
            delete temp;
            return data;
        }
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

bool isPalindrome(const string& str) {
    Stack s;
    int length = str.length();

    for (int i = 0; i < length / 2; i++) {
        s.push(str[i]);
    }

    for (int i = (length + 1) / 2; i < length; i++) {
        if (str[i] != s.pop()) {
            return false;
        }
    }
    return true;
}

int main() {
    string str = "radar";
    cout << "String: " << str << endl;
    cout << "Is Palindrome: " << (isPalindrome(str) ? "Yes" : "No") << endl;
    return 0;
}
