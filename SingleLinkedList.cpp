#include <iostream>
using namespace std;
struct LinkedList{
    int data;
    LinkedList *next;
    // LinkedList *prev;
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
        // head->prev=nullptr;
    }
    else {
        newNode->next=head;
        // head->prev=newNode;
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
}
else{
    while(current->next!=nullptr)
    {
        current=current->next;
    }
    current->next=newNode;
}

 }


 void insertAt(LinkedList *&head,int position,int val)
 {

    LinkedList *newNode=new LinkedList();
    newNode->data=val;
    int pos=1;

    if(head==nullptr)
    {
        head=newNode;
        newNode->next=nullptr;
        return;
    }

 if(position==1)
    {
        newNode->next=head;
        head=newNode;
       return;
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
        cout<<"out of bound\n\n";
        return;
    }
    if(current->next==nullptr)
    {
            current->next=newNode;
    }


   else {
    LinkedList *temp=current;
   
    newNode->next=current->next;
    temp->next=newNode;
   }
   }
 }
void deleteFirst(LinkedList *&head) {
    if (head == nullptr) {
        cout << "The list is empty" << endl;
    } else {
        LinkedList *temp = head;
        head = head->next;
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
    if(head->next==nullptr)
    {
        delete head;
        cout<<"now the list is empty";
        head=nullptr;
    }
    else
    {
        LinkedList *current=head;
        while(current->next->next!=nullptr)
        {
            current=current->next;
        }
        LinkedList *temp=current->next;
        current->next=nullptr;
        delete temp;
    }
}
void deleteAt(LinkedList *&head, int position) {
    if (head == nullptr) {
        cout << "The list is empty" << endl;
        return;
    }

    if (position == 1) {
        LinkedList *temp = head;
        head = head->next;
        delete temp;
    } else {
        int pos = 1;
        LinkedList *current = head;
        while (pos < position - 1 && current != nullptr) {
            current = current->next;
            pos++;
        }

        if (current == nullptr || current->next == nullptr) {
            cout << "Position is out of bound" << endl;
            return;
        }

        LinkedList *temp = current->next;
        // temp->next->prev = current;
        current->next = temp->next;

        delete temp;
    }
}

void reverseDisplayList(LinkedList *&head)
   { 
    {
        if(head==nullptr)
            return;

        reverseDisplayList(head->next);

        cout<<" "<<head->data<<" ";


    }
}

bool search(LinkedList *head,int target)
{
    LinkedList *current=head;
    while(current!=nullptr)
    {
        if(current->data==target)
        {return true;}
        current=current->next;
    }
    return false;
}
void menu(LinkedList *&head);
void insertMenu(LinkedList *&head);
void deleteMenu(LinkedList *&head);
void insertMenu(LinkedList *&head) {
    cout << "\t\t\t INSERTION\t\t\t\n\n";
    cout << "1. Insert At the Beginning\n\n";
    cout << "2. Insert At the End\n\n";
    cout << "3. Insert at Any Position\n\n";
    cout << "0. Back to Menu\n\n";

    int option;
    int val,Op;
    int pos;
    cin >> option;

    switch(option) {
        case 1:
            cout << "Enter Value\n";
            cin >> val;
            insertFirst(head, val);
            display(head);
            cout<<"0.Exit\n\n1.Back to menu\n\n";
            cin>>Op;
            if(Op==1)
            {
                system("CLS");
                insertMenu(head);
            }
            else
            {
                return;
            }
            break;
        case 2:
            cout << "Enter Value\n";
            cin >> val;
            insertLast(head, val);
            display(head);
            cout<<"0.Exit\n\n1.Back to menu\n\n";
            cin>>Op;
            if(Op==1)
            {
                system("CLS");
                insertMenu(head);
            }
            else {
                return;
            }

            break;
        case 3:
            cout << "Enter Value\n";
            cin >> val;
            cout << "Enter Position\n";
            cin >> pos;
            insertAt(head, pos, val);
            display(head);
            cin>>Op;
            cout<<"\n\n0.Exit\n\n1.Back to menu\n\n";

            if(Op==1)
            {
                system("CLS");
                insertMenu(head);
            }
            else
            {
                return;
            }
            break;
        case 0:
            system("CLS");
            menu(head);
        default:
            system("CLS");
            cout << "Invalid option. Please try again." << endl;
            insertMenu(head);
            break;
    }
}
void deleteMenu(LinkedList *&head){
    cout << "\t\t DELETION\t\t\n\n";
    cout << "1. Delete At the Beginning\n\n";
    cout << "2. Delete At the End\n\n";
    cout << "3. Delete At Any Position\n\n";
    cout << "0. Back to Menu\n";

    int option, pos,Op;
    cin >> option;

    switch(option) {
        case 1:
            system("CLS");
            deleteFirst(head);
            display(head);
            cout<<"\n\n0.Exit\t\t1.Back to menu\n\n";
            cin>>Op;
            if(Op==1)
            {
                system("CLS");
                deleteMenu(head);
            }
            break;
        case 2:
            system("CLS");
            deleteLast(head);
            display(head);
            cout<<"\n\n0.Exit\n\n1.Back to menu\n\n";
            cin>>Op;
            if(Op==1)
            {
                system("CLS");
                deleteMenu(head);
            }
            break;
        case 3:
            cout << "Enter position: ";
            cin >> pos;
            system("CLS");
            deleteAt(head, pos);
            display(head);
            
            cout<<"\n\n0.Exit\n\n1.Back to menu\n\n";
            cin>>Op;
            if(Op==1)
            {
                system("CLS");
                deleteMenu(head);
            }
            else 
            return;
            break;
        case 0:
            system("CLS");
            menu(head);
            break;
        default:
            cout <<"Invalid option.Please try again." << endl;
            display(head);
            deleteMenu(head);
            cout<<"\n\n0.Exit\n\n1.Back to menu\n\n";
            cin>>Op;
            if(Op==1)
            {
                system("CLS");
                deleteMenu(head);
            }
            else 
            return;
    }
}
void menu(LinkedList *&head)
{
    cout<<"This is a menu for doubly LinkedList\n\n 1.inserting\n\n 2.Delete\n\n 3.Searching\n\n4.Reverse List\n\n";
    int option,Op;
    cin>>option;
    switch(option)
    {
         case 1:
             system("CLS");
         insertMenu(head);
         break;
        case 2:
           system("CLS");
         deleteMenu(head);
         break;
        case 3:
        cout<<"Enter the number you wanna check\n";
        int target;
        cin>>target;
        system("CLS");
        cout<<search(head,target);
        cout<<"\n\n0.Exit\n\n1.Back to menu\n\n";
            cin>>Op;
            if(Op==1)
            {
                system("CLS");
                deleteMenu(head);
            }
            else 
            return;
        break;
        case 4:
        system("CLS");
        reverseDisplayList(head);
        cout<<"\n\n0.Exit\n\n1.Back to menu\n\n";
            cin>>Op;
            if(Op==1)
            {
                system("CLS");
                deleteMenu(head);
            }
            else 
            return;
        break;

    }
}

int main()
{
    LinkedList *head;
    head=nullptr;
      menu(head);
    return 0;
}
