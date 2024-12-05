#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
    node* prev;
};

struct priorityQueue {
    node* front = nullptr;
    node* rear = nullptr;

    void enqueueFront(int val) {
        node* newNode = new node();
        newNode->data = val;
        newNode->next = nullptr;
        newNode->prev = nullptr;

        if (front == nullptr && rear == nullptr) {  
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }

int peak()
{
    if(front==nullptr)
    {
        cout<<"empty\n";
        return -1;
    }
    else {
        return front->data;
    }
}
    void enqueueRear(int val) {
        node* newNode = new node();  
        newNode->data = val;
        newNode->next = nullptr;
        newNode->prev = nullptr;

        if (front == nullptr && rear == nullptr) {  
            front = rear = newNode;
        } else {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeueFront() {
        if (front == nullptr) {
            cout << "queue is empty\n";
            return;
        } else {
            node* temp = front;
            front = front->next;
            if (front != nullptr) {
                front->prev = nullptr;
            } else {
                rear = nullptr;  
            }
            delete temp;
        }
    }


void add(int val)
{
    if(peak()>val)
    {
        enqueueFront(val);
    }
    else if(peak()<val)
    {
            enqueueRear(val);
    }
    else{
        enqueueFront(val);
       }
}
void poll()
{
    dequeueFront();
}
    // void dequeueRear() {
    //     if (rear == nullptr) {
    //         cout << "queue is empty\n";
    //         return;
    //     } else {
    //         node* temp = rear;
    //         rear = rear->prev;
    //         if (rear != nullptr) {
    //             rear->next = nullptr;
    //         } else {
    //             front = nullptr;  
    //         }
    //         delete temp;
    //     }
    // }

    void display() {
        if (front != nullptr) {
            node* current = front;
            cout << "<-";
            while (current != nullptr) {  
                cout << current->data << "<-";
                current = current->next;
            }
            cout << "nullptr\n";
        } else {
            cout << "queue is empty\n";
        }
    }
};

int main() {
    priorityQueue q;
    q.add(3);
    q.add(-3);
    q.add(0);
    q.add(4);
    q.add(8);
    q.display();
    cout << "After dequeue from front:\n";
    q.display();
    q.poll();
    cout << "After dequeue from rear:\n";
    q.display();
    return 0;
}
