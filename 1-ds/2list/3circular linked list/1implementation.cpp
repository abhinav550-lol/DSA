#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
  public:
   int data;
   Node* next;

   Node(int data){
    this->data = data;
    next = NULL;
   }
};

 void insertNode(Node* &tail,int val,int element=0){
    Node* t = new Node(val);
    if(tail == NULL){
        tail = t;
        tail -> next = tail;
        return ;
    }
    Node *finder = tail;
    while(finder->data != element ){
        finder=finder->next;
    }
    Node* save= finder->next;
    finder->next = t;
    t->next=save;
 }
 
 printCLL(Node* tail){
    Node* iterator = tail;
    do{
        cout<<iterator->data<<' ';
        iterator=iterator->next;
    }while(iterator!= tail);
 }


int main()
{
    Node* tail = NULL;
   insertNode(tail, 8);
   insertNode(tail, 3,8);
   insertNode(tail, 5,3);
   insertNode(tail, 4,5);
    insertNode(tail,11,8);
    
    printCLL(tail);


    return 0;
}