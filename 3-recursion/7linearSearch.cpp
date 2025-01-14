#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
  bool linearSearch(int *arr,int s,int key){
    if(s==0){return false;}
    if(arr[0]==key){
        return true;
    }else{
        bool ans = linearSearch(arr+1,s-1,key);
        return ans;
    }
  }

int main(){
    int arr[5]={1,2,19,23,4};
    cout<<linearSearch(arr,5,19);
  return 0;
}