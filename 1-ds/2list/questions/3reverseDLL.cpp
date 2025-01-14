#include <iostream>
#include<bits/stdc++.h>
#include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\linkedList\2doubly linked list\0import.cpp"
using namespace std;
 
 void reverseDLL(Node * &head){
    if(head == NULL || head ->next == NULL){return ;}
      Node *curr = head;
      Node *prev = NULL;
      Node* save;
      while(curr != NULL){
            save = curr -> next;
            curr -> next = prev;
            curr -> prev = save;
            prev = curr;
            curr = save;
      }
      head = prev; 
   }

int main(){
   
   Node *n1 = new Node(12);
   Node* head = n1 ;
   Node* tail = n1 ;
   insertAtHead(head, 5);
   insertAtHead(head, 3);
   insertAtHead(head, 4);
   printDLL(head); 

   reverseDLL(head);
   printDLL(head);
  return 0;
}