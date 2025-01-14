#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
void pushAtBottom(stack<int>& s, int x) 
{
    if(s.empty()){
        s.push(x);
        return ;
    }
    int poppedElement = s.top();
    s.pop();
    pushAtBottom(s, x);
    s.push(poppedElement);
}

 void print(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << ' ';
        s.pop();
    }cout<<endl;
}

int main(){
    stack<int> s1;
    s1.push(4);
    s1.push(4);
    s1.push(5);
    s1.push(6);
    s1.push(2);
    s1.push(3);
    print(s1);
    pushAtBottom(s1,5);
    print(s1);
  return 0;
}