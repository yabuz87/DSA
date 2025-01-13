#include <iostream>
using namespace std;
struct stack{
    int num[30];
    int pointer=-1;
    void push(int val)
    {
        if(pointer<29)
        {
            num[++pointer]=val;

        }
        else{
            cout<<"stack overflow\n";
        }
    }
   bool isEmpty()
   {
    return (pointer<0); 
   }
    int pop()
    {
        if(isEmpty())
        {
            cout<<"stack under flow\n";
            return -1;
        }
        else{
            return num[pointer--];
        }

    }
    void decimalToBinary(int n)
    {
        int digit;
        while(n>1)
        {
            digit=n%2;
            push(digit);
            n=n/2;
        }
        push(n);
        while(!isEmpty())
        {
            cout<<pop();
        }
    }
};

int main()
{
    int np=19;
    stack * s=new stack;
    s->decimalToBinary(np);
}