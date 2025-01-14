#include <iostream>
#include<bits/stdc++.h>
using namespace std;

template <typename T>
 class Node
{
public:
    Node *next;
    T value;
    Node(T data)
    {
        value = data;
        next = NULL;
    }
    ~Node(){
        value = 0;
        next = NULL;
        delete next;
    }
};

template <typename T>
insertAtTail(Node<T>* &head,Node<T>* &tail, T val){
    Node<T>* n = new Node<T>(val);
    if(tail == NULL){
        tail = n;
        head = n;
    }else{
        tail -> next = n;
        tail = n;
    }
}

template <typename T>
 class STACK{
    public:
    Node<T>* stackHead;
    Node<T>* stackTail;
    int stackIndex;
    int stackSize;
    STACK(int intialSize = 5) : stackSize(intialSize) , stackIndex(-1),stackTail(NULL),stackHead(NULL){}
    ~STACK(){
        Node<T>* temp = stackHead;
        while(temp != NULL){
            Node<T>* next = temp -> next;
            temp -> next = NULL;
            delete temp;
            temp = next;
        }
        stackHead = stackTail = NULL;
    }

    bool isEmpty(){
        return stackHead==NULL;
    }

    void push(T val){
        stackIndex++;
        if(stackIndex < stackSize){
            insertAtTail(stackHead,stackTail,val);
        }else{
            throw out_of_range("STACK_OVERFLOW");
        }
    }

    T top(){
        if(!isEmpty()){
            return stackTail -> value ;
        }else{
            throw out_of_range("STACK_UNDERFLOW");
        }
    } 

    void pop(){
        if(!isEmpty()){
        stackIndex --;
        Node<T>* iterator = stackHead; 
        while(iterator -> next != stackTail || iterator != tail) iterator = iterator -> next;
        iterator -> next = stackTail->next;
        delete stackTail;
        stackTail = iterator;
        }else{
            throw out_of_range("STACK_UNDERFLOW");
        }
    }
    int size(){
        return stackIndex + 1;
    }
 };
 
int main(){
   STACK<int> s;
   cout<<s.isEmpty()<<endl;
   s.push(5);
   s.push(4);
   s.push(4);
   s.pop();
   cout<<s.top()<<endl;
   s.push(4);
   cout<<s.size();
  return 0;
}