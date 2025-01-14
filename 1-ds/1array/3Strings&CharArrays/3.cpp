#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
bool palindrome(char str[]){
    int start=0,end=strlen(str)-1,count=0;
    while(start<end){
      if(str[start]!=str[end]){
        return false;
      }else{
        start++;
        end--;
      }
        }
    return true;
}

int main(){
    char str[20];
    cin>>str;
    cout<<palindrome(str);
  return 0;
}