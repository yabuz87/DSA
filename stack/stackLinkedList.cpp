#include <iostream>
using namespace std;

struct Node {
    int data;
    char alpha;
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
    void push(char val) {
        Node* newNode = new Node();
        newNode->alpha = val;
        newNode->next = top;
        top = newNode;
    }

    bool isPalindrome(string str) {
        int length = str.length();

        for (int i = 0; i < length / 2; i++) {
            push(str[i]);
        }

        for (int i = (length + 1) / 2; i < length; i++) {
            if (str[i] != pop(str)) {
                return false;
            }
        }
        return true;
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

    char pop(string n) {
        if (top == nullptr) {
            cout << "Stack Underflow\n";
            return -1;
        } else {
            char data = top->alpha;
            Node* temp = top;
            top = top->next;
            delete temp;
            return data;
        }
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void display() {
        Node* temp = top;
        if (temp == nullptr) {
            cout << "Stack is empty\n";
            return;
        }

        cout << "|----|\n";
        while (temp != nullptr) {
            cout << "| " << temp->data << "  |\n";
            temp = temp->next;
        }
        cout << "|____|\n";
    }

    void empty() {
        while (!isEmpty()) {
            pop();
        }
    }

    void decimalToBinary(int n) {
        empty();
        while (n > 0) {
            push(n % 2);
            n /= 2;
        }
        while (!isEmpty()) {
            cout << pop();
        }
        cout << endl;
    }
};

void menu(Stack &s) {
    cout << "\n\n<<<<<Linked List based Stack>>>>>>\n\n";
    cout << "1. Push\n\n";
    cout << "2. Pop\n\n";
    cout << "3. isEmpty\n\n";
    cout << "4. Display\n\n";
    cout << "5. Palindrome Check\n\n6. Decimal to binary\n\n";
    cout << "Enter your choice: ";
    int ch;
    cin >> ch;
    switch (ch) {
        int val, Op;
        case 1: {
            system("cls");
            cout << "Enter value: ";
            cin >> val;
            s.push(val);
            s.display();
            cout << "1. Back to menu     0.Exit\n\n";
            cin >> Op;
            if (Op == 1) {
                system("cls");
                menu(s);
            } else
                break;
            break;
        }
        case 2: {
            system("cls");
            cout << "Popped value is " << s.pop() << endl;
            s.display();
            cout << "1. Back to menu     0.Exit\n\n";
            cin >> Op;
            if (Op == 1) {
                system("cls");
                menu(s);
            } else
                break;
            break;
        }
        case 3: {
            system("cls");
            cout << (s.isEmpty() ? "Stack is empty" : "Stack is not empty") << endl;
            cout << "1. Back to menu     0.Exit\n\n";
            cin >> Op;
            if (Op == 1) {
                system("cls");
                menu(s);
            } else
                break;
            break;
        }
        case 4: {
            system("cls");
            s.display();
            cout << "1. Back to menu     0.Exit\n\n";
            cin >> Op;
            if (Op == 1) {
                system("cls");
                menu(s);
            } else
                break;
            break;
        }
        case 5: {
            system("cls");
            cout << "Enter the String: \n\n";
            string Str = " ";
            cin >> Str;
            cout << "\n\n\""<< Str <<"\" is " << (s.isPalindrome(Str) ? " " : "Not ") <<"Palindrome."<< endl;
            cout << "1. Back to menu     0.Exit\n\n";
            cin >> Op;
            if (Op == 1) {
                system("cls");
                menu(s);
            } else
                return;
            break;
        }
        case 6: {
            system("cls");
            cout << "Enter the number\n\n";
            cin >> val;
            s.decimalToBinary(val);
            s.display();
            cout << "1. Back to menu     0.Exit\n\n";
            cin >> Op;
            if (Op == 1) {
                system("cls");
                menu(s);
            } else
                break;
            break;
        }
        default: {
            system("cls");
            cout << "Invalid choice\n";
            menu(s);
            break;
        }
    }
}

int main() {
    Stack s;
    menu(s);
    return 0;
}
