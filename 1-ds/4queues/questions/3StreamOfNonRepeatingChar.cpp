#include <iostream>
#include <bits/stdc++.h>
using namespace std;



string FirstNonRepeating(string A){
  string ans;
  map<char,int> cnt;
  queue<char> q;
  for(int i=0;i<A.length();i++){
    cnt[A[i]]++;
    q.push(A[i]);

    while(!q.empty()){
      int curr = q.front();
      if(cnt[q.front()]>1){
        q.pop();
      }else{
        ans.push_back(curr);
        break;
      }
    }
    if(q.empty()){
      ans.push_back('#');
    }
  }
  return ans;
}

int main(){
  string A = "aabc";
  cout<<FirstNonRepeating(A);
  return 0;
}