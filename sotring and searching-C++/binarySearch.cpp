#include <iostream>
using namespace std;

int bsearch(int num[],int n,int key)
{

    int high=n-1;
    int low=0;
    int middle;
    while (low<=high)
    {
        middle=(high+low)/2;
        if(num[middle]<key)
        {
            low=middle+1;
        }
        else if(num[middle]>key)
        {
            high=middle-1;

        }
       else if(num[middle]==key)
        {
            return middle;
         }

    }
    return -1;
}




int main()
{

    int num[]={1,3,4,7,9,10};
    int np=bsearch(num,6,10);
    cout<<np;
    return -1;
}