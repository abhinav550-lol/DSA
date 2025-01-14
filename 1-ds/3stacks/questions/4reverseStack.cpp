#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void recursiveReverse(stack<int> &s, vector<int> &stackElements) {
    if (s.empty()) {
        for (int i = 0; i < stackElements.size(); i++) {
            s.push(stackElements[i]);
        }
        return;
    }

    int poppedElement = s.top();
    s.pop();
    stackElements.push_back(poppedElement);

    recursiveReverse(s, stackElements);
}

void reverseStack(stack<int> &s) {
    vector<int> stackElements;
    recursiveReverse(s, stackElements);
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
    reverseStack(s1);
    print(s1);
  return 0;
}