#include<iostream>
using namespace std;
void selectionSort(int num[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int index=i;
        for(int j=i+1;j<n;j++)
        {
            if(num[index]>num[j])
            {
                    index=j;
            }
        }
        int temp=num[i];
        num[i]=num[index];
        num[index]=temp;
    }
}
void display(int num[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<num[i]<<" ";
    }
}

int main()
{


int num[]={5,2,9,1,0};
int n=sizeof(num)/sizeof(num[0]);
selectionSort(num,n);
display(num,n);
}