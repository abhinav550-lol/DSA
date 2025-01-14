#include <iostream>
#include<bits/stdc++.h>
#include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\linkedList\2doubly linked list\0import.cpp"
using namespace std;
 
void deletionOfnodes(Node* &head , Node* &tail, int pos){
    if(head!=NULL){
      if(pos == 1){
        Node* temp = head;
        head = head -> next;
        head -> prev = NULL;
        temp -> next =NULL;
        delete temp;
      }else{
        Node* curr = head;
        Node* prev = NULL;
        int count = 1;
        while(count<pos){
          prev = curr;
          curr = curr -> next ;
          count ++;
        }
        if(curr == tail){
          tail = tail -> prev;
          curr -> prev = NULL;
          tail -> next = NULL;
          delete curr;
          return ;
        }
        prev -> next = curr -> next ;
        curr -> next -> prev = prev;
        curr -> next = NULL;
        curr-> prev = NULL ;
        delete curr;
      }
      return ;
    }
      cout<<"Empty Linked List"<<endl;
  }

int main(){
   Node* n1 = new Node(10);
   Node* head = n1;
   Node* tail= n1;
   insertAtTail(tail,11);
   insertAtTail(tail,13);
   insertAtTail(tail,14);
   printDLL(head);

   int pos;
   cin>>pos;
   deletionOfnodes(head,tail,pos);
   printDLL(head);
   cout<<head->data<<' '<<tail->data;
  return 0;
}