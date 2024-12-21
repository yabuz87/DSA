#include <iostream>
using namespace std;
void display(int num[],int n)
{
    cout<<"[";
    for(int i=0;i<n;i++)
    {

        cout<<num[i]<<" ";
    }
    cout<<"]";
}

void insertAt(int nums[],int n,int posi,int number)
{
    for(int i=n-1;i>posi-1;i--)
   {
    nums[i]=nums[i-1];
   }
   posi--;
   nums[posi]=number;

}
void insertEnd(int nums[],int n,int number)
{
    nums[n-1]=number;
}
void insertFirst(int nums[],int n,int number)
{
    for(int i=n-1;i>0;i--)
    {
        nums[i]=nums[i-1];
    }
        nums[0]=number;
}
void DeleteAt(int nums[],int n,int posi)
{
   //nums[posi]=0;
   int i;
   for(i=posi-1;i<n-1;i++)
   {
    nums[i]=nums[i+1];
   }
   nums[i]=0;
}
void deletefirst(int nums[],int n)
{
    //[2,3,4,5,6,8,0]
    int i;

    for(i=0;i<n-1;i++)
    {
        nums[i]=nums[i+1];
    }

   // nums[i]=0;
}
void menu(int arr[],int n)
    {
 cout<<"\t\t menu\n\n1.InsertAtAnypos\n\n2.DeleteAtAny\n\n3.insertAtBeginning\n\n4.insertAtEnd\n\n5.deleteAtFirst\n\n";
 int option;
 int val;

 cin>>option;
int pos;
int subOption;
 switch(option)
 {
 case 1:


        cout<<"Enter the position\n";
        cin>>pos;
        if(pos>n)
        {
            cout<<"array out of bound";
            cout<<"\n1.back\n0.exit";
            cin>>subOption;
        if(subOption==0)
            return;
        if(subOption==1)
            system("ClS");
            menu(arr,n);
            break;
        }
        cout<<"enter Value\n";
        cin>>val;
        system("CLS");
        insertAt(arr,n,pos,val);
        display(arr,n);
        cout<<"\n1.back\n0.exit";
        cin>>subOption;
        if(subOption==0)
            return;
        if(subOption==1)
            system("ClS");
            menu(arr,n);
        break;
 case 2:
    cout<<"Enter the index\n";
    cin>>pos;
    DeleteAt(arr,n,pos);
    display(arr,n-2);
    cout<<"\n1.back\n0.exit";
        cin>>subOption;
        if(subOption==0)
            return;
        if(subOption==1)
            system("ClS");
            menu(arr,n);
    break;
 case 3:
     cout<<"Enter the value\n";
     cin>>val;
     insertFirst(arr,n,val);
      display(arr,n);
     cout<<"\n1.back\n0.exit";
        cin>>subOption;
        if(subOption==0)
            return;
        if(subOption==1)
            system("ClS");
            menu(arr,n);
     break;
 case 4:

    cout<<"Enter the value\n";
    cin>>val;
    insertEnd(arr,n,val);
    display(arr,n);
    cout<<"\n1.back\n0.exit";
        cin>>subOption;
        if(subOption==0)
            return;
        if(subOption==1)
            system("ClS");
            menu(arr,n);
            break;
 case 5:
     deletefirst(arr,n);
     display(arr,n-2);
     cout<<"\n1.back\n0.exit";
        cin>>subOption;
        if(subOption==0)
            return;
        if(subOption==1)
            system("ClS");
            menu(arr,n);
            break;


 }
    }
void deleteEnd(int nums[],int n)
{
    nums[n-2]=nums[n-1];
}

int main()
{
    cout << "enter the number of element\n";
    int n;
    cin >> n;

    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    system("CLs");
    display(arr,n);
    n++;
    arr[n-1]=0;
    menu(arr,n);

    return 0;
}
