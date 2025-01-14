#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void print(queue<int> q);
// interleave using a stack only!!!!
void interleaveQueue(queue<int> &q, int size){
    stack<int> s;
    int mid = size / 2;
    for(int i=0;i<mid;i++){
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }

    for(int i=0;i<mid;i++){
        int curr = q.front();
        q.pop();
        q.push(curr);
    }

    for(int i=0;i<mid;i++){
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()){
        int curr = s.top();
        q.push(curr);
        s.pop();

        curr = q.front();
        q.push(curr);
        q.pop();
    }
} 

int main(){
   queue<int> q;
   q.push(14);
   q.push(15);
   q.push(12);
   q.push(11);
   q.push(12);
   q.push(13);
   q.push(71);
   q.push(11);
   print(q);
   interleaveQueue(q,q.size());
   print(q); 
  return 0;

}

void print(queue<int> q){
    while(!q.empty()){
        int curr = q.front();
        cout << curr << ' ';
        q.pop();
    }
    cout<<endl;
}
