#include<iostream>
using namespace std;
void selectionSort(int num[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int index=i;
        for(int j=i+1;j<n;j++)
        {
            if(num[index]<num[j])
            {
                    index=j;
            }
        }
        int temp=num[i];
        num[i]=num[index];
        num[index]=temp;
    }
}
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

    void add(int val)
    {
        enqueue(val);
        int no=(rear-front)+1;
        selectionSort(num,no);
        
    }
    void poll()
    {
        dequeue();
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
    q.add(-3);
    q.add(3);
    q.add(0);
    q.add(4);
    q.add(8);
    // q.poll();
    // q.display();
    // int n=q.();
    // cout<<"\n"<<n<<endl;
    q.display();
    return 0;
}









