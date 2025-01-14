class Solution
{
    int findElementInOrder(int element,int * in , int size){
        for(int i=0 ; i< size ;i++){
            if(element == in[i]){
                return i;
            }
        }
    }

    Node* solve(int *in , int *post, int size, int &postOrderIndex  , int inOrderStart,int inOrderEnd){
        if(postOrderIndex < 0 || inOrderEnd < inOrderStart) return NULL;

        int element = post[postOrderIndex--];
        Node* root = new Node(element);
        int position = findElementInOrder(element,in,size);

        root -> right = solve(in,post,size,postOrderIndex,position + 1,inOrderEnd);
        root -> left = solve(in,post,size,postOrderIndex,inOrderStart,position - 1);

        return root;
    }
    public:
    //Function to return a tree created from postorder and inoreder traversals.
    Node *buildTree(int in[], int post[], int n) {
        int postOrderIndex = n - 1;
        int inOrderStart = 0;
        int inOrderEnd = n-1;
        Node* res = solve(in , post , n ,postOrderIndex,inOrderStart, inOrderEnd);
        return res;
    }
};