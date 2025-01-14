#include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\binaryTree\1theory\0import.cpp"

void solve(Node* root, int k,int nodeToSearchOn,vector<int> path,int & ans){
    if(root == NULL ) return ;
    path.push_back(root -> data);
    
    if(root -> left) solve(root -> left, k ,nodeToSearchOn,path,ans);
    if(root -> right ) solve(root -> right,k,nodeToSearchOn,path,ans);

    
    int lastIndex = path.size() - 1;
    if(path[lastIndex] == nodeToSearchOn && lastIndex - k >=0){
        ans = path[lastIndex - k];
    }
        path.pop_back();
}

int kthAncestor(Node* root,int k,int nodeToSearchOn){
  if(root == NULL ) return -1;
  vector<int> path;
  int ans = -1;  
solve(root,k,nodeToSearchOn,path,ans);
  return ans;
}


//5 4 1 3 2 -1 -1 -1 -1 -1 -1

int main(){
Node* root = NULL;
buildTreeFromLevelOrder(root,1 , 4);
int v = kthAncestor(root,1,1);
cout << v;
  return 0;
}
