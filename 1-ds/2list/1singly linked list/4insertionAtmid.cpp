#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
class Node
{
public:
    Node *next;
    int value;
    Node(int data)
    {
        value = data;
        next = NULL;
    }
};

void printLL(Node *head){
    Node* temp = head;
    while(temp!= NULL)
    {
        cout<<temp->value<<' ';
        temp = temp->next;
    }
    cout<<endl;
}

void insertAtTail(Node* &tail,int data){
    Node* n2 = new Node(data);
    tail->next=n2;
    tail = n2;
}

void insertAtMid(Node* head , int pos ,int data){
    if(pos == 1){}
    int count = 1;
    Node* temp = head;
    while(count < pos-1){
        temp = temp ->next;
        count++;
    }
    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

int main(){
   Node* n1 = new Node(10);
   Node *head = n1;
   Node *tail = n1;
   insertAtTail(tail,15);
   insertAtTail(tail,18);

    int pos = 3;
   insertAtMid(head , pos , 17);
   printLL(head);
  return 0;
}