#include "1-ds/5binaryTree/1theory/0import.cpp"

void ReverseLevelOrderTraversal(Node* root){
    stack<Node*> s;
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        root = q.front();
        q.pop();
        s.push(root);
        if(root->right!=NULL){
            q.push(root->right);
        }

        if(root->left!=NULL){
            q.push(root->left);
        }
    }
    while(!s.empty()){
        Node* curr = s.top();
        cout << curr->data <<' ';
        s.pop();
    }
}

//  5 1 3 -1 -1 2 -1 -1 1 5 -1 -1 -1
int main()
{
    Node *root = NULL;
    root = buildTree(root);
    ReverseLevelOrderTraversal(root);
    return 0;
}