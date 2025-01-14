#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
 class Node{
    public:
    Node* prev;
    int data;
    Node* next;
    Node(int data){
        this-> data = data;
        prev = NULL;
        next = NULL;
    }
 };

 printDLL(Node * head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<' ';
        temp = temp ->next;
    }cout<<endl;
 }
 
 int LinkedListLength(Node* head){
    int length =0;
    while(head!=nullptr){
        length++;
        head=head->next;
    }
    return length;
 }
 
int main(){
   Node* n1 = new Node(10);
   printDLL(n1);
   cout<<LinkedListLength(n1);
  return 0;
}