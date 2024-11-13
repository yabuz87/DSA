#include <iostream>
using namespace std;
struct LinkedList{
    int data;
    LinkedList *next;
    LinkedList *prev;
};
 LinkedList *head=nullptr;

 void display(LinkedList *head)
 {
    cout<<"[";
    while(head!=nullptr)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<"]";
 }
 void insertFirst(LinkedList *&head, int value)
 {
    LinkedList *newNode=new LinkedList();
    newNode->data=value;

    if(head==nullptr)
    {
        head=newNode;
        head->prev=nullptr;
    }
    else {
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
    }
 }
 void insertLast(LinkedList *&head, int val)
 {
    
    LinkedList *newNode=new LinkedList();
    newNode->data=val;
    LinkedList *current=head;
   
    while(current->next!=nullptr)
    {
        current=current->next;
    }
    current->next=newNode;
    newNode->prev=current;

 }

 
 void insertAt(LinkedList *&head,int val,int position)
 {
   
    LinkedList *newNode=new LinkedList();
    newNode->data=val;
    int pos=1;
    

 if(position==1)
    {
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
        head->prev=nullptr;

    }
   else{ 

        LinkedList *current=head;
    while(pos<position-1 && current!=nullptr)
    {
        current=current->next;
        pos++;
    }
    if(current==nullptr)
    {
        cout<<"out of bound";
        return;
    }
    if(current->next==nullptr)
    {
            current->next=newNode;
            newNode->prev=current;
            newNode->next=nullptr;
    }
     
   
   else {
    LinkedList *temp=current;
    newNode->next=current->next;
    current->next->prev=newNode;
    temp->next=newNode;
    newNode->prev=temp;
   }
   }
 }

int main()
{
    head=new LinkedList();
    LinkedList *second=new LinkedList();
    LinkedList *third=new LinkedList();
    head->data=40;
    head->prev=nullptr; 
    head->next=second; 
    second->data=50;
    second->prev=head;
    second->next=third;
     third->data=60;
    third->prev=second;
    third->next=nullptr;
     insertFirst(head,30);
    insertLast(head,89);
    insertAt(head,44,7);
    display(head);
    return 0;
}
