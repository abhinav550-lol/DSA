#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
  bool isSorted(int arr[],int s){
      if(s ==1 || s== 0)
        return true;
      
      if(arr[0]>arr[1]){
        return false;
      }else{
        bool ans=isSorted(arr+1,s-1);
         return ans;
      }
  }

int main(){
    int arr[]={1,2,3,4,5,6,7,8};
    cout<<isSorted(arr,8);
    return 0;
}