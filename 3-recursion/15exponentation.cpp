#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
 int recursivePower(int a,int b){
    if(b==0){return 1;}
    if(b==1) {return a;}
     int ans = recursivePower(a,b/2);
    if(b&1){
        return a*ans*ans;
    }else{
return ans*ans;
    }
 }

int main(){
   int a,b;
   cin>>a>>b;
   cout<<recursivePower( a, b);    
  return 0;
}