#include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\6binarySearchTree\1theory\0import.cpp"

Node* LCAinaBST(Node* root , Node* P, Node* Q){
    Node* curr = root;
    while(curr != NULL){
        if(curr -> data  > P-> data && curr -> data > Q-> data ){
            curr = curr -> left;
        }
        else if(curr -> data  < P-> data && curr -> data < Q-> data ){
            curr = curr -> right;
        }
        else{
            return curr;
        }
    }
    return NULL;
}

int main()
{
    Node *root = NULL;
    buildBST(root);
    Node* ans = LCA(root, root -> right , root -> left);
    cout << ans -> data;
    return 0;
}
