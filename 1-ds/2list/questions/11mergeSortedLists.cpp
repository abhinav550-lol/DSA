#include <iostream>
#include <bits/stdc++.h>
#include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\linkedList\1singly linked list\0importLL.cpp"
using namespace std;

Node* SelectFirst(Node* first, Node* second){
    Node* curr1 = first;
    Node* next1 = curr1->next;
    Node* curr2 = second;
    Node* next2 = curr2 -> next;

    if(next1==NULL){
       curr1->next = curr2;
      return first;
            }
    while(next1 != NULL && curr2!=NULL){
        if((curr1->value <= curr2->value) && (curr2->value <= next1->value)){
            curr1 -> next = curr2;
            next2 = curr2->next;
            curr2->next = next1;

            curr1 = curr2;
            curr2 = next2;
        }else{
            curr1 = next1;  
            next1 = next1->next;
            if(next1==NULL){
                curr1->next = curr2;
                return first;
            }
        }
    }
    return first;
}

Node* mergeSortedLists(Node* h1, Node* h2) {
    if(h1==NULL ) return h2;
    if(h2==NULL ) return h1;

    if(h1->value <= h2 -> value){
        return SelectFirst(h1,h2);
    }else{
        return SelectFirst(h2,h1);
    }
}


int main()
{
    Node *n1 = new Node(1);
    Node *h1 = n1;
    Node *t1 = n1;
    insertAtTail(t1, 5) ;
    insertAtTail(t1, 4);
    insertAtTail(t1, 7);

    Node *n2 = new Node(2);
    Node *h2 = n2;
    Node *t2 = n2;
    insertAtTail(t2, 3);
    insertAtTail(t2, 6);
    cout << "The two sorted linked lists are :" << endl;
    printLL(h1);
    printLL(h2);

    printLL(mergeSortedLists(h1,h2));
    return 0;
}