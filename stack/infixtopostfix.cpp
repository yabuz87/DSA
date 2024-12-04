#include<iostream>
#include<vector>
using namespace std;

struct stack{
    vector<string> ch[10];
    int pointer=0;
    
    void push(string val)
{
    if(pointer>=0 || pointer<=10)
    {
        ch.push_back(val);
        return
    }
    else if(pointer>9){
        cout<<"Stack over flow"<<endl;
        return;
    }
    else {
        cout<<"stack under flow"<<endl;
        return;
    }
}
string pop()
{
    if(pointer>=0)
    {
        
        return ch[--pointer];
    }
    else if(pointer<0)
    {
        cout<<"stack is empty"<<endl;
        return "-1";
    }
}
void display()
{
    int i=ch.length;
    for(i=ch.length();i>=0;i++)
    {
            cout<<ch[i]<<" ";
    }
}
void postToInfix(string str)
{
    int i = 0, n = str.length();
    stack s;
    while (i < n) {
        if(str[i]!='-' || str[i]!='+' || str[i]!='/'|| str[i]!='*')
        {
            push(str[i]);
            i++;
        }
        else{
            // string a=pop();
            // string b=pop();
            string  c="("+pop()+"str[i]"+pop()+")";
            push(c);
        }
}
}
};



int main()
{
    stack s;
    string str = "AB*CD-+F/";
    s.postToInfix(str);
    s.display();
}