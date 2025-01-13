#include <iostream>
#include <string>

using namespace std;

struct Stack {
    string eval[20];
    int pointer = -1;

    void push(string a) {
        if(pointer < 20) {
            eval[++pointer] = a;
        } else {
            cout << "stack overflow\n";
        }
    }

    string pop() {
        if(pointer == -1) {
            cout << "stack underflow\n";
            return "-1";
        } else {
            return eval[pointer--];
        }
    }

    string infixtoPostfix(string a) {
        int n = a.length();
        for(int i = 0; i < n; i++) {
            if(isalnum(a[i])) {
                push(string(1, a[i]));
            } else {
                string op1 = pop();
                string op2 = pop();
                if(a[i] == '+') {
                    push("(" + op2 + "+" + op1 + ")");
                } else if(a[i] == '-') {
                    push("(" + op2 + "-" + op1 + ")");
                } else if(a[i] == '*') {
                    push("(" + op2 + "*" + op1 + ")");
                } else if(a[i] == '/') {
                    push("(" + op2 + "/" + op1 + ")");
                } else if(a[i] == '^') {
                    push("(" + op2 + "^" + op1 + ")");
                }
            }
        }
        return pop();
    }
};

int main() {
    Stack n;
    string np = n.infixtoPostfix("aoh+*bcd+*+");
    cout << np;
}
