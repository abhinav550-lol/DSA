#include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\6binarySearchTree\1theory\0import.cpp"

int kthSmallestMorris(Node* root,int k){
    Node* curr = root;
    int count = 0;
    while( curr != NULL){
        if(curr -> left == NULL){
            count ++;
            if(count == k) return curr -> data;
            curr = curr -> right;
        }else{
            Node* prev = curr -> left;
            while(prev -> right && prev -> right != curr){
                prev = prev -> right;
            }
            if(prev -> right == NULL){
                prev -> right = curr;
                curr = curr -> left;
            }else{
                count++;
                if(count == k) return curr -> data;
                prev -> right = NULL;
                curr = curr -> right;
            }
        }
    }
    return -1;
}

int main()
{
    Node *root = NULL;
    buildBST(root);
    cout << kthSmallestMorris(root);
    return 0;
}

