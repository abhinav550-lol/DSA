#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
// bool binarySearch(int *arr, int s, int k) {
//     if (s <= 0)  return false;
//      int mid = s / 2;
    
//     if (arr[mid] == k) {
//         return true;
//     } else if (arr[mid] > k) {
//         return binarySearch(arr, mid, k);
//     } else {
//         return binarySearch(arr + mid + 1, s - mid - 1, k);
//     }
// }

bool binarySearch(int *arr,int end ,int k,int start=0){
    if(start>end){return false;}
    int mid = start + (end-start)/2;
    if(arr[mid]==k){return true;}
    if(arr[mid]>k){
        return binarySearch(arr,mid-1,k,start);
    }else{
        return binarySearch(arr,end,k,mid+1);
    }
}

int main(){
   int arr[]={1,2,3,4,5,6};
   cout<<binarySearch(arr,5,6);    
  return 0;
}