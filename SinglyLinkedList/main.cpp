#include <iostream>
using namespace std;

struct SLL {
    int data;
    SLL *next;
};

SLL *head = nullptr;

// void displayList(SLL *head);
// void insertFirst(SLL *&head,int a);
// void insertLast(SLL *&head,int a);
// int length(SLL *head);
// void insertAt(SLL *&head,int a,int pos);




void displayList(SLL *head)
    {

            if(head==nullptr)
            {
               cout<<"the list is Empty";
                return;

            }
            SLL *current=head;
            cout<<"[";
            while(current!=nullptr)
            {
                cout<<current->data<<" ";

                current=current->next;
            }
            cout<<"]";
    }
    void insertFirst(SLL *&head,int a)
    {
        SLL *current=new SLL;
        current->data=a;

        if(head==nullptr)
          {
             head=current;
             current->next=nullptr;
             return;
          }
          else
          {


              current->next=head;
              head=current;
              return;
          }

    }
    //void deleteFirst()
    void insertLast(SLL *&head,int a)
    {
        SLL *newNode=new SLL;
        newNode->data=a;
       // newNode->next=nullptr;

       if(head==nullptr)
       {
           head=newNode;
       }
       else if(head->next==nullptr)
        {
            head->next=newNode;
            return;

        }

            SLL *current=head;

            while(current->next!=nullptr)
            {
                current=current->next;

            }
           current->next=newNode;

    }
    int length(SLL *head)
    {
        int counter=1;
        while(head!=nullptr)
        {
            head=head->next;
            counter++;
        }
        return counter;
    }
    // void reverseDisplayList(LLS *&head)
    // {
    //     if(head==nullptr)
    //         return;

    //     reverseDisplayList(head->next);

    //     cout<<" "<<head->data<<" ";


    // }
    void insertAt(SLL *&head,int a,int pos)
    {


               SLL* newNode=new SLL;
                 newNode->data=a;
                SLL* current=head;
               int count=1;
                if (pos == 1){ // Inserting at the head
                    newNode->next = head;
                    head = newNode;
                    return;
                            }

               while(count<pos-1&& current!=nullptr)
               {
                  current=current->next;
                  count++;
               }
               if(current==nullptr)
               {
                   cout<<"out of bound";
                   return;
               }
               SLL* temp=current;
              newNode->next=current->next;
               current->next=nullptr;
               temp->next=newNode;

    }
        SLL* reverseList(SLL *&head)
        {
            SLL *first;
            if(head==nullptr || head->next==nullptr)
                return head;
            first=reverseList(head->next);
            head->next->next=head;
            head->next=nullptr;

            return first;

        }

void DeleteFirst(SLL *&head)
{

    SLL *temp;
     temp=head;
    if(head==nullptr)
    {
        cout<<"the list is empty";
        return;
    }
    else
    {
        head=head->next;
        delete temp;

    }

}
bool search(int a,SLL* head)
{

    while(head->next!=nullptr)
    {
        if(head->data==a);
        return true;
        head=head->next;
    }
    return false;
}
// void manu()
// {
//     cout<<"this one is singly Linked List\n\n1.Display List\n\n2.Length of List\n\n3.DeleteFirst\n\n4.DeleteLast";
       // int option;
       // cin>>option;
      /*  switch(option)
        {
            case 1: display()
        }*/
// }



int main() {
    SLL *first= new SLL;
    SLL *second=new SLL;
    SLL *third=new SLL;
    SLL *fourth=new SLL;
    first->data = 50;
    second->data=60;
    third->data=70;
    fourth->data=80;



    head =first;
    first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=nullptr; // Initialize 'start' to point to 'p'


   // insertFirst(head,30);
    //insertAt(head,55,2);
     //displayList(head);
     cout<<"\n\n";
    //DeleteFirst(head);
    //displayList(head);
mht5uhh
    //cout<<"\n the reversed  form of the above linked list is \n";
   // displayList(reverseList(head));
    //
    //displayList(head);
//    reverseDisplayList(head);

    return 0; // Return 0 for a successful program termination
}

