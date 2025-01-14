#include <iostream>
#include<bits/stdc++.h>
#include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\linkedList\1singly linked list\0importLL.cpp"
using namespace std;
 
 void sort0s1s2s(Node* &head){
    Node* zeroHead = NULL ; 
    Node* oneHead = NULL;
    Node* twoHead = NULL ;
    Node* curr = head ;
    while(curr!=NULL){
      Node* save = curr -> next;
      switch (curr->value)
      {
      case 0:
        curr -> next = zeroHead;
        zeroHead = curr ;
      break;
      case 1:
        curr -> next = oneHead;
        oneHead = curr ;
      break;
      case 2:
          curr -> next = twoHead;
          twoHead = curr ;
      break;
      }
      curr = save;
    }
  Node* iterator = zeroHead;
while(iterator!=NULL && iterator->next!=NULL) iterator = iterator -> next;
  Node* zeroTail = iterator;

  iterator = oneHead;
while(iterator!=NULL && iterator->next!=NULL) iterator = iterator -> next;
  Node* oneTail = iterator;

  iterator = twoHead;
while(iterator!=NULL && iterator->next!=NULL) iterator = iterator -> next;
  Node* twoTail = iterator;

  zeroTail -> next = oneHead; 
  oneTail -> next = twoHead;
  twoTail -> next = NULL;

  head = zeroHead;    
 }

int main(){
   Node* n1 = new Node(2);
   Node* head= n1; 
   Node* tail = n1; 
   insertAtTail(tail,1);
   insertAtTail(tail,0);
   insertAtTail(tail,2);
   insertAtTail(tail,2);
   insertAtTail(tail,1);
   insertAtTail(tail,2);
   insertAtTail(tail,1);
   insertAtTail(tail,0);
   printLL(head);
   sort0s1s2s(head);
   printLL(head);
  return 0;
}