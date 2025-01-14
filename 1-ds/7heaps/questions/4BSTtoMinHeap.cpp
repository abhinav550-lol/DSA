#include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\6binarySearchTree\1theory\0import.cpp"
// given that the bst is a complete binary tree
 
 void inorderTraversal(Node* root , vector<int> &in){
    if(root == NULL) return;

    if(root -> left) inorderTraversal(root -> left,in);
    in.push_back(root -> data);
    if(root -> right) inorderTraversal(root -> right,in);
 }

void populatePreorderly(Node* root , vector<int> &in , int &index){
    if(root == NULL || index >= in.size()) return ;
    root-> data = in[index++];
    populatePreorderly(root -> left, in , index);
    populatePreorderly(root -> right , in , index);
}

void BST_TO_MINHEAP(Node* root){
    vector<int> in;
    inorderTraversal(root , in);
    int index = 0;
    populatePreorderly(root , in , index);
}

int main(){
    Node* root = NULL;
    buildBST(root);
    levelOrderTraversal(root);
    BST_TO_MINHEAP(root); cout << endl;
    levelOrderTraversal(root);
    return 0;
}