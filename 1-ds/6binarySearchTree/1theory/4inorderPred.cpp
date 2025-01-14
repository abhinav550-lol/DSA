#include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\6binarySearchTree\1theory\0import.cpp"

void inorderPredecessor(Node* root, Node* &pre,int key){
    if(root == NULL) return;

    Node* curr = root;
    while(curr -> data != key){
        if(curr -> data > key){
            curr = curr -> left;
        }else{
            pre = curr;
            curr = curr -> right;
        }
    }

    Node* leftTree = curr -> left;
    while(leftTree != NULL){
        pre = leftTree;
        leftTree = leftTree -> right;
    }
}

int main(){
    Node* root = NULL;
    buildBST(root);
    levelOrderTraversal(root);
    Node* pre = NULL;
    inorderPredecessor(root , pre , 7);

    if(pre)
    cout << pre -> data << endl;
    else
    cout << "No Pred";

  return 0;
}