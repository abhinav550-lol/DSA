#include <iostream>
#include<bits/stdc++.h>
using namespace std;
//  daaabbbcccc = da3b3c4
 string nick(string s){
      string t="";
      int i=0;
      while(i<s.length()){
        int count = 0,j=i;
        while(s[j]==s[j+1]){
            count++;
            j++;
            i++;
        }
        if(count!=0){
            t.push_back(s[j]);
            t.push_back(count);
        }
        if(s[i]!=s[i+1] && count==0){
            t.push_back(s[i]);
        i++;
        }
      }
      return t;
 }

int main(){
string s="daaabbbcccc"; 
 s=nick(s);
 cout<<s;
  return 0;
}