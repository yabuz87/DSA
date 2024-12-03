#include <iostream>
using namespace std;

void  display(int num[],int n)
        {
            for(int i=0;i<n;i++)
               { cout<<num[i]<<" ";}
                cout<<endl;
        }
void insertionSort(int num[],int n)
{
    for(int i=1;i<n;i++)
    {
        int key = num[i];
        int j=i-1;
        while(j>=0&& num[j]>key)
        {
            num[j+1]=num[j];
            j--;
        }
        num[j+1]=key;
        display(num,n);
      
    }
}

void binaryInsertionSort(int num[],int n)
{
    for(int i=1;i<n;i++)
    {
            int current=num[i];
            int j=i-1;
            int high=j;
            int low=0;
            while(low<=high)
            {
                int mid=(low+high)/2;
                if(num[mid]<current)
                {
                    high=mid-1;
                }
                else if(num[mid]>current)
                {
                        low=mid+1;
                }
                    
            }   
             }
}


int main()
{
        int num[]={2,6,-2,6,7};
        int n=sizeof(num)/sizeof(num[0]);
        insertionSort(num,n);
}