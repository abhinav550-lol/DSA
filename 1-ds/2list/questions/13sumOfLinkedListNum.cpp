#include <iostream>
#include<bits/stdc++.h>
#include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\linkedList\1singly linked list\0importLL.cpp"
using namespace std;
 
bool largerNumber(Node* h1, Node* h2){
    Node* t1 = h1;
    Node* t2 = h2;
    while(t1!=NULL && t2!=NULL){
        t1 = t1 -> next;
        t2 = t2 -> next;
    }
    if(t1 == NULL && t2 == NULL) return true;
    return t1!=NULL?true:false;
}

Node* reverseList(Node* &head){
    Node* curr = head;
    Node* newHead = NULL;
    while(curr!=NULL){
        Node* save = curr -> next;
        curr -> next = newHead;
        newHead= curr;
        curr = save;
    }
    return newHead;
}

void insertAtHead(Node* &head,int val){
    Node* n = new Node(val);
    if(head==NULL){
        head = n;
    }else{
        n -> next = head;
        head = n;
    }
}

Node* addTwoLists(Node* h1, Node* h2){
  while( h1!=NULL&&h1->value==0 ) h1 = h1 -> next;  
  while( h2!=NULL && h2->value==0) h2 = h2 -> next;  
  if(h2 == NULL ) return NULL;
  if(h1 == NULL ) return NULL;
  Node* num1 = NULL;
  Node* num2 = NULL;
  Node* result = NULL;
  if(largerNumber(h1,h2)){
    num1 = h1;
    num2 = h2;
  }else{
    num1 = h2;
    num2 = h1;
  }
  num1 = reverseList(num1);
  num2 = reverseList(num2);
  int carry = 0;
  while(num1 != NULL && num2 != NULL){
    int sum = num1 -> value + num2-> value + carry;
    int digit = sum % 10;
    carry = sum / 10;
    insertAtHead(result,digit);
    num1 = num1 -> next;
    num2 = num2 -> next;
  }
  while(num1!=NULL){
    int sum = num1 -> value + carry;
    int digit = sum % 10;
    carry = sum / 10;
    insertAtHead(result,digit);
    num1 = num1 -> next;
  }
  if(carry!=0){
    insertAtHead(result,carry%10);
  }
    num1 = reverseList(num1);
    num2 = reverseList(num2);
    return result;
}

int main(){
   Node* n1 = new Node(7);
   Node* h1 = n1 ;
   Node* t1 = n1 ;
   insertAtTail(t1,4);
   insertAtTail(t1,5);

   Node* n2 = new Node(4);
   Node* h2 = n2 ;
   Node* t2 = n2 ;
   insertAtTail(t2,5);
   insertAtTail(t2,5);

   cout<<"The Linked Lists: " <<endl;
   printLL(h1); 
   printLL(h2); 
   cout<<"Sum Of Linked Lists"<<endl;
   printLL(addTwoLists(h1,h2));
  return 0;
}