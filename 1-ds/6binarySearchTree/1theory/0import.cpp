#include <iostream>
#include<bits/stdc++.h>
using namespace std;



 class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int x):data(x){
        this -> left = NULL;
        this -> right = NULL;
    }
 };

Node* insertNode(Node* root,int data){
    if(root == NULL){
        root = new Node(data);
        return root; 
    }
    if(data > root->data){
        root ->right = insertNode(root -> right,data);
    }else{
        root -> left = insertNode(root -> left,data);
    }
    return root;
}

 void buildBST(Node* &root){
    int data;
    cout << "Enter a root:"<<endl;
    cin>>data;

    while(data != -1){
        root = insertNode(root , data);
        cout << "Enter the element:" << endl;
        cin >> data;
    }
 }

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << ' ';
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
}   

