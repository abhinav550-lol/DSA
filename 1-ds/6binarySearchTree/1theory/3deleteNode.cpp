    #include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\6binarySearchTree\1theory\0import.cpp"

    Node* minOfBST(Node* root){
        if(root == NULL ) return NULL;
        while(root -> left ) root = root -> left;
        return root;
    }

    Node* deleteNode(Node* root, int nodeToDelete){
        if(root == NULL ) return NULL;

        if(root -> data == nodeToDelete){ 
            if(root -> right == NULL && root -> left ==NULL ){
                delete root;
                return NULL;
            }

            if(root -> right != NULL && root ->left == NULL){
                Node* rightNode = root -> right;
                delete root;
                return rightNode;
            }

            if(root -> left != NULL && root -> right == NULL){
                Node* leftNode = root -> left;
                delete root;
                return leftNode;
            }
            
            if(root -> left != NULL && root -> right != NULL){
                int minValToRight = minOfBST(root->right)->data;
                root -> data = minValToRight;
                root -> right =  deleteNode(root -> right, minValToRight);
                return root;
            }
        }else if(root ->data > nodeToDelete){
            root -> left = deleteNode(root -> left , nodeToDelete);
            return root;
        }else{
            root -> right = deleteNode(root -> right, nodeToDelete);
            return root;
        }
    }

    int main(){
        Node* root = NULL;
        buildBST(root);
        levelOrderTraversal(root);
        root = deleteNode(root,12);
        levelOrderTraversal(root);
    return 0;
    }