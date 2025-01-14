#include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\6binarySearchTree\1theory\0import.cpp"

Node* solve(vector<int> &preorder, int min , int max , int &index){
    if(index >= preorder.size() || preorder[index] > max || preorder[index] < min) return NULL;

    Node* root = new Node(preorder[index++]);
    root -> left = solve(preorder, min, root -> data, index);
    root -> right = solve(preorder, root -> data, max, index);

    return root;
}

Node* preorderToBST(vector<int> &preorder) {
    int index = 0;
    return solve(preorder, INT_MIN,INT_MAX , index);
}

int main()
{
    Node *root = NULL;
    vector<int> preorder = {20, 10, 5, 15, 13, 35, 30, 42};
    root = preorderToBST(preorder);
    levelOrderTraversal(root);
    return 0;
}
