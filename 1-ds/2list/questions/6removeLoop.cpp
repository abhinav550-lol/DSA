#include <iostream>
#include <bits/stdc++.h>
#include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\linkedList\3circular linked list\0import.cpp"
using namespace std;

void printLL(Node *head){
    Node* temp = head;
    while(temp!= NULL)
    {
        cout<<temp->data<<' ';
        temp = temp->next;
    }
    cout<<endl;
}

Node* beginningOfTheLoop(Node *tail)
{
    Node* fast = tail;
    Node* slow = tail;
    while(fast != NULL && fast->next!=NULL){
        fast = fast -> next -> next;
        slow = slow -> next;
        if(slow == fast ) break;
    }
    if(fast== NULL || fast -> next ==NULL){ return NULL ;}
    slow = tail;
    while(slow!=fast){
        slow = slow -> next;
        fast = fast -> next;
    }
    return fast;
}
void removeLoop(Node* &tail ){
    if(tail==NULL){return ;}
    Node* startOfLoop = beginningOfTheLoop(tail);
    Node* prev = startOfLoop;
    while(prev->next!=startOfLoop){
        prev=prev->next;
    } 
    prev->next = NULL;
}

int main()
{
    Node *tail = NULL;
    insertNode(tail, 1);
    insertNode(tail, 3, 1);
    insertNode(tail, 5, 3);
    insertNode(tail, 4, 5);
    insertNode(tail, 11, 4);
    printCLL(tail);
    Node* LOOP =  beginningOfTheLoop(tail) ;
    cout<<LOOP->next;
    removeLoop(tail);
    return 0;
}