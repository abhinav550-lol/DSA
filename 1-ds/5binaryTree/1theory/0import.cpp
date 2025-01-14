#include <iostream>
#include <bits/stdc++.h>
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

void buildTreeFromLevelOrder(Node* &root){
    cout<<"Enter data for root:"<<endl;
    int data;
    cin>>data;
    queue<Node*> q;
    root = new Node(data);
    q.push(root);
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        
        cout << "Enter the left node data for "<<curr->data<<":"<<endl;
        int leftData;
        cin>>leftData;

        Node* leftNode = NULL;
        if(leftData != -1){
            leftNode = new Node(leftData);
            q.push(leftNode);
        } 
        curr -> left = leftNode;


        cout << "Enter the right node data for "<<curr->data<<":"<<endl;
        int rightData;
        cin>>rightData;
        Node* rightNode = NULL;
        if(rightData != -1){
        rightNode = new Node(rightData);
        q.push(rightNode);
        }
        curr -> right = rightNode;
    }
}