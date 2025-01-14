#include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\binaryTree\1theory\0import.cpp"



void zigZagTraversal(Node* root){
    queue<Node*> q;
    q.push(root);

    bool leftToRight = true;
    vector<int> res;
    while(!q.empty()){
        int size = q.size();
       vector<int> layers(size);

       for(int i=0;i<size;i++){
        Node* curr = q.front();
        q.pop();

        int index = leftToRight ? i : size - i - 1;
        layers[index] = curr -> data;

        if(curr -> left) q.push(curr -> left);
        if(curr -> right) q.push(curr -> right);
       }
       
    leftToRight = !leftToRight;
    for(int i: layers) res.push_back(i);

    }
}

//5 5 1 3 2 -1 -1 -1 -1 -1 -1

int main(){
Node* root = NULL;
buildTreeFromLevelOrder(root);
zigZagTraversal(root);
  return 0;
}
