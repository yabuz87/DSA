void DeleteBST(Node* &RNP, int x) {
    if (RNP == NULL) {
        cout << "Data not found\n";
        return;
    }

    if (x < RNP->Num) {
        DeleteBST(RNP->Left, x);  // delete the element in the left subtree
    } else if (x > RNP->Num) {
        DeleteBST(RNP->Right, x); // delete the element in the right subtree
    } else {
        Node* DNP = RNP;
        if (RNP->Left == NULL) {
            RNP = RNP->Right; // replace RNP with its right child
        } else if (RNP->Right == NULL) {
            RNP = RNP->Left;  // replace RNP with its left child
        } else {
            // Find the minimum node in the right subtree
            Node* MinNode = RNP->Right;
            while (MinNode->Left != NULL) {
                MinNode = MinNode->Left;
            }
            // Merge the right subtree with the left subtree
            MinNode->Left = RNP->Left;
            RNP = RNP->Right; // replace RNP with its right child
        }
        delete DNP; // delete the node
    }
}
