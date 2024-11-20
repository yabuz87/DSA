#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Stack {
    Node* top;

    Stack() : top(nullptr) {} // Constructor to initialize top

    void push(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (top == nullptr) {
            cout << "Stack Underflow\n";
            return -1;
        } else {
            int data = top->data;
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

void decimalToBinary(int n) {
    Stack s;
    while (n > 0) {
        s.push(n % 2);
        n /= 2;
    }
    while (!s.isEmpty()) {
        cout << s.pop();
    }
    cout << endl;
}

int main() {
    int decimal = 10;
    cout << "Decimal: " << decimal << endl;
    cout << "Binary: ";
    decimalToBinary(decimal);
    return 0;
}
