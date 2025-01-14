#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Your code here
    set<vector<int>> s;
    s.insert({1 , 3});
    s.insert({1 , 3});
    for(auto e : s){
        for(auto i : e){
            cout << i << ' ';
        }cout << endl;
    }
    return 0;
}