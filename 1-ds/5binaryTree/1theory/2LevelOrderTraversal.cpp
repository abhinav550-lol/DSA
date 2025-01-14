#include "1-ds/5binaryTree/1theory/0import.cpp"

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << ' ';
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
}   


// 5 1 3 -1 -1 2 -1 -1 1 5 -1 -1 -1
int main()
{
    Node *root = NULL;
    root = buildTree(root);
    levelOrderTraversal(root);
    return 0;
}