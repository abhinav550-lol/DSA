#include <iostream>
#include <bits/stdc++.h>
#include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\linkedList\3circular linked list\0import.cpp"
using namespace std;

void deleteCircularNode(Node *&tail, int element){
    if(tail == NULL){
        cout<<"Empty LL";
        return ;
    }
   Node* prev = tail ;
   Node* curr = prev -> next ;

   while(curr -> data != element){
        prev = curr ;
        curr = curr -> next ;
   }
   
   prev -> next = curr -> next;

   if(prev == curr ){
        tail = NULL;
   }
   else if(tail == curr){
     tail = prev;
   } 

    curr -> next =NULL;
    delete curr ;
}

int main()
{
    Node *tail = NULL;
    insertNode(tail, 3);
    insertNode(tail, 4, 3);
    insertNode(tail, 5, 4);
    insertNode(tail, 6, 5);

    printCLL(tail);
    int element ;
    cin>>element;

    deleteCircularNode(tail, element);
    printCLL(tail);
    return 0;
}