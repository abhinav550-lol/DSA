#include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\binaryTree\1theory\0import.cpp"

    vector<int> bottomView(Node* root)    {
            //Your code here
            map<int , int> m;
        queue<pair<Node* ,int>> q;
        vector<int> res;

        if(root == NULL ) return res;

        q.push(make_pair(root,0));

        while(!q.empty()){
            pair<Node*, int> curr = q.front();
            q.pop();

            int xAxis = curr.second;
            Node* currNode = curr.first;
            m[xAxis] = currNode -> data;
            

            if(currNode -> left) q.push(make_pair(currNode->left,xAxis -1));
            if(currNode -> right) q.push(make_pair(currNode->right,xAxis +1));
        }
        for(auto i : m){
            res.push_back(i.second);
        }
        return res;
        }

//5 5 1 3 2 -1 -1 -1 -1 -1 -1

int main(){
Node* root = NULL;
buildTreeFromLevelOrder(root);
vector<int> v = bottomView(root);
for(int i : v){
    cout<< i << ' ';
}
  return 0;
}
