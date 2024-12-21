#include <iostream>
#include <stack>
using namespace std;

struct node{
    int data;
    node *right;
    node *left;
};

node* root = nullptr;

void insert(int val) {
    node* newNode = new node();
    newNode->data = val;
    newNode->left = nullptr;
    newNode->right = nullptr;

    if (root==nullptr)
    {
        root=newNode;
        cout<<val<<" has added successfully\n";
        return;
    }

    node *temp=root;
    node *parent = nullptr;

    while (temp != nullptr) {
        parent = temp;
        if (val < temp->data) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }

    if (val < parent->data) {
        parent->left = newNode;
        cout<<val<<" has added successfully\n";
        return;
    } else {
        parent->right = newNode;
        cout<<val<<" has added successfully\n";
    }
}
void pre_order_traverse() {
    if (root == nullptr) {
        return;
    }

    stack<node*> nodeStack;
    nodeStack.push(root);

    while (!nodeStack.empty()) {
        node* current = nodeStack.top();
        cout << " " << current->data;
        nodeStack.pop();
        if (current->right) {
            nodeStack.push(current->right);
        }
        if (current->left) {
            nodeStack.push(current->left);
        }
    }
}

int main()
{
    
    insert(5);
    insert(2);
    insert(5);
    insert(6);
    insert(-7);
    pre_order_traverse();
}