#include <iostream>
#include<bits/stdc++.h>
#include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\linkedList\1singly linked list\0importLL.cpp"
using namespace std;

Node* getMid(Node* head){
  Node* slow = head;
  Node* fast = head->next;
  while(fast != NULL && fast -> next != NULL){
    fast = fast -> next -> next;
    slow =slow -> next;
  }
  return slow;
}
Node* merge(Node* leftList, Node* rightList){
  if(leftList==NULL) return rightList;
  if(rightList==NULL) return leftList;

  Node* sortedHead = new Node(0);
  Node* curr = sortedHead;

  while(leftList!=NULL && rightList != NULL){
    if(leftList->value <rightList-> value){
      curr -> next = leftList;
      leftList = leftList -> next;
    }else{
      curr -> next = rightList;
      rightList = rightList -> next;      
    }
      curr = curr -> next;
  }
  while(leftList != NULL){
      curr -> next = leftList;
      leftList = leftList -> next;
      curr = curr -> next;
  }
  while(rightList != NULL){
      curr -> next = rightList;
      rightList = rightList -> next;
      curr = curr -> next;
  }

  return sortedHead -> next;
}

Node* mergeSort(Node* head){
  if(head == NULL || head -> next ==NULL ) return head;
  Node* mid = getMid(head);

  Node* leftList = head;
  Node* rightList = mid->next;
   mid -> next = NULL;

   leftList = mergeSort(leftList);
   rightList = mergeSort(rightList);

  Node* sortedHead = merge(leftList,rightList);

  return sortedHead;
}



int main(){
    Node* n1 = new Node(15);
    Node* head = n1 ;
    Node* tail = n1;
    insertAtTail(tail,10);
    insertAtTail(tail,1);
    insertAtTail(tail,23);
    insertAtTail(tail,20);
    printLL(head);
    head=mergeSort(head);
    printLL(head);

  return 0;
}