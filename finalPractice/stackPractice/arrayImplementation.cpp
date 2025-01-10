#include <iostream>
using namespace std;
struct Stack{
    int size;
    int pointer=-1;
    int* arr;
    Stack(int s)
    {
        size=s;
     arr=new int[s];
     for(int i=0;i<size;i++)
     {
        arr[i]=0;
     }
    }
   
    void push(int val)
    {
        if(pointer<size-1)
       { 
        pointer++;
        arr[pointer]=val;
    
        }
        else 
        {
            cout<<"stack over flow \n";
        }
    }
    int pop()
    { 
        if(pointer==-1)
        {
            cout<<"stack underflow\n";
        }
        int temp=arr[pointer];
        pointer--;
        return temp;
    }
    int peek()
    {
        return arr[pointer]; 
    }
    void display()
    {
        
            for(int i=0;i<=pointer;i++)
            {
                cout<<arr[i]<<" ";
            }
    }
    bool isEmpty()
    {
        if(pointer!=-1)
        {
            return false;
        }
        else{
            return true;
        }
    }
    bool isFull()
    {
        if(pointer==size-2)
        {
            return true;
        }
        else {
            return false;
        }
    }
     ~Stack()
    {

            delete[] arr;  
    }
    



};

int main()
{
    Stack s(6);
    s.push(4);
    s.push(5);
    cout<<"\n"<<s.isFull()<<"\n";
   s.display();

   cout<<"\n"<<s.peek();


}