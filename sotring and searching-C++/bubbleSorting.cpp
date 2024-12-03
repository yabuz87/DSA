#include <iostream>
using namespace std;
void bubbleSort(int num[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(num[j]>num[j+1])
            {
                int temp=num[j];
                num[j]=num[j+1];
                num[j+1]=temp;
            }
        }
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
    int num[]={1,4,8,-2,5};
    bubbleSort(num,5);
    display(num,5);
}