#include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\6binarySearchTree\1theory\0import.cpp"

int maxOfTree(Node* root){
    Node* curr = root;
    while(curr->right != NULL) curr = curr -> right; 
    return curr -> data;
}

int minOfTree(Node* root){
    Node* curr = root;
    while(curr -> left!= NULL) curr = curr -> left;   
    return curr->data;
}

int main(){
    Node* root = NULL;
    buildBST(root);
    cout << maxOfTree(root);
    cout << minOfTree(root);
    return 0;
}