#include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\6binarySearchTree\1theory\0import.cpp"

void inorderSuccesor(Node* root, Node* & succ, int key){
 if(root == NULL) return;

    Node* curr = root;
    while(curr -> data != key){
        if(curr -> data < key){
            succ = curr;
            curr = curr -> right;
        }else{
            curr = curr -> left;
        }
    }

    Node* rightTree = curr -> right;
    while(rightTree != NULL){
        succ = rightTree;
        rightTree = rightTree -> left;
    }
}

int main(){
    Node* root = NULL;
    buildBST(root);
    levelOrderTraversal(root);
    Node* succ = NULL;
    inorderSuccesor(root , succ , 12);
    cout << succ -> data << endl;
  return 0;
}