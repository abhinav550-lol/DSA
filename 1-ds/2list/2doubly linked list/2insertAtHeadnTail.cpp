#include <iostream>
#include<bits/stdc++.h>
#include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\linkedList\2doubly linked list\0import.cpp"
// comment this line ^^^^ when practicing
using namespace std;
 
 insertAtHead(Node* &head,int val){
    Node* n2 = new Node(val);
    head->prev = n2;
    n2->next = head;
    head = n2;
 }

insertAtTail(Node* &tail,int val){
   Node* n2 = new Node(val);
   tail->next = n2;
   n2->prev =tail;
   tail =n2;

}

int main(){
   Node *n1 = new Node(20);
   Node* head= n1;
   Node* tail = n1;
   printDLL(head);

   insertAtHead(head,10);
   insertAtTail(tail,15);
   printDLL(head);

  return 0;
}