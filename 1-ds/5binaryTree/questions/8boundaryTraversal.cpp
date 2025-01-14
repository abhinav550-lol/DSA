#include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\binaryTree\1theory\0import.cpp"

void traverseLeft(Node* root, vector<int> &res){
    if(root == NULL || root -> right == NULL && root -> left == NULL){
        return ;
    }
    res.push_back(root-> data);
    if(root->left)
    traverseLeft(root->left,res);
    else
    traverseLeft(root->right,res); 

}

void traverseLeafNodes(Node* root,vector<int> &res){
    if(root == NULL) return ;

    if(root-> right == NULL && root -> left == NULL){
        res.push_back(root->data);
    }

    traverseLeafNodes(root -> left , res);
    traverseLeafNodes(root -> right, res);
}

void traverseRight(Node* root, vector<int> &res){
    if(root == NULL || root -> right == NULL && root -> left == NULL)return ;


    if(root -> right){
        traverseRight(root -> right,res);
    }else{
        traverseRight(root -> left,res);
    }
    res.push_back(root ->data);
}


vector<int> boundaryTraversal(Node* root){
    vector<int> res;
    if(root == NULL)
        return res;

    res.push_back(root-> data);
    
    traverseLeft(root -> left,res);

            traverseLeafNodes(root->left, res);
        //right subtree
        traverseLeafNodes(root->right, res);

    traverseRight(root -> right,res);

    return res;
}


//5 5 1 3 2 -1 -1 -1 -1 -1 -1

int main(){
Node* root = NULL;
buildTreeFromLevelOrder(root);
vector<int> v = boundaryTraversal(root);
for(int i : v){
    cout<< i << ' ';
}
  return 0;
}
