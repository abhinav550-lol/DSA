#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 /*
  void ReverseString(string &s1,int s, int e){
        if(s>e){return ;}
        swap(s1[s++],s1[e--]);
        ReverseString(s1,s,e);
  }
*/
void reverseString(string &s1,int s=0){
     if(s>s1.size()-s-1) return ;
     swap(s1[s],s1[s1.size()-s-1]);
     s++;
     reverseString(s1,s);
}

int main(){
    string s;
   cin>>s;
   reverseString(s);    
   cout<<s;
  return 0;
}