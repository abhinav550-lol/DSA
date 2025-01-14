#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
bool palindrome(string s,int start,int end){
    while(start<end){
        if(s[start]!=s[end]){
            return false;
        }
        start++;
        end--;
        palindrome(s,start,end);
    }
    return true;
}

int main(){
   string s="malayalam";
   cout<<palindrome(s,0,s.size()-1);    
  return 0;
}