//#include <iostream>
//using namespace std;
// struct stack{
//     int length;
//     int num[length];
//     int pointer=0;
//     void push(int num[],int val)
//     {
//         if(pointer==lenth-1)
//         {
//             cout<<"Stack overFlow\n\n";
//         }
//         else{
//             num[pointer]=val;
//             pointer++;
//             }
//     }
//     void pop(int num[])
//     {
//         if(present==0){
//             cout<<"stack under Flow ";
//         }
//         num[pointer]=num[pointer-1];
//         pointer--;
        
//     }
//     void peek(int num[])
//     {
//         cout<<num[pointer];
//     }

// }
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
            for (int i = 0; i < pointer; i++) {
                cout << num[i] << " ";
            }
            cout << endl;
        }
    }
};
//use the concept to  do palindrome
// decimal to binary
//infix postfix
//postfix evaluator
//decimal to binary and palindrome should be linkedList based.
// gotchaaaaaaa

int menu(stack s)
{
    cout << "\t\t<<<<<<<Stack Menu>>>>>>>\n\n";
    cout<<"1.push\n\n2.pop\n\n3.peek\n\n4.isEmpty\n\n5.Size\n\n";
    int option;
    cin>>option;
    switch(option)
    {
        case 1:
        s.push(s);
        break;
        case 2:
        s.pop(s);
        case 3:

    }
}
int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display(); // Output: 10 20 30

    s.peek(); // Output: 30

    s.pop();
    s.display(); // Output: 10 20

    return 0;
}

int main()
{
    stack s=new stack(0); 
    menu(s);
}