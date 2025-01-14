#include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\binaryTree\1theory\0import.cpp"

pair<int , int > solve(Node* root){
    if(root == NULL) return make_pair(0,0);

    pair<int ,int> left = solve(root -> left);
    pair<int ,int> right = solve(root -> right);

    pair<int ,int> res;
    res.first = root -> data +left.second + right.second;
    res.second = max(left.first,left.second) + max(right.first,right.second);

    return res; 
}

int maxSumOfNonAdjNodes(Node* root){
    if(root == NULL) return 0;
    pair<int ,int> p = solve(root);
    return max(p.first,p.second);
}

//5 4 1 3 2 -1 -1 -1 -1 -1 -1

int main(){
Node* root = NULL;
buildTreeFromLevelOrder(root,1 , 4);
int v = maxSumOfNonAdjNodes(root);
cout << v;
  return 0;
}

