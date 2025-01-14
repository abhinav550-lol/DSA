#include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\binaryTree\1theory\0import.cpp"
class Solution {
  public:
 Node* createMapping(Node* root, map<Node*, Node*>& parentToChildren,int targetNode){
    parentToChildren[root] = NULL;

    queue<Node*> q;
    q.push(root);

    Node* res = NULL;
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        if(targetNode == curr->data) res = curr;

        if(curr->left) {
        q.push(curr -> left);    
        parentToChildren[curr->left] = curr;
        }
        if(curr->right) {
            q.push(curr -> right);
            parentToChildren[curr->right] = curr;
        }
    }
    return res;
}

int burnTree(Node* root,map<Node* , Node*> &parentToChildren){
    map<Node*, bool> visited;
    queue<Node*> q;
    q.push(root);
    visited[root] = true;
    int ans= 0;

    while(!q.empty()){
        int size = q.size();
        int flag = 0;
        for(int i = 0 ; i< size ;i++){
            Node * curr = q.front();
            q.pop();

            if(curr -> left && !visited[curr -> left]){
                q.push(curr -> left);
                visited[curr -> left] = true;
                flag = true;
            }
            if(curr -> right && !visited[curr -> right]){
                q.push(curr -> right);
                visited[curr -> right] = true;
                flag = true;
            }
            if(parentToChildren[curr] && !visited[parentToChildren[curr]]){
                q.push(parentToChildren[curr]);
                visited[parentToChildren[curr]] = true;
                flag = true;
            }
        }
        if(flag == 1) ans++;
    }
    return ans;
}

int minTime (Node* root,int target){
    map<Node* , Node*> parentToChildren;
    Node* targetNode= createMapping(root,parentToChildren,target);   
    int ans = burnTree(targetNode , parentToChildren);
    return ans;
}

};

//5 4 1 3 2 -1 -1 -1 -1 -1 -1

int main(){
Node* root = NULL;
buildTreeFromLevelOrder(root);
int t = minTimeToBurnTree(root,5);
  return 0;
}
