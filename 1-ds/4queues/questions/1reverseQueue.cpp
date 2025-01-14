#include <iostream>
#include<bits/stdc++.h>
using namespace std;

 void reverseQueue(queue<int> &q){
    if(q.empty()){
        return ;
    }
    int poppedElem = q.front();
    q.pop();
    reverseQueue(q);
    q.push(poppedElem);
 }

 void printQueue(queue<int> q1){
    while(!q1.empty()){
        cout << q1.front() << " ";
        q1.pop();
    }
 }

int main(){
   queue<int> q1;
   q1.push(10);
   q1.push(14);
   q1.push(13);
   q1.push(12);
   reverseQueue(q1);
   printQueue(q1);
  return 0;
}