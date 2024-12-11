#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};
struct queue{
    node* front=nullptr;
    node* rear=nullptr;
    
    void enqueue(int val)
    {
        node* newNode = new node;
        newNode->data=val;
        if(front==NULL && rear==NULL)
        {
            
            rear=newNode;
            front=rear;
        }
        else{    
            rear->next=newNode;
            rear=newNode;
        }
    }
    void dequeue()
    {
        if(front!=nullptr)
        {
                node *temp=front;
                front=front->next;
                delete temp;
        }

    }
    void display()
    {
        node* current;
        current=front;
        if(front!=nullptr)
        {
            while(current!=rear)
            {
                cout<<"<--"<<current->data<<"<-- ";
                current=current->next;
            }
            cout<<"<--"<<current->data<<"<-- ";
        }
        else{
            cout<<"Queue is empty"<<endl;
        }
    }
    int peak()
    {
        if (front==nullptr)
        {
            cout<<"empty queue\n";
            return -1;
        }
        else 
        {
            return front->data;
        }
    }
};

int main()
{

  queue q;
  q.enqueue(10);
  q.enqueue(12);
  q.enqueue(14);
  q.enqueue(16);
  q.display();
   cout<<"\n";
  q.dequeue();
  q.display();
  cout<<"\n"<<q.peak();
}