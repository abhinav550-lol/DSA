#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << ' ';
        s.pop();
    }cout<<endl;
}

void recursiveDeletion(stack<int> &s,int count,int mid){
    if(count == mid ){
        s.pop();
        return ;
    }
    int poppedElement = s.top();
    s.pop();
    recursiveDeletion(s,count+1,mid);
    s.push(poppedElement);
}

void deleteMiddle(stack<int> &s,int n){
    if(s.empty()) return ;
    if(n == 0){
        s.pop();
        return ;
    }
    int size = s.size();
    int mid = size / 2;
    int count = 0;
    recursiveDeletion(s,count,mid);
}

int main()
{
    stack<int> s1;
    s1.push(4);
    s1.push(4);
    s1.push(5);
    s1.push(6);
    s1.push(2);
    s1.push(3);
    print(s1);
    deleteMiddle(s1,s1.size()-1);
    print(s1);

    return 0;
}