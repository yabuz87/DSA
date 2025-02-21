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
    node* newnode = new node();
    newnode->data = val;
    newnode->left = nullptr;
    newnode->right = nullptr;

    if (root==nullptr)
    {
        root=newnode;
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
        parent->left = newnode;
        cout<<val<<" has added successfully\n";
        return;
    } else {
        parent->right = newnode;
        cout<<val<<" has added successfully\n";
    }
}

void DeleteBST(node* &RNP, int x) {
    if (RNP == nullptr) {
        cout << "Data not found\n";
        return;
    }

    if (x < RNP->data) {
        DeleteBST(RNP->left, x);  // delete the element in the left subtree
    } else if (x > RNP->data) {
        DeleteBST(RNP->right, x); // delete the element in the right subtree
    } else {
        node* DNP = RNP;
        if (RNP->left == nullptr) {
            RNP = RNP->right; // replace RNP with its right child
        } else if (RNP->right == nullptr) {
            RNP = RNP->left;  // replace RNP with its left child
        } else {
            // Find the minimum node in the right subtree
            node* Minnode = RNP->right;
            while (Minnode->left != nullptr) {
                Minnode = Minnode->left;
            }
            // Merge the right subtree with the left subtree
            Minnode->left = RNP->left;
            RNP = RNP->right; // replace RNP with its right child
        }
        delete DNP; // delete the node
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
int main()
{
    insert(10);
    insert(12);
    insert(14);
    insert(9);
    insert(6);
    insert(0);
    preOrderTraversal(root);
    cout<<"\n";
    DeleteBST(root,9);
    preOrderTraversal(root);


    
}