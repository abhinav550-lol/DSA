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

void deleteNode(Node*&head,Node* &tail, int pos)
{
    if(pos==1){
        Node* prev = head;
        head = head -> next;
        prev -> next = NULL;
        delete prev;
    }else{
        Node* prev = NULL;
        Node* current = head;
        int count = 1;
        while(count < pos){
            prev = current;
            current = current -> next;
            count++;
        }
        if(current->next == NULL){
            tail = prev;
            prev->next = NULL;
            delete current;
            return ;
        }
        prev->next = current-> next;
        current->next = NULL;
        delete current;
    }
}
