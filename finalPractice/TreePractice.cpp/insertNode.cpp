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
