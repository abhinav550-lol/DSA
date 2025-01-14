#include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\binaryTree\1theory\0import.cpp"
void inOrderTraversal(Node* root){
    if(root == NULL){
        return ;
    }

    inOrderTraversal(root->left);

    cout<<root->data<<' ';

    inOrderTraversal(root->right);
}

void preOrderTraversal(Node* root){
    if(root == NULL){
        return ;
    }

    cout<<root->data<<' ';

    preOrderTraversal(root->left);

    preOrderTraversal(root->right);
}
void postOrderTraversal(Node* root){
    if(root == NULL){
        return ;
    }

    postOrderTraversal(root->left);

    postOrderTraversal(root->right);

    cout<<root->data<<' ';
}

//  5 1 3 -1 -1 2 -1 -1 1 5 -1 -1 -1
int main(){
    Node *root = NULL;
    root = buildTree(root);
    inOrderTraversal(root);
    cout<<endl;
    preOrderTraversal(root);
    cout<<endl;
    postOrderTraversal(root);
    return 0;
}