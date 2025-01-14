#include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\6binarySearchTree\1theory\0import.cpp"

class Info{
    public:
    int size;
    bool isBST;
    int max;
    int min;
};

Info solve(Node* root , int &maxSize){
    if(root == NULL) return {0,true,INT_MIN,INT_MAX};

    Info leftSubTree = solve(root -> left, maxSize);
    Info rightSubTree = solve(root -> right, maxSize);

    Info curr;
    curr.size = leftSubTree.size + 1 + rightSubTree.size;
    curr.max = max(root -> data , rightSubTree.max);
    curr.min = min(root -> data , leftSubTree.min);

    if(leftSubTree.isBST && rightSubTree.isBST && (leftSubTree.max < root -> data && rightSubTree.min > root -> data))
        curr.isBST = true;
    else
        curr.isBST = false;
    
    if(curr.isBST) maxSize = max(maxSize , curr.size);
    return curr;
}


int largestBST(Node* root){
    if(root == NULL) return 0;
    int maxSize = 0;
    Info a = solve(root, maxSize);
    return maxSize;
}



int main()
{
    Node * root  = NULL;
    buildBST(root);

    return 0;
 }