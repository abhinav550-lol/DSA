#include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\binaryTree\1theory\0import.cpp"

void solve(Node* root, int k, int & count , vector<int> path){
    if(root == NULL ) return ;

    path.push_back(root -> data);

    solve(root -> right, k ,count,path);
    solve(root -> left, k ,count,path);

    int size = path.size();
    int sum =0;
    for(int i=size-1;i>=0;i--){
        sum += path[i];
        if(sum == k) count ++;
    }
    path.pop_back();
}

int kSumPaths(Node* root,int k){
    int count = 0;
    vector<int> path;
    solve(root ,k,count , path);
    return count;
}


//5 4 1 3 2 -1 -1 -1 -1 -1 -1

int main(){
Node* root = NULL;
buildTreeFromLevelOrder(root,1 , 4);
int v = kSumPaths(root,5);
cout << v;
  return 0;
}
