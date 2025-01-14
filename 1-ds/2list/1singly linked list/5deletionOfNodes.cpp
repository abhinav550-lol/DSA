#include <iostream>
#include <bits/stdc++.h>
#include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\linkedList\1singly linked list\0importLL.cpp"
// comment this line ^^^^ when practicing

using namespace std;

void deleteNode(Node*&head,Node* &tail, int pos)
{
    if(pos==1){
        Node* prev = head;
        head = head -> next;
        prev -> next = NULL;
        delete prev;
    }else{
        Node* prev = NULL;
        Node* current = head;
        int count = 1;
        while(count < pos){
            prev = current;
            current = current -> next;
            count++;
        }
        if(current->next == NULL){
            tail = prev;
            prev->next = NULL;
            delete current;
            return ;
        }
        prev->next = current-> next;
        current->next = NULL;
        delete current;
    }
}

int main()
{
    Node *n1 = new Node(10);
    Node *head = n1;
    Node *tail = n1;
    insertAtTail(tail, 15);
    insertAtTail(tail, 25);
    insertAtTail(tail, 35);
    printLL(head);

    int pos = 4;
    deleteNode(head,tail, pos);
    cout<<head->value<<' '<<tail->value<<endl;
    printLL(head);
    return 0;
}
