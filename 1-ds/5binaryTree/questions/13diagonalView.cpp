#include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\binaryTree\1theory\0import.cpp"

vector<int> diagonal(Node *root)
{
    if(root == NULL) return {};
    queue<Node*> q;
    vector<int> res;
    
    q.push(root);
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        while(curr != NULL){
            if(curr -> left){
                q.push(curr -> left);
            }
            res.push_back(curr -> data);
            curr = curr -> right;
        }
    }
    return res;
}

//5 5 1 3 2 -1 -1 -1 -1 -1 -1

int main(){
Node* root = NULL;
buildTreeFromLevelOrder(root);
vector<int> v = diagonal(root);
for(int i : v){
    cout<< i << ' ';
}
  return 0;
}
