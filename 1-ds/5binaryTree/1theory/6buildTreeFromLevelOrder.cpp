#include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\binaryTree\1theory\0import.cpp"

void buildTreeFromlevelOrder(Node* &root){
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


// 5 1 3 -1 -1 2 -1 -1 1 5 -1 -1 -1
int main(){ 
    Node* root = NULL;
    buildTreeFromlevelOrder(root);
    return 0;
}