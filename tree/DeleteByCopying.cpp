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

void DeleteBST(Node *RNP, Node *PDNP, int x)
{
    Node *DNP; // a pointer that points to the currently deleted node
    if (RNP == NULL) {
        cout << "Data not found\n";
    } else if (RNP->Num > x) {
        DeleteBST(RNP->Left, RNP, x);  // delete the element in the left subtree
    } else if (RNP->Num < x) {
        DeleteBST(RNP->Right, RNP, x); // delete the element in the right subtree
    } else {
        DNP = RNP;
        if ((DNP->Left == NULL) && (DNP->Right == NULL)) {
            if (PDNP->Left == DNP)
                PDNP->Left = NULL;
            else
                PDNP->Right = NULL;
            delete DNP;
        } else if (DNP->Left != NULL && DNP->Right == NULL) {
            if (PDNP->Left == DNP)
                PDNP->Left = DNP->Left;
            else
                PDNP->Right = DNP->Left;
            delete DNP;
        } else if (DNP->Right != NULL && DNP->Left == NULL) {
            if (PDNP->Left == DNP)
                PDNP->Left = DNP->Right;
            else
                PDNP->Right = DNP->Right;
            delete DNP;
        } else {
            Node* maxNodeParent = DNP;
            Node* maxNode = DNP->Left;
            while (maxNode->Right != NULL) {
                maxNodeParent = maxNode;
                maxNode = maxNode->Right;
            }
            DNP->Num = maxNode->Num; // copy the value from maxNode to DNP
            if (maxNodeParent->Right == maxNode)
                maxNodeParent->Right = maxNode->Left;
            else
                maxNodeParent->Left = maxNode->Left;
            delete maxNode;
        }
    }
}
