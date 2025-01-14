#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
int fact(int n){
    if(n==0 || n == 1){ return 1; }
    return n*fact(n-1);
}

void printCounting(int n){
    if(n==0) return ;
    cout<<n<<' ';
    printCounting(n-1);
}   

 int twoSquared(int n){
    if(n==0){
        return 1;
    }
    return 2*twoSquared(n-1);
 }

int main(){
   int n;
   cin>>n;
   cout<<twoSquared(n);

//    printCounting(n); 
//    cout<<fact(n);
  return 0;
}