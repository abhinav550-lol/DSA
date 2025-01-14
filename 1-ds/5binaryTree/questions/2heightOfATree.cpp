#include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\binaryTree\1theory\0import.cpp"
#include<bits/stdc++.h>
 
int heightOfTheTree(Node* root){
  if(root == NULL) return 0;

  int leftHeight = heightOfTheTree(root -> left);
  int rightHeight = heightOfTheTree(root -> right);

  return max(leftHeight , rightHeight ) +1 ;
}

int main(){
   Node* root = NULL;
  buildTreeFromLevelOrder(root);
  cout<<heightOfTheTree(root);
  return 0;
}