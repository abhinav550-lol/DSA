#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
class Node{
    public:
    int data;
    Node* right;
    Node* left;
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node* buildTree(Node* root){
    cout<<"Enter data: "<<endl;
    int data;
    cin>>data;
    root = new Node(data);

    if(data == -1) return NULL;

    cout<<"Enter data for left node of: " <<data<<endl;  
    root->left = buildTree(root->left);

    cout<<"Enter data for right node of: " <<data<<endl;  
    root->right = buildTree(root->right);
   return root; 
}   

int main(){
Node* root = NULL;
 root = buildTree(root);   
  return 0;
}