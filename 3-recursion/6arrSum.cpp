#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
   int arraySum(int *arr,int s){
    if(s==0){return 0;}
    int sum = arr[0]+arraySum(arr+1,s-1);
    return sum;
   }

int main(){
   int arr[5]={};
   cout<<arraySum(arr,5);    
  return 0;
}