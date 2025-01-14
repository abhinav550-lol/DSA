#include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\binaryTree\1theory\0import.cpp"

bool isIdentical(Node *r1, Node *r2){
    if(r1 == NULL && r2 == NULL )
        return true;
    if(r1 != NULL && r2 == NULL || r1 == NULL && r2 != NULL)
        return false;
        
    bool right = isIdentical(r1->right,r2->right);
    bool left = isIdentical(r1->left,r2->left);
    bool res = r1 -> data == r2 -> data;
    
    if(right && left && res){
        return true;
    }else{
        return false;
    }
}
int main(){
    
    return 0;
}