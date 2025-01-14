#include <iostream>
#include<bits/stdc++.h>
#include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\linkedList\1singly linked list\0importLL.cpp"
using namespace std;

void iterativeReverseLL(Node* &head){
      if(head == NULL || head ->next == NULL){ return ;}
      Node* prev = NULL;
      Node* curr = head;
      Node*save ;
      while(curr!=NULL){
        save = curr -> next;
        curr->next = prev;
        prev = curr;
        curr = save;
      }
      head = prev;
  }

  Node* recursiveReverseLL(Node* &head,Node* curr,Node* prev){
    if(curr == NULL){
      return prev;
    }
      Node* save = curr -> next;
      curr->next = prev;
      prev = curr ;
      curr = save;

      recursiveReverseLL(save,curr,prev);
  }
  
 Node *recursiveReverseLL2(Node * &head){
      if(head == NULL || head -> next ==NULL){
         return head;
      } 

      Node* newHead = recursiveReverseLL2(head->next);
      head -> next -> next = head;
      head -> next = NULL;

      return newHead;
    }


int main(){
  Node *n1 = new Node(15);
  Node *tail = n1;
  Node *head = n1;
  insertAtTail(tail,23);
  insertAtTail(tail,81);
  insertAtTail(tail,34);
  printLL(head);

  // iterativeReverseLL(head);

  Node* prev = NULL;
  Node* curr = head;
  head = recursiveReverseLL(head,curr,prev);

  // head = recursiveReverseLL2(head);
  printLL(head);
  return 0;
}