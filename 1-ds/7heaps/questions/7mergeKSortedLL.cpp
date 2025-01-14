#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Forward declaration of the Node class
class Node;

void insertAtTail(Node* &head, Node* &tail, Node* &curr){
    if(head == NULL){
        head = tail = curr;
    }else{
        tail -> next = curr;
        tail = curr;
    }
}

class customOptions{
 public:
 bool operator()(Node* a, Node* b){
    return a-> data > b -> data;
 }
};

Node* mergeKLists(vector<Node*> &listArray){
    Node* mergedHead = NULL;
    Node* mergedTail = NULL;
    int size = listArray.size();
    priority_queue<Node* , vector<Node*> , customOptions> pq;

    for(int i=0 ; i < size ; i++)    pq.push(listArray[i]);

    while(!pq.empty()){
        Node* curr = q.top();
        q.pop();

        insertAtTail(mergedHead, mergedTail , curr);

        if(curr->next != NULL){
            pq.push(curr->next);
        }
    }
    return mergedHead;
}

int main(){
    return 0;
}

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
