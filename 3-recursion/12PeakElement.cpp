#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
 int peakElement(int *arr,int start,int end){
    int mid=start+(end-start)/2;
    while(start<end){
        if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1]) return mid;
        if(arr[mid+1]>arr[mid]){
          return peakElement(arr,mid+1,end);
        }else{
            return peakElement(arr,start,mid);
        }
    }
 }

int main(){
   int arr[10]={1,2,3,4,5,6,5,2,1,0};
   cout<<peakElement(arr,0,9);
  return 0;
}