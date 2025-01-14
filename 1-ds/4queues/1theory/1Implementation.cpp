#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
class QUEUE{
 private:
 int *arr;
 int qSize;
 int qFront;
 int qBack;

 public:
 QUEUE(int s = 5):qSize(s){
    arr = new int[qSize];
    qFront = qBack = 0;
 }
 bool isEmpty(){
    if(qBack == qFront){
        return true;
    }
    return false;
 }
 void push(int val){
    if(qBack == qSize){
        cout<<"QUEUE IS FULL!!!";
        return ;
    }
    arr[qBack] = val;
    qBack++;
 }

 int pop(){
    if(isEmpty()){
    cout<<"QUEUE IS EMPTY!!!";
    return -1;
    } 
    int res = arr[qFront];
    arr[qFront] = -1;
    qFront++;

    return res;
 }
 int size(){
    if(isEmpty()) return 0;
    return qBack - qFront;
 }
 int front(){
    if(isEmpty()){
        return -1;
    }
    return arr[qFront];
 }
 int back(){
    if(isEmpty()){
        return -1;
    }
    return arr[qBack-1];
 }
} ;


int main(){
   QUEUE q1(10);
   q1.push(5);
   q1.push(4);
   q1.push(3);
   q1.push(2);
   cout<<q1.isEmpty()<<endl;
//    cout << q1.pop()<<endl;
   cout << q1.size()<<endl;
   cout<<q1.front()<<endl;
   cout<<q1.back()<<endl; 
  return 0;
}