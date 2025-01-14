#include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\binaryTree\1theory\0import.cpp"

pair<bool,int> solveSumTree(Node* root){
    if(root == NULL) return make_pair(true,0);
    if(root -> right == NULL && root -> left == NULL ) return make_pair(true,root -> data);
    int curr = root -> data;
    pair<bool,int> right = solveSumTree(root->right);
    pair<bool,int> left = solveSumTree(root->left);

    bool rightAns = right.first;
    bool leftAns = left.first;
    bool condt = curr == right.second + left.second;

    pair<bool,int> res;
    if(rightAns && leftAns && condt){
        res.first = true;
        res.second = 2*curr; 
    }else{
        res.first = false;
    }
    return res;
}


bool sumTree(Node* root){
    return solveSumTree(root).first;
}

int main(){
    
    return 0;
}





bool sumTree(Node *root){
    if(root == NULL || root -> left == NULL && root -> right == NULL  ){
        return true;
    }
    int rightData = root -> right -> data;
    int leftData = root -> left -> data;
    
    bool check1= sumTree(root -> right);
    bool check2= sumTree(root -> left);

    if(rightData + leftData == root -> data && check1 && check2){
        return true;
    }else{
        return false;
    }
}