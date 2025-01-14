#include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\binaryTree\1theory\0import.cpp"

void flattenTree(Node* root){
    Node* curr = root;
    while(curr != NULL){
        if(curr -> left){
            Node* prev = curr -> left;

            while(prev -> right)
                prev = prev -> right;

            prev -> right = curr -> right;
            curr -> right = curr -> left;
            curr -> left = NULL;
        }
        curr = curr -> right;
    }
}


int main(){

Node* root = NULL;
buildTreeFromLevelOrder(root);
Node* listNode = flattenTree(root);
while(listNode){
    cout << listNode -> data << ' ';
    listNode = listNode -> right;
}
  return 0;
}
