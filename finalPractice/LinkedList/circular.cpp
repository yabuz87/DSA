#include<iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};
node* head;
 void insertFirst(int a)
 {
    node* newNode=new node;
    newNode->data=a;
    if(head==nullptr)
    {
        head->next=newNode;
        newNode->next=head;
    }
    else{
        node* current=head;
        while(current->next!=head)
        {
            current=current->next;
        }
        
        current->next=newNode;
        newNode->next=head;
        head=newNode;
    }
 }

 void insertLast(int a)
 {
     node* newNode=new node;
    newNode->data=a;
    if(head==nullptr)
    {
        head->next=newNode;
        newNode->next=head;
    }
    else {
        node* current=head;
        while(current->next!=head;)
        {
            current=current->next;
        }
        current->next=newNode;
        newNode->next=head;        
    }
 }
 void insertAt(int a,int pos)
 {
    node* newNode=new node;
    int counter=1;
    newNode->data=a;
    if(pos==1)
    {
        insertFirst(a);
    }
    else
    {
        node* current=head;
        while(counter<pos-1 && current->next!=head)
        {
                current=current->next;
                counter++;
        }
        node* temp=current;
        current->next=newNode;
        newNode->next=temp->next;

    }
 }
 void display()
 {
    if(head==nullptr)
    {
        cout<<"list is empty\n";
    }
        else{
            node* current=head;
            cout<<current->data<<" ";

            while(current->next!=head)
            {
                cout<<current->data<<" ";
                current=current->next; 
            }
        }
    }
 
 void deleteFirst()
 {
    if(head==nullptr)
    {
        cout<<"empty List\n";
        return;
    }
    else
    {
        node* temp=head;
        node* current=head;
        while(current->next!=head)
        {
            current=current->next;
        }
        head=head->next;
        current->next=head;
        delete temp;

    }
 }
 void deleteLast()
 {
    if(head==nullptr)
    {
        cout<<"empty list\n";
        return;
    }
    else{
        node* current=head;
        while(current->next->next!=head)
        {
            current=current->next;
        }
        node* temp=current->next;
        current->next=head;
        delete temp;
        
        
    }
 }