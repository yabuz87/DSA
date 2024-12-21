#include <iostream>
using namespace std;
void simpleSort(int num[],int n)
{
    for(int i=0;i<n;i++)
    {
        int index=i;
        for(int j=i+1;j<n;j++)
        {
            if(num[index]>num[j])
            {
                int temp=num[j];
                num[j]=num[index];
                num[index]=temp;
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

int num[]={1,6,0,-2,4};
int n=sizeof(num)/sizeof(num[0]);
simpleSort(num,n);
display(num,n);

}