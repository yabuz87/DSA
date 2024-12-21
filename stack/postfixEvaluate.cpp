#include <iostream>
using namespace std;

struct stack {
    float num[15];
    int top = -1;

    void push(float val) {
        if(top >= 14) {  // Use >= 14 to ensure array bounds are not exceeded
            cout << "Stack overflow" << endl;
            return;
        }
        num[++top] = val;
    }

    float pop() {
        if(top == -1) {
            cout << "Stack underflow" << endl;
            return -1;
        }
        return num[top--];
    }

    void display() {
        if(top == -1) {  // Use -1 to check if stack is empty
            cout << "Stack is empty" << endl;
        } else {
            cout << "|---|" << endl;
            for(int i = top; i >= 0; i--) {
                cout << "| " << num[i] << " |" << endl;
            }
            cout << "|___|" << endl;
        }
    }

    float postfixEvaluate(string str) {
        int n = str.length();
        int i = 0;
        while(i < n) {
            if(isdigit(str[i])) {
                push(str[i] - '0');
            } else {
                float a = pop();
                float b = pop();
                switch(str[i]) {
                    case '+':
                        push(b + a);
                        break;
                    case '-':
                        push(b - a);
                        break;
                    case '*':
                        push(b * a);
                        break;
                    case '/':
                        push(b / a);
                        break;
                }
            }
            i++;
        }
        return pop();
    }
};

int main() {
    stack s;
    cout << s.postfixEvaluate("6523+8*+3+*") << endl;
    return 0;
}
// Frontend Developer Expanding Skills in Backend Development with Node.js
