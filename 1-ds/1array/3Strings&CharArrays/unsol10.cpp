#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 // oermuttion in string 
 
 bool permutationInString(string s1,string s2){
    int arr[26]={0};
    for(int i=0;i<s1.size();i++){
      int index=s1[i]-'a';
      arr[index]++;
    }
    int i=0,k=s1.length();
    while(i<s2.length() && i<i+k){
      int index=s2[i]-'a';
      int count=0;
      if(arr[index]!=0){
        count++;
        arr[index]--;
      }
      i++;
      if(count==s1.length()){
        return true;
      }
    }
 return false;
 }

int main(){
   string s1="ab",s2="baooo";
   cout<<permutationInString(s1,s2);
  return 0;
}