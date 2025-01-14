#include <iostream>
#include<bits/stdc++.h>
#include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\linkedList\2doubly linked list\0import.cpp"
using namespace std;

void insertAtPos(Node* &head,Node* &tail,int pos ,int val){
    if(pos==1){
        insertAtHead(head,val);
        return ;
    }else{
        Node* temp = head;
        int count = 1;
        while(count<pos-1){
            temp=temp->next;
            count++;
        }
        if(temp->next== NULL){
            insertAtTail(tail,val);
            return ;
        }
        Node* nodeToInsert = new Node(val);
        nodeToInsert->next=temp->next;
        temp->next->prev=nodeToInsert;
        temp->next = nodeToInsert;
        nodeToInsert->prev = temp;
    }
}
 
int main(){
   Node* n1 = new Node(10);
   Node* head = n1;
   Node* tail= n1;
   insertAtHead(head,13);
   insertAtHead(head,15);
   insertAtHead(head,14);
   printDLL(head);
   cout<<head->data<<" "<<tail->data<<endl;

   int pos ;
   cin>>pos;
   insertAtPos(head,tail,pos,5);
   printDLL(head);
  return 0;
}