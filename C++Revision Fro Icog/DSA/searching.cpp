#include <iostream>
using namespace std;

struct Searching
{

void linearSearch(int num[],int n,int target)
{
    for(int i=0;i<n;i++)
    {
        if(num[i]==target)
        {
            cout<<"the element is found at"<<i<<endl;
            return;
        }
    }
    cout<<"element not found\n";
    return;
}
void selectionSort(int num[],int n)
{
    if(n<=1)
    {
        return;
    }
    else 
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
            int temp=num[index];
            num[index]=num[i];
            num[i]=temp;
        }
    }
}

int binarySearch(int num[],int n, int target)
{
    selectionSort(num,n);
    int low=0;
    int high=n-1;
    while(low<high)
    {
        int mid= (low+high)/2;
        if(num[mid]>target)
        {
            high=mid-1;
        }
        else if(num[mid]<target)
        {
            low=mid+1;
        }
         else if(target==num[mid])
        {
            return mid;
        }
        else
        {
            return low;
        }
    }
    return -1;
}
};

int main()
{
    int num[]={1,4,0,7,-4,9};
    int n=sizeof(num)/sizeof(num[0]);
    Searching s;
    int answer=s.binarySearch(num,n,4);
    cout<<answer;
    return 0;
}