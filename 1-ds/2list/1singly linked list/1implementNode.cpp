#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
class Node{
    private:
    public:
    Node* next;
    int value;
    Node(int data){
        value=data;
        next = NULL;
    }
};

int main(){
   Node* n1 = new Node(10);
   cout<< n1->value<< endl;
   cout<< n1->next <<endl;
  return 0;
}