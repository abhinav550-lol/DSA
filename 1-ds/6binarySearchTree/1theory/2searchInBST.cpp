
bool searchInBST(BinaryTreeNode<int> *root, int x) {
    // Write your code here.
    if(root == NULL ) return false;

    bool ans;
    if(x == root -> data){
        ans = true;
    }else if(x > root -> data){
        ans = searchInBST(root -> right,  x);
    }else{
        ans = searchInBST(root -> left , x);
    }
    return ans;
}


// o(1)
bool searchInBST(BinaryTreeNode<int> *root, int x) {
    // Write your code here.
    BinaryTreeNode<int> *curr = root;
    while(curr != NULL){
        if(curr->data == x) return true;

        if(curr -> data > x) 
        curr = curr -> left;
        else
         curr = curr -> right;
    }
    return false;
}