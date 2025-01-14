#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
class Node {
    public:
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
}


int countNodes(Node* root){
        if(root == NULL) return 0;
        int ans = 1+ countNodes(root -> left) + countNodes(root -> right);
        return ans;
    }
    
    bool isCBT( Node* root , int i , int totalNodes){
        if(root == NULL) return true;
        
        if(i >= totalNodes) return false;
        else{
            bool leftAns = isCBT(root -> left , 2*i +1 , totalNodes);
            bool rightAns = isCBT(root -> right , 2*i +2 , totalNodes);
            return leftAns && rightAns;
        }
    }
    
    bool isMaxOrder( Node* root){
        if(root == NULL) return true;
        
        if(root -> left == NULL && root -> right ==NULL){
            return true;
        }else if(root -> right == NULL){
            return root -> left -> data <= root -> data && isMaxOrder(root -> left);
        }else{
                bool leftAns = isMaxOrder(root -> left);
                bool rightAns = isMaxOrder(root -> right);
            return (root -> left -> data <= root -> data ) &&
                    (root -> right -> data <= root -> data) && leftAns && rightAns;
        }

     }
    bool isHeap( Node* root) {
        int index = 0;
        int totalNodes = countNodes(root);
        if(isCBT(root,index,totalNodes) && isMaxOrder(root)){
            return true;
        }
        return false;
    }



int main(){
   
  return 0;
}