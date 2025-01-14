#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
   const vector <string> arr={"zero","one", "two" ,"three", "four" , "five" , "six", "seven", "eight" ,"nine"};
 void sayDigits(int n){
    if(n==0){ return ;}
    sayDigits(n/10);
    cout<<arr[n%10]<<' ';
 }

int main(){
   int n;
   cin>>n;
   sayDigits(n);    
  return 0;
}