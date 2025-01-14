#include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\binaryTree\1theory\0import.cpp"

Node* lca(Node *root, int n1 ,int n2){
    if(root == NULL) return NULL;

    if(root -> data == n1 || root -> data == n2 ) return root;

    Node* rightAns = lca( root -> right , n1 ,n2 );
    Node* leftAns = lca( root -> left , n1 , n2);

    if(rightAns!= NULL && leftAns != NULL)
        return root ;
    else if(rightAns != NULL && leftAns == NULL)
        return rightAns;
    else if(rightAns == NULL && leftAns != NULL)
        return leftAns;
        else
        return nullptr;    
}

//5 4 1 3 2 -1 -1 -1 -1 -1 -1

int main(){
Node* root = NULL;
buildTreeFromLevelOrder(root,1 , 4);
int v = lca(root);
cout << v;
  return 0;
}
