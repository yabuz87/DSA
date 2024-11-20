#include <iostream>
using namespace;

struct LinkedList{
    LinkedList *next;
    int data;
    void push(int val)
    {
        if(head==nullptr)
        {
            head=newNode;
            
        }
        LinkedList newNode=new LinkedList();
        newNode->data=val;
        head=newNode;

    }
};

Struct Stack{
    
}
