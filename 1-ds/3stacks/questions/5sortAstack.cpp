#include <iostream>
#include<bits/stdc++.h>
using namespace std;
    
void print(stack<int> s){
    while(!s.empty())
    {
      cout<<s.top()<<endl;
      s.pop();
    }
}


void insertSorted(stack<int> &s,int element){
  if(s.empty() || s.top()<element){
    s.push(element);
    return ;
  }
  int poppedElement = s.top();
  s.pop();
  insertSorted(s,element);

  s.push(poppedElement);
}

void sortStack(stack<int> &s){
  if(s.empty()){
    return ;
  }
  int poppedElement = s.top();
  s.pop();
  sortStack(s);

  insertSorted(s,poppedElement);
 }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   

int main(){
   stack <int> s;
   s.push(7);
   s.push(1);
   s.push(10);
   s.push(2);
   sortStack(s);
   print(s);
  return 0;
}