#include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\binaryTree\1theory\0import.cpp"

void morrisTraversal(Node* root){
    Node* curr = root ;
    while(curr != NULL){
        if(curr -> left == NULL){
            cout<< curr -> data << ' ';
            curr = curr -> right;
        }else{
            Node* prev = curr -> left;
            while(prev -> right && prev -> right != curr){
                prev = prev -> right;
            }
           if(prev -> right == NULL){
            prev -> right = curr;
            curr = curr -> left;
           }else{
            prev->right = NULL;
            cout << curr -> data << ' ';
            curr = curr -> right;
           } 
        }
    }
}

int main(){

Node* root = NULL;
buildTreeFromLevelOrder(root);
morrisTraversal(root);
  return 0;
}





