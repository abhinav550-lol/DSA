#include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\6binarySearchTree\1theory\0import.cpp"

void inOrderTraversal(Node* root, vector<int> &in){
    if(root == NULL) return ;

    if(root -> left) inOrderTraversal(root -> left, in);
    in.push_back(root -> data);
    if(root -> right) inOrderTraversal(root -> right, in);
}


Node* inorderToBalancedBST(vector<int> in, int s, int e){
    if(s > e) return NULL;
    int mid = (s+e)/2;
    Node* root = new Node(in[mid]);
    root -> left = inorderToBalancedBST(in,s,mid-1);
    root -> right = inorderToBalancedBST(in,mid+1,e);
    return root;
}

Node* balancedBst(Node* root){
    vector<int> in;
    inOrderTraversal(root, in);

    return inorderToBalancedBST(in, 0, in.size() -1);
}

int main()
{
    Node *root = NULL;
    buildBST(root);
    Node* rootOfBalanced = balancedBst(root);
    return 0;
}
