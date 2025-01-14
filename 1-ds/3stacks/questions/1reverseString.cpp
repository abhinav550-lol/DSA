#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string reverseString(string n){
    stack <char> s ;
    string res;
    for(int i = 0 ; i < n.length() ; i++){
        s.push(n[i]);
    }
    for(int i=0; i<n.length();i++){
        res.push_back(s.top());
        s.pop();
    }
    return res;
}

int main()
{
    string n = "HELLO";
    cout << reverseString(n);
    return 0;
}