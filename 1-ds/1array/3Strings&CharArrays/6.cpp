#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 string reverseInOrder(string s){
    int start =0,end =0;
    while(end<=s.length()){
        while(s[end+1]!=' ' && end+1<s.length() ){
            end++;
        }
        int s1=start,s2=end; 
        while(s1<s2){
            swap(s[s1++],s[s2--]);
        }
        start=end+2,end=start;
    }
    return s;
 }
 string reverseOrderOfWords(string s){
    int start=0,end=0;
     reverse(s.begin(),s.end());
     return reverseInOrder(s);
 }

int main(){
       string s="the sky is blue";
       s=reverseOrderOfWords(s);
       cout<<s;
  return 0;
}