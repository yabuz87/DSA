#include <iostream>
using namespace std;
struct LinkedList{
    int data;
    LinkedList *next;
    LinkedList *prev;
};

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

if(head==nullptr)
{
    head=newNode;
    head->prev=nullptr;
}
else{
    while(current->next!=nullptr)
    {
        current=current->next;
    }
    current->next=newNode;
    newNode->prev=current;
}

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
void deleteFirst(LinkedList *&head) {
    if (head == nullptr) {
        cout << "The list is empty" << endl;
    } else {
        LinkedList *temp = head;
        head = head->next;
        head->prev = nullptr;

        delete temp;
    }
}
void deleteLast(LinkedList *&head)
{
    if(head==nullptr)
    {
        cout<<"the list is empty";
        return;
    }
    else 
    {
        Linked
    }
    
}


int main()
{
    LinkedList *head;
    head=nullptr;
    insertFirst(head,30);
    insertFirst(head,20);
    insertFirst(head,40);
    insertLast(head,76);
    insertLast(head,6);
    // insertAt(head,44,6);
    // deleteFirst(head);
    display(head);
    return 0;
}
