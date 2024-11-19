#include <iostream>
using namespace std;

struct Stack {
    static const int length = 10; // Define a constant for the stack size
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

    void pop() {
        if (pointer == 0) {
            cout << "Stack Underflow\n";
        } else {
            pointer--;
        }
    }

    void peek() {
        if (pointer == 0) {
            cout << "Stack is empty\n";
        } else {
            cout << num[pointer - 1] << endl;
        }
    }

    void display() {
        if (pointer == 0) {
            cout << "Stack is empty\n";
        } else {
                cout<<"|---|"<<endl;
            for (int i = pointer-1; i >= 0; i--) {
                cout <<"| "<< num[i] << " |"<<endl;
            }
            cout<<"|___|";
            cout << endl;
        }
    }
    void isEmpty()
    {
        if(pointer==0)
        {
            cout<<"Yes the Stack is empty\n\n";
            return;
        }
        else
        {
            cout<<"Nope the stack is not empty\n\n";
            return;
        }
    }
};
//use the concept to  do palindrome
// decimal to binary
//infix postfix
//postfix evaluator
//decimal to binary and palindrome should be linkedList based.
// gotchaaaaaaa

void menu(Stack *&s)
{
    cout << "\n\n\t\t<<<<<<<Stack Menu>>>>>>>\n\n";
    cout<<"1.push\n\n2.pop\n\n3.display\n\n4.isEmpty\n\n5.peek\n\n";
    int option,val,Op;
    cin>>option;
    switch(option)
    {
        case 1:
        cout<<"Enter the number/ value\n\n";
        cin>>val;
        s->push(val);
        system("CLS");
        cout<<"\n1.Back to menu  0. Exit\n\n";
        cin>>Op;
        if(Op==1)
        {
            system("CLS");
            menu(s);
        }
        else{
            return;
        }
        break;
        case 2:
        s->pop();
        system("CLS");
        cout<<"\n1.Back to menu  0. Exit\n\n";
        cin>>Op;
        if(Op==1)
        {
            system("CLS");
            menu(s);
        }
        else{
            return;
        }
        break;
        case 3:
        system("CLS");
        s->display();
        cout<<"\n1.Back to menu  0. Exit\n\n";
        cin>>Op;
        if(Op==1)
        {
            system("CLS");
            menu(s);
        }
        else{
            return;
        }
        break;
        case 4:
        system("CLS");
        s->isEmpty();
        cout<<"\n1.Back to menu  0. Exit\n\n";
        cin>>Op;
        if(Op==1)
        {
            system("CLS");
            menu(s);
        }
        else{
            return;
        }
        break;
        case 5:
        system("CLS");
        s->peek();
        cout<<"\n1.Back to menu  0. Exit\n\n";
        cin>>Op;
        if(Op==1)
        {
            system("CLS");
            menu(s);
        }
        else{
            return;
        }
        break;
        case 6:
        default:
        system("CLS");
        cout<<"\n\ntry again\n\n";
        menu(s);

    }
}
int main() {
    Stack *s=new Stack();
    //  s->push(10);
    //  s->push(20);
    //  s->push(30);
    //  s->display(); // Output: 10 20 30

    // s.peek(); // Output: 30

    // s.pop();
    // s.display(); // Output: 10 20
   menu(s);

    return 0;
}