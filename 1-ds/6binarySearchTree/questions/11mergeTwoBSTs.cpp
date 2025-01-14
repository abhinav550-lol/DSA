#include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\6binarySearchTree\1theory\0import.cpp"

void inOrderTraversal(Node* root, vector<int> &in){
    if(root == NULL) return ;

    if(root -> left) inOrderTraversal(root -> left , in);
    in.push_back(root -> data);
    if(root -> right) inOrderTraversal(root -> right, in);
}

Node* inorderToBST(vector<int> &inorder,int start , int end){
    if(start > end) return NULL;

    int mid = (start + end )/ 2;
    Node* root = new Node(inorder[mid]);
    root -> left = inorderToBST(inorder,start,mid-1);
    root -> right = inorderToBST(inorder,mid+1,end);

    return root;
}

Node* mergeTwoBSTs(Node* r1 , Node* r2){
    vector<int> inorder1;
    vector<int> inorder2;
    inOrderTraversal(r1,inorder1);
    inOrderTraversal(r2,inorder2);
    int n = inorder1.size();
    int m = inorder2.size();
    vector<int> mergedBST;

    int i = 0, j = 0;
    while(i < n && j < m){
        if(inorder1[i] < inorder2[j]){
            mergedBST.push_back(inorder1[i++]);
        }else{
            mergedBST.push_back(inorder2[j++]);
        }
    }
    while(i<n) mergedBST.push_back(inorder1[i++]);
    while(j<m) mergedBST.push_back(inorder2[j++]);
    return inorderToBST(mergedBST,0 , mergedBST.size()-1);
}
int main()
{
    Node *r1 = NULL;
    Node* r2 = NULL;
    buildBST(r1);
    buildBST(r2);
    Node* r3 = mergeTwoBSTs(r1  , r2 );
    vector<int> v;
    inOrderTraversal(r3, v);
    for(int i : v)
    cout << i <<' ';
    return 0;
}


// O(N1 + N2) Sc and Tc
// vector<int> mergeTwoBSTs(Node* r1 , Node* r2){
//     vector<int> inorder1;
//     vector<int> inorder2;
//     inOrderTraversal(r1,inorder1);
//     inOrderTraversal(r2,inorder2);
//     int n = inorder1.size();
//     int m = inorder2.size();
//     vector<int> mergedBST;

//     int i = 0, j = 0;
//     while(i < n && j < m){
//         if(inorder1[i] < inorder2[j]){
//             mergedBST.push_back(inorder1[i++]);
//         }else{
//             mergedBST.push_back(inorder2[j++]);
//         }
//     }
//     while(i<n) mergedBST.push_back(inorder1[i++]);
//     while(j<m) mergedBST.push_back(inorder2[j++]);
    
//     return mergedBST;
// }
