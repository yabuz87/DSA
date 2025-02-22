#inlcude <iostream>
using namespace std;

struct node{
    node* next;
    int data;

};
node* head=nullptr;
void insertFirst(node* head,int a)
{
    node* newNode=new node;
    newNode->data=a;
    if(head==nullptr)
    {
        head=newNode;
        head->next=nullptr;
    }
    else{
        newNode->next=head;
        head=newNode;
        return;
    }
}
void insertLast(node* head,int a)
{
     node* newNode=new node;
      newNode->data=a;
     node* current=head;
    if(head==nullptr)
    {
        head=newNode;
        head->next=nullptr;
    }
    while(current->next!=nullptr)
    {
        current=current->next;
    }
    current->next=newNode;

}
void insertAtAny(node* head,int a, int pos)
{
    node* newNode=new node;
     newNode->data=a;
     int counter=1;
     if(pos==1)
     {
        insertFirst(head,a);
     }
      node* current=head;
     while(counter>pos-1 &&current!=nullptr)
     {
        current=current->next;
        counter++;
     }
     if(current==nullptr)
     {
        cout<<"out of bound\n";
     }
     else{
     node* temp=current;
     temp->next=newNode;
     newNode->next=current->next;
     current->next=nullptr;

     }
}
void deleteFirst()
{
    if(head==nullptr)
    {
        cout<<"empty list\n";
    }
    else{
        node* temp=head;
        head=head->next;
        delete temp;
    }
}
bool search(int a)
{
    node* current=head;
    while(current!=nullptr)
    {
        if(current->data==a)
        {
            return true;
        }
        current=current->next;
    }
           return false;
}
void deleteAtAny(int pos)
{
    int counter=1;
    node* current=head;
    node* temp;
    if(head=nullptr)
    {
        cout<<"empty list\n";
    }
    else if(pos==1)
    {
        deleteFirst();

    }
    else{
     
      while(counter<pos-1 && current->next!=nullptr)
      {
        current=current->next;
        counter++;
      }

      if(current->next==nullptr || counter !=pos-1)
      {
        cout<<"out of bound\n";
      }
      else{
        temp=current->next;
        current->next=temp->next;
        delete temp;
      }

      }
}

void deleteLast()
{
     node* temp;
     node* current=head;
    if(head==nullptr)
    {
        cout<<"empty List\n";
    }
    else if(head->next=nullptr)
    {
        head=temp;
        head=nullptr;
        delete temp;
    }
    else{
       
        
        while(current->next->next!nullptr)
        {
            current=current->next;
        }
       temp=current->next;
       current->next=nullptr;
       delete temp;
    }
}