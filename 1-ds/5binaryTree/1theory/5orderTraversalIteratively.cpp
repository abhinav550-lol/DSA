#include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\binaryTree\1theory\0import.cpp"


void inOrderTraversal(Node* root) {
    stack<Node*> s;
    Node* curr = root;

    while(curr != NULL || !s.empty()){
        while(curr != NULL){
            s.push(curr);
            curr = curr -> left;
        }

        curr = s.top();
        s.pop();

        cout<< curr -> data<<' ';


        curr = curr -> right;
    }
}


void preOrderTraversal(Node* root) {
    stack<Node*> s;
    s.push(root);

    while (!s.empty()) {
        Node* curr = s.top();
        s.pop();
        cout << curr->data << " ";

        if (curr->right) {
            s.push(curr->right);
        }
        if (curr->left) {
            s.push(curr->left);
        }
    }
}
void postOrderTraversal(Node* root){
    stack<Node*> s1, s2;
    s1.push(root);

    while (!s1.empty()) {
        Node* curr = s1.top();
        s1.pop();
        s2.push(curr);

        if (curr->left) {
            s1.push(curr->left);
        }
        if (curr->right) {
            s1.push(curr->right);
        }
    }

    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

//  5 1 3 -1 -1 2 -1 -1 1 5 -1 -1 -1
int main(){
    Node *root = NULL;
    root = buildTree(root);
    inOrderTraversal(root);
    cout<<endl;
    preOrderTraversal(root);
    cout<<endl;
    postOrderTraversal(root);
    return 0;
}