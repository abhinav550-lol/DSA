#include <iostream>
#include <bits/stdc++.h>
#include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\linkedList\1singly linked list\0importLL.cpp"
using namespace std;

  void removeDuplicates(Node* & head) {
      if (head == NULL || head->next == NULL) return ;
      unordered_map<int,bool> unique;
      Node* curr = head;
      Node* prev = NULL;
      while(curr!=NULL ){
      if(unique[curr->value] == false){
        unique[curr->value]= true;
        prev = curr;
        curr = curr -> next;
      }else{
        Node* duplicate = curr;
        curr = curr -> next;
        delete duplicate;
        prev -> next = curr;
      }
 }
  }


int main()
{
  Node *n1 = new Node(1);
  Node *head = n1;
  Node *tail = n1;
  insertAtTail(tail, 13);
  insertAtTail(tail, 3);
  insertAtTail(tail, 2);
  insertAtTail(tail, 13);
  insertAtTail(tail, 4);
  insertAtTail(tail, 3);
  insertAtTail(tail, 4);
  printLL(head);
  removeDuplicates(head);
  printLL(head);
  return 0;
}