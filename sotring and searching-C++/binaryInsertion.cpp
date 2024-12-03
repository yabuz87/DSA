#include <iostream>
using namespace std;

int binary(int num[],int n,int target)
{
    int low=0;
    int high=n-1;
    int mid;
    while(low<=high)
    {
        if(num[mid]<target)
        {
            high=mid-1;
        }
        else if(num[mid]>target)
        {
            low=mid+1;
        }
        else if(num[mid]==target)
        {
            return mid;
        }

    }
     return low;

}
void binaryInsertion(int num[],int n)
{
    for(int i=1;i<n;i++)
    {
            int current=num[i];
            int j=i-1;
            int pos=binary(num,n,current);
            while(j>=pos)
            {
                num[j+1]=num[j];
                j=j-1;
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
    binaryInsertion(num,5);
    display(num,5);
}