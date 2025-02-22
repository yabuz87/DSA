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


//another way to insert
void insert2(int val) {
    node* newNode = new node();
    newNode->data = val;
    newNode->left = nullptr;
    newNode->right = nullptr;
    int flag = 0;
    if(root==nullptr)
    {
        root=newNode;
        cout<<val<<" has added successfully\n";
    }
    else{
        node *temp=root;
        while(flag==0)
        {
            if(val >temp->data)
            {
                if(temp->right==nullptr)
                {
                    temp->right=newNode;
                    cout<<val<<" has added successfully\n";
                    flag=1;
                }
                else
                {
                    temp=temp->right;
                }
            }
            else{
                if(temp->left==nullptr)
                {
                    temp->left=newNode;
                    cout<<val<<" has added successfully\n";
                    flag=1;
                }
                else
                {
                    temp=temp->left;
                }
            }
        }
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
void preOrderTraversal(node* root)
{
    if(root==nullptr)
    return;
    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    
    preOrderTraversal(root->right);
}
void inOrderTraversal(node* root)
{
    if(root==nullptr)
    {
        return;
    }
    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
    cout<<" "<<root->data<<" ";
}
void post_order_traversal(node* root)
{
    if(root==nullptr)
    {
        return;
    }
    post_order_traversal(root->left);
    post_order_traversal(root->right);
    cout<<root->data<<" ";
}

int main()
{
    
    insert(5);
    insert(2);
    insert(8);
    insert(6);
    insert(3);
    insert(-7);
    // pre_order_traverse();
    // cout<<"\n this one is in recursion\n";
    
    // preOrderTraversal(root);
    cout<<"\n in-order-traversal\n";
    inOrderTraversal(root);
    // cout<<"\n post order traversal\n";
    // post_order_traversal(root);
}