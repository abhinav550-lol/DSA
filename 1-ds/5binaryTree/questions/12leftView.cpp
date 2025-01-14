#include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\binaryTree\1theory\0import.cpp"


void solve(Node* root , int &level , vector<int> &res){
    if(root == NULL ) return ;

    if(level == res.size())
        res.push_back(root -> data);

    if(root - > left ) solve(root -> left , level + 1 , res);
    if(root -> right) solve( root-> right , level + 1, res);
}

vector<int> leftView(Node* root)    {
 vector<int> ans;
 solve(root,0,ans);     
 return ans;
}

//5 5 1 3 2 -1 -1 -1 -1 -1 -1

int main(){
Node* root = NULL;
buildTreeFromLevelOrder(root);
vector<int> v = leftView(root);
for(int i : v){
    cout<< i << ' ';
}
  return 0;
}
