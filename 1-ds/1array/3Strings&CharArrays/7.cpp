#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
 char maxOccurenceInAString(string s){
    char ans,maxCount=0;
    for(int i=0;i<s.length();i++){
      char c=i,count=0;
      for(int j=0;j<s.length();j++){
        if(s[c]==s[j] && c!=j )
            count++;
      }
    if(count>maxCount){
        ans=s[c];
        maxCount=count;
    }
    }
    return ans;
 }

int main(){
   string s="tstststsfsfsfststssttttttttttttttt";
   cout<<maxOccurenceInAString(s);
  return 0;
}