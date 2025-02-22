#include <iostream>
using namespace std;

struct Sorting{

    void bubbleSort(int num[],int n)
    {
        if(n==1)
        {
            return;
        }
        else 
        {
            for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<n-1-i;j++)
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

    void display(int num[],int n)
    {
        for(int i=0;i<n;i++)
        {
            cout<<num[i]<<" ";
        }
    }


   void insertionSort(int num[],int n)
    {     
        for(int i=1;i<n;i++)
        {
            int current=num[i];
            int j=i-1;
            while(j>=0 && num[j]>current)
            {
                num[j+1]=num[j];
                j--;   
            }
            num[j+1]=current;

        }
    }


    
};

int main() {
    int num[] = {1, 4, -5, 0, 3};
    int n = sizeof(num) / sizeof(num[0]);
        Sorting s;
        // s.display(num,n);
        cout<<endl;
        // s.selectionSort(num, n);

    s.display(num,n);

    cout<<"this is how insertion works\n";
    s.insertionSort(num,n);

    return 0;
}