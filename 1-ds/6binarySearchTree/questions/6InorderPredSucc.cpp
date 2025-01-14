#include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\6binarySearchTree\1theory\0import.cpp"

pair<int, int> predecessorSuccessor(Node *root, int key){
    int pred = -1;
    int succ = -1;
    Node* curr = root;
    while(curr -> data != key && curr != NULL){
        if(curr -> data > key){
            succ = curr -> data;
            curr = curr -> left;
        }else{
            pred = curr -> data;
            curr = curr -> right;
        }
    }

    Node* rightTree = curr -> right;
    while(rightTree != NULL){
        pred = rightTree -> data;
        rightTree = rightTree -> left;
    }

    Node* leftTree = curr -> left;
    while(leftTree !=NULL){
        succ = leftTree -> data;
        leftTree = leftTree -> right;
    }

    return make_pair(pred, succ); 
}  

int main()
{
    Node *root = NULL;
    buildBST(root);
    
    return 0;
}

