#include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\6binarySearchTree\1theory\0import.cpp"

void inOrderTraversal(Node* root, vector<int> &in){
    if(root == NULL ) return ;

    if(root -> left ) inOrderTraversal(root->left,in);
    in.push_back(root -> data);
    if(root -> right ) inOrderTraversal(root->right,in);

}

bool twoSumInBST(Node* root, int target) {
    vector<int> in;
    inOrderTraversal(root , in);
    int i = 0;
    int j = in.size() - 1;
    while(i<j){
        int sum = in[i] + in[j];
        if(sum == target)
            return true;
        else if(sum > target)
            j--;
        else{
            i++;
        }
    }
    return false;
}


int main()
{
    Node *root = NULL;
    buildBST(root);
    cout << twoSumInBST(root , 20);
    return 0;
}
