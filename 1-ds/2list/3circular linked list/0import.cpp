#include <iostream>
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
 
 void printCLL(Node* tail){
    if(tail == NULL ) {
        cout<<"tail is empty";
        return ;
         }
    Node* iterator = tail;
    do{
        cout<<iterator->data<<' ';
        iterator=iterator->next;
    }while(iterator!= tail);
    cout<<endl;
 }
