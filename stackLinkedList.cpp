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

    void display() {
        Node* temp = top;
        if (temp == nullptr) {
            cout << "Stack is empty\n";
            return;
        }

        cout << "|----|\n";
        while (temp != nullptr) {
            cout << "| " <<  temp->data << "  |\n";
            temp = temp->next;
        }
        cout << "|____|\n";
    }
    void empty()
    {
        while(!isEmpty())
        {
            pop();
        }
    }
    void decimalToBinary(int n) {

        empty();
    while (n > 0) {
        push(n % 2);
        n/= 2;
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
    cout << "5. Decimal to binary\n\n6.format the stack\n\n";
    cout << "Enter your choice: ";
    int ch;
    cin >> ch;
    switch (ch) {
        int val, Op;
        case 1:
             system("cls");
            cout << "Enter value: ";
            cin >> val;
            s.push(val);
            s.display();
            cout<<"1. Back to menu     0.Exit\n\n";
            cin>>Op;
            if(Op==1)
            {system("cls");
              menu(s); }
            else
            break;
        case 2:
            system("cls");
            cout << "Popped value is " << s.pop() << endl;
            s.display();
            cout<<"1. Back to menu     0.Exit\n\n";
            cin>>Op;
            if(Op==1)
            {system("cls");
              menu(s); }
            else
            break;
        case 3:
            system("cls");
            cout << (s.isEmpty() ? "Stack is empty" : "Stack is not empty") << endl;
            cout<<"1. Back to menu     0.Exit\n\n";
            cin>>Op;
            if(Op==1)
            {system("cls");
              menu(s); }
            else
            break;
        case 4:
            system("cls");
            s.display();
           cout<<"1. Back to menu     0.Exit\n\n";
            cin>>Op;
            if(Op==1)
            {system("cls");
              menu(s); }
            else
            break;
        case 5:
            system("cls");
            cout << "Enter value: \n\n";
            cin >> val;
            s.decimalToBinary(val);
            cout<<"1. Back to menu     0.Exit\n\n";
            cin>>Op;
            if(Op==1)
            {system("cls");
              menu(s); }
            else
            break;
        case 6:
        system("cls");
        s.empty();
        s.display();
        cout<<"1. Back to menu     0.Exit\n\n";
        cin>>Op;
        if(Op==1)
            {system("cls");
              menu(s); }
            else
            break;
        default:
            cout << "Invalid choice\n";
            menu(s);
    }
    menu(s);
}



int main() {
    Stack s;
    menu(s);
    return 0;
}
