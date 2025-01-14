#include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\6binarySearchTree\1theory\0import.cpp"

void inOrderTraversal(Node* root, int i; int ans,int k){
    if(root == NULL) return ;

    if(root -> left ) inOrderTraversal(root -> left);
    i++; if(i == k) ans = root -> data;
    if(root -> right ) inOrderTraversal(root -> right);
 }

int kthSmallest(Node* root, int k){
    int ans;
    inOrderTraversal(root,0,ans,k);
    return ans;    
}

int main()
{
    Node *root = NULL;
    buildBST(root);
    return 0;
}

