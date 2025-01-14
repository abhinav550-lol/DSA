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