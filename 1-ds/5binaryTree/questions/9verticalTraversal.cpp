#include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\binaryTree\1theory\0import.cpp"

vector<int> verticalTraversal(Node* root){
    map<int , map<int , vector<int> > >nodes;
    queue<pair<Node* , pair <int ,int>>> q;
    vector<int> res;

    if(root == NULL) return res;

    q.push(make_pair(root,make_pair(0,0)));
    while(!q.empty()){
        pair<Node* , pair <int ,int>>  curr = q.front();
        q.pop();

        Node* currNode = curr.first;
        int lvl = curr.second.first;
        int xAxis = curr.second.second;

        nodes[xAxis][lvl].push_back(currNode->data);

        if(currNode -> left)
            q.push(make_pair(currNode->left,make_pair(lvl+1,xAxis - 1)));  
        if(currNode -> right)
            q.push(make_pair(currNode->right,make_pair(lvl+1,xAxis+1)));
    }
    for(auto i : nodes){
        for(auto j : i.second){
            for(auto k: j.second){
                res.push_back(k);
            }
        }
    }
    return res;
}

//5 5 1 3 2 -1 -1 -1 -1 -1 -1

int main(){
Node* root = NULL;
buildTreeFromLevelOrder(root);
vector<int> v = verticalTraversal( root);
for(int i : v){
    cout<< i << ' ';
}
  return 0;
}


