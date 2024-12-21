#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
    node* prev;
};

struct Deque {
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

    void dequeueRear() {
        if (rear == nullptr) {
            cout << "queue is empty\n";
            return;
        } else {
            node* temp = rear;
            rear = rear->prev;
            if (rear != nullptr) {
                rear->next = nullptr;
            } else {
                front = nullptr;  
            }
            delete temp;
        }
    }

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
    Deque q;
    q.enqueueFront(3);
    q.enqueueFront(-3);
    q.enqueueRear(0);
    q.enqueueFront(4);
    q.enqueueRear(8);
    q.display();
    q.dequeueFront();
    cout << "After dequeue from front:\n";
    q.display();
    q.dequeueRear();
    cout << "After dequeue from rear:\n";
    q.display();
    return 0;
}
