#include <iostream>
#include<bits/stdc++.h>
#include <cmath>
#include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\linkedList\1singly linked list\0importLL.cpp"
 using namespace std;

 Node* middleElement(Node* head){
    if(head == NULL || head -> next == NULL){ return head;}
    Node* pro = head,*noob = head;
    while(pro!=NULL && pro -> next != NULL){
        pro = pro-> next -> next;
        noob = noob -> next;
    }
    return noob;
 }
 
int main(){
   Node* n1 = new Node(15);
   Node* head1 = n1;
   Node* tail1 = n1;
   insertAtTail(tail1 , 51);
   insertAtTail(tail1 , 43);
   insertAtTail(tail1 , 2);
   Node* mid1 = middleElement(head1);

   Node* n2 = new Node(10);
   Node* head2 = n2;
   Node* tail2 = n2;
   insertAtTail(tail2 ,83);
   insertAtTail(tail2 , 12);
   Node* mid2 = middleElement(head2);
    

   printLL(head1); 
   printLL(head2); 
   printLL(mid1);
   printLL(mid2);
  return 0;
}


// BRUTE FORCE -- >
/*
Node* middleElement(Node* head){
    if(head == NULL || head -> next == NULL){ return head;}
    Node* temp = head;
    int len = 0;
    while(temp!= NULL) {
        temp = temp->next; 
        len ++;
    }   
    int m = ceil(len/2);
    Node* mid = head;
    while(m!=0){
        mid = mid -> next;
        m--; 
    }
    return mid;
}
*/