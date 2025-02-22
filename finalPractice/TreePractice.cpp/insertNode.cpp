#include <iostream>
using namespace std;

struct node {
    node* left;
    node* right;
    int data;

    node(int val) {
        left = nullptr;
        right = nullptr;
        data = val;
    }
};

void insert(int val, node*& root) {
    node* newNode = new node(val);
    if (root == nullptr) {
        root = newNode;
    } else {
        node* current = root;
        node* temp = nullptr;
        while (current != nullptr) {
            temp = current;
            if (current->data > val) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        if (temp->data > val) {
            temp->left = newNode;
        } else {
            temp->right = newNode;
        }
    }
}
void insert(node* root,int a)
{
    node* newNode = new node(a);
    if(root==nullptr)
    {
        root=newNode;   
    }
    else if(root->data>a && root->left==nullptr)
    {
        root->left=newNode;
    }
    else if(root->data<a && root->right==nullptr)
    {
        root->right=newNode;
    }
    else if(root->data>a)
    {
        insert(root->left,a);
    }
    else{
        insert(root->right,a);
    }
}
bool search(node* root,int a)
{
    if(root->data==a)
    {
        return true;
    }
    else if(root==null)
    {
        return false;
    }
    else if(root->data>a)
    {
        search(root->left,a);
    }
    else if(root->data<a)
    {
        search(root->right,a);
    }
}
node* search(node* root, int a)
{
    if(root==null || root->data==a)
    {
        return root;
    }
    else if(root->data>a)
    {
        search(root->left,a)
    }
    else{
        search(root->right,a);
    }
}

int findMin(node* root)
{
    int min;
    if(root==nullptr)
    {
        return min;
    }
    else{
        min=root->data;
        findMin(root->left);
    }

    
}
void preOrder(node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(node* root)
{
    if(root==nullptr)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
void postOrder(node* root)
{
    if(root==nullptr)
    {
        return ;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
    
}

node* root = nullptr;

int main() {
    insert(10, root);
    insert(6, root);
    insert(15, root);
    insert(14, root);
    insert(18, root);
    insert(19, root);
    insert(16, root);
    insert(17, root);
    insert(12, root);
    insert(13, root);
    insert(11, root);
    insert(4, root);
    insert(8, root);
    insert(7, root);
    cout<<"\n";
    preOrder(root);
    cout<<"\n";
    inOrder(root);
    cout<<"\n";
    postOrder(root);

    return 0;
}
