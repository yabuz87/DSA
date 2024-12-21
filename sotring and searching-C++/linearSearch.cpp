#include <iostream>
using namespace std;


int linearSearch(int arr[],int n, int key)
{
    int count=0;
    for(int i:arr)
    {
        if(i==key)
        {

            return count;
        }
       else count++;
    }
    return -1;
}




int main()
{
        int num[]={1,3,5,6,8};
        int key=5;
        cout<<linearSearch(num,5,key);

    return -1;
}