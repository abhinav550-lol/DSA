#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
 void reverse(char str[]){
    int start=0,end=strlen(str)-1;
    while(start<end){
        swap(str[start++],str[end--]);
    }
    cout<<str;
    
 }
 

int main(){
   char str[20],str2[20];
   cin>>str;
   reverse(str);

  return 0;
}