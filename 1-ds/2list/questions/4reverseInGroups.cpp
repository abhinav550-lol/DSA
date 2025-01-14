#include <iostream>
#include <bits/stdc++.h>
#include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\linkedList\1singly linked list\0importLL.cpp"
using namespace std;

/****************************************************************
    Following is the Linked List node structure

    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/


Node* kReverse(Node* head, int k) {
    //base call
    if(head == NULL) {
        return NULL;
    }
    
    //step1: reverse first k nodes
    Node* next = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int count= 0;
    
    while( curr != NULL && count < k ) {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    
    //step2: Recursion dekhlega aage ka 
    if(next != NULL) {
        head -> next = kReverse(next,k);
    }
    
    //step3: return head of reversed list
    return prev;
}
int main()
{
  Node *n1 = new Node(1);
  Node *head = n1;
  Node *tail = n1;
  insertAtTail(tail, 2);
  insertAtTail(tail, 3);
  insertAtTail(tail, 4);
  insertAtTail(tail, 5);
  printLL(head);

  int k = 2;
  printLL(kReverse(head, k));
  return 0;
}
