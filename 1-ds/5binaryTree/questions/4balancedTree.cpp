#include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\binaryTree\1theory\0import.cpp"


    pair<bool ,int> solveBalancedTree(Node* root){
    if(root == NULL) return make_pair(true,0);

    pair<bool ,int> left = SolvebalancedTree(root->left);
    pair<bool ,int> right= SolvebalancedTree(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;
    bool diff = abs (left.second - right.second) <= 1;

    pair<bool, int> res;
    res.second = max(left.second , right.second) + 1;
    
    if(leftAns && rightAns && diff){
        res.first = true;
    }else{
        res.second = false;
    }
    return res;
}

bool balancedTree(Node* root){
    return solveBalancedTree(root).first;
}

int main(){
   Node* root = NULL;
  buildTreeFromLevelOrder(root);

  return 0;
}

