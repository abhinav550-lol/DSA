#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
// your code here
priority_queue<int> pq;
for(int i = 0;i<n;i++) pq.push(a[i]);
for(int i = 0;i<m;i++) pq.push(b[i]);

vector<int> res;
while(!pq.empty()){
    int curr = pq.top();
    res.push_back(curr);
    pq.pop();
}
return res;
}

int main(){
    
  return 0;
}