#include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\binaryTree\1theory\0import.cpp"

 // o(n) soln

 pair<int,int> solveDiameter(Node* root){
    if(root == NULL ) return make_pair(0,0);

    pair<int,int> left = solveDiameter(root->left);
    pair<int,int> right = solveDiameter(root->right);

    int leftDiameter = left.first;
    int rightDiameter = right.first;
    int diameterThruRoot = left.second + right.second + 1;

    pair<int , int > ans ;
    ans.first = max(leftDiameter,max(rightDiameter,diameterThruRoot));
    ans.second = max(left.second , right.second) + 1;

    return ans;
 }

 int diameterOfATree(Node* root){
    return solveDiameter(root).first;
 }

int main(){
   Node* root = NULL;
  buildTreeFromLevelOrder(root);
  cout<<diameterOFATree(root);
  return 0;
}



// int heightOfTheTree(Node* root){
//   if(root == NULL) return 0;

//   int leftHeight = heightOfTheTree(root -> left);
//   int rightHeight = heightOfTheTree(root -> right);

//   return max(leftHeight , rightHeight ) +1 ;
// }


// // O(N^2) complexity 
// int diameterOfATree(Node* root){
//     if(root == NULL ){ return 0 ;}
//     int maxLeftDia = diameterOfAtree(root->left);
//     int maxRightDia = diameterOfATree(root->right);
//     int maxNodeDia = heightOfTheTree(root->left) + 1 + heightOfTheTree(root->right);

//     int result = max(maxLeftDia, maxRightDia , maxNodeDia);

//     return result;
// }