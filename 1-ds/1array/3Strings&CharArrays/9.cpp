#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
 string removeAllOccurences(string s,string part){
    while(s.length()!=0 && s.find(part)<s.length()){
        s.erase(s.find(part),part.length());
    }
    return s;
 }

int main(){
    string s="axxxxyyyyb";
    s=removeAllOccurences(s,"xy");
    cout<<s;
  return 0;
}