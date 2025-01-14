#include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\6binarySearchTree\1theory\0import.cpp"

    bool isBST(Node *root, int min, int max)
    {
        if (root == NULL)
            return true;

        bool left, right;
        if (root->data >= min && root->data <= max)
        {
            left = isBST(root->left, min, root->data);
            right = isBST(root->right, root->data, max);
        }else{
            return false;
        }
        if (left && right)
            return true;
        else
            return false;
    }

    bool validateBST(Node *root)
    {
        return isBST(root, INT_MIN, INT_MAX);
    }

int main()
{
    Node *root = NULL;
    buildBST(root);
    return 0;
}

// 1st App
//  void inOrderTraversalBST(Node* root, vector<int> &in){
//      if(root == NULL ) return ;

//     if(root -> left ) inOrderTraversalBST(root -> left,in);
//     in.push_back(root->data);
//     if(root -> right) inOrderTraversalBST(root->right,in);
// }

// bool validateBST(Node* root) {
//     vector<int> in;
//     inOrderTraversalBST(root , in);

//     int size = in.size();
//     for(int i = 1;i< size;i++){
//         if(in[i] <= in[i-1]) return false;
//     }
//     return true;
// }
