#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct Stack {
    static const int length = 100; // Define a constant for the stack size
    int num[length];
    int pointer;

    Stack() : pointer(0) {} // Constructor to initialize pointer

    void push(int val) {
        if (pointer == length) {
            cout << "Stack Overflow\n\n";
        } else {
            num[pointer] = val;
            pointer++;
        }
    }

    int pop() {
        if (pointer == 0) {
            cout << "Stack Underflow\n";
            return -1;
        } else {
            pointer--;
            return num[pointer];
        }
    }

    bool isEmpty() {
        return pointer == 0;
    }
};

int evaluatePostfix(string postfix) {
    Stack s;

    for (char &c : postfix) {
        if (isdigit(c)) {
            s.push(c - '0');
        } else {
            int val2 = s.pop();
            int val1 = s.pop();
            switch (c) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
            }
        }
    }
    return s.pop();
}

int main() {
    string postfix = "231*+9-";
    cout << "Postfix: " << postfix << endl;
    cout << "Evaluation: " << evaluatePostfix(postfix) << endl;
    return 0;
}
