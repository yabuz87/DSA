#include <iostream>
using namespace std;

struct queue {
    int n;
    int* num;
    int rear = -1;
    int front = -1;

    queue(int size) {
        n = size;
        num = new int[size];
    }

    ~queue() {
        delete[] num;
    }

    void enqueue(int val) {
        if (rear >= n - 1) {
            cout << "queue overflow\n";
        } else {
            if (front == -1) {
                front = 0;
            }
            rear++;
            num[rear] = val;
        }
    }

    int dequeue() {
        if (front == -1) {
            cout << "queue underflow \n";
            return -1;
        } else {
            return num[front++];
        }
    }

    bool isEmpty() {
        return (rear == -1);
    }

    void display() {
        if (front == -1) {
            cout << "queue is empty\n";
        } else {
            for (int i = front; i <= rear; i++) {
                cout << num[i] << " ";
            }
            cout << endl;
        }
    }
};


struct circularQueue
{
        int* num;
        int n;
        int front=-1;
        int rear=-1;
        circularQueue(int size)
        {
                n=size;
                num=new int[size];

        }
        ~circularQueue()
        {
            delete[] num;
        }
        void enqueue(int val)
        {
                if((rear+1)%n==front)
                {
                            cout<<"queue over flow \n";
                }
                else if(rear==-1 && front==-1)
                {
                    rear=0=front=0;
                    num[rear]=val;
                }
                else{
                    rear=(rear+1)%n;
                    num[rear]=val;
                }
        }
        int dequeue()
        {
            if(rear==front)
            {
                int temp=num[front];
                front=rear=-1;
                return temp;
            }

        }
};

int main() {
    queue q(5);
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);
    q.enqueue(20);
    q.dequeue();
    q.dequeue();
    q.display();
}
