#include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\6binarySearchTree\1theory\0import.cpp"

void inOrderTraversal(Node* root, vector<int> &in){
    if(root == NULL) return ;

    if(root -> left ) inOrderTraversal(root -> left,in);
    in.push_back(root -> data);
    if(root -> right ) inOrderTraversal(root -> right,in);
 }

int kthLargest(Node* root, int k){
    vector<int> in;
    inOrderTraversal(root , in);
    if(k < 1 || k > in.size()){
        return -1;
    }else{
        return in[in.size() - k ];
    }
}

int main()
{
    Node *root = NULL;
    buildBST(root);
    return 0;
}

