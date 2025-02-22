#include <iostream>
using namespace std;

int main()
{
    int num=9;
    int *ptr1=&num;
    cout<<ptr<<endl;
    cout<<*ptr1;
    int num2=0;
    int *ptr2=&num2;
    ptr1=ptr2;
    cout<<ptr2<<endl;
    cout<<*ptr2;
}