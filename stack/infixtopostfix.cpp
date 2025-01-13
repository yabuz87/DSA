#include <iostream>
#include <string>
using namespace std;

struct stack {
    char ch[20];
    int top = -1;

    void push(char val) {
        if (top >= 19) {
            cout << "stack overflow" << endl;
            return;
        }
        ch[++top] = val;
    }

    void display() {
        if (top == -1) {  // Use -1 to check if stack is empty
            cout << "Stack is empty" << endl;
        } else {
            cout << "|---|" << endl;
            for (int i = top; i >= 0; i--) {
                cout << "| " << ch[i] << " |" << endl;
            }
            cout << "|___|" << endl;
        }
    }

    char pop() {
        if (top <= -1) {
            cout << "stack underflow" << endl;
            return '0';  // Indicates stack underflow
                       }
        return ch[top--];  // Corrected sequence: Decrement top after returning the value
               }

    char peak() {
        if (top >= 0) {
            return ch[top];
        } else {
            cout << "stack is empty" << endl;
            return '0';  // Indicates empty stack
        }
    }

    int precedence(char op) {
        if (op == '+' || op == '-') {
            return 1;
        }
        if (op == '*' || op == '/') {
            return 2;
        }
        if (op == '^') {
            return 3;
        }
        return 0;
    }

    char* postfixToinfix(string str) {
        int n = str.length();
        char* arr = new char[n + 1];  // Ensure enough space and null-terminated
        int count = 0;
        int i = 0;

        while (i < n) {
            if (isalpha(str[i])|| isdigit(str[i])) {
                cout << str[i] << endl;
                arr[count++] = str[i];
                i++;
                continue;
            } else if (str[i] == '(') {
                push(str[i]);
                display();
                i++;
                continue;
            } else if (str[i] == ')') {
                while (peak() != '(') {
                    arr[count++] = pop();
                }
                pop();  // Pop the '(' from the stack
                display();
                i++;
                continue;
            } else if (str[i] == '^') {
                push(str[i]);
                display();
                i++;
                continue;
            } else {
                while (top != -1 && precedence(peak()) >= precedence(str[i])) {
                    arr[count++] = pop();
                }
                push(str[i]);
                display();
                i++;
            }
        }

        // Pop all the operators left in the stack
        while (top != -1) {
            arr[count++] = pop();
        }
        arr[count] = '\0';  // Null-terminate the array

        return arr;
    }
};

int main() {
    stack s;
    char* np = s.postfixToinfix("a*(o+h)+b*(c+d)");
    cout << np << endl;
    delete[] np;  // Free the allocated memory
    return 0;
}
