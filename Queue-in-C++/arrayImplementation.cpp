#include<iostream>
using namespace std;
struct queue{
    int front=-1;
    int rear=-1;
    int num[20];
   void enqueue(int val)
   {
        if(rear==19)
        {
           cout<<"over flow";
           return;
        }
        else if(front=-1 &&rear==-1)
        {
            front=rear=0;
            num[rear]=val;
            return;
        }
        else{
            rear++;
            num[rear]=val;
        }
        
   }
  int  dequeue()
    {
            if(front==-1&& front==-1)
            {
                cout<<"underflow\n";
                return -1;
            }
            else if(front==rear)
            {
               int temp=num[front];
                front=rear=-1;
                return temp;
            }
            else{
                return num[front++];
            }
    }
    void display()
    {
        if(front==-1)
        {
            cout<<"queue is empty\n";
        }
        else{

            for(int i=front;i<rear+1;i++)
            {
               
                cout<<num[i]<<"<-";
            }
        }
    }
    int peak()
    {
        if(front==-1)
        {
            cout<<"queue is empty\n";
            return -1;
        }
        else {
            return num[front];
        }
    }
};

int main()
{
    queue q;
    q.enqueue(3);
    q.enqueue(0);
    q.enqueue(4);
    q.enqueue(8);
    q.display();
    int n=q.dequeue();
    cout<<"\n"<<n<<endl;
    q.display();
    return 0;
}