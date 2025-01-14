#include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\6binarySearchTree\1theory\0import.cpp"

void inOrderTraversal(Node* root, vector<Node*> &sortedLL){
    if(root == NULL ) return ;

    if(root -> left ) inOrderTraversal(root->left , sortedLL);
    sortedLL.push_back(root);
    if(root -> right ) inOrderTraversal(root->right , sortedLL);
}

Node* flatten(Node* root){
    if(root == NULL) return NULL;
    vector<Node*> sortedLL;
    inOrderTraversal(root,sortedLL);

    Node* head = sortedLL[i];
    int lastIndex = sortedLL.size() - 1;


    for(int i= 0 ; i < lastIndex ; i++ ){
        Node* curr = sortedLL[i];
        curr -> right = sortedLL[i + 1];
        curr -> left = NULL;
    }

    sortedLL[lastIndex]->left = NULL;
    sortedLL[lastIndex]->right = NULL;
     
    return head;
}

int main()
{
    Node *root = NULL;
    buildBST(root);
    Node* head = flatten(root);
    return 0;
}
