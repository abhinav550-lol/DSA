#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
int pivot(int *arr,int start,int end){
    int mid = start+ (end-start)/2;
    while(start<end){
        if(arr[mid-1]>arr[mid] && arr[mid+1]>arr[mid]) return mid;
        if(arr[0]>arr[mid]){
            return pivot(arr,start,mid);
        }else{
            return pivot(arr,mid+1,end);
        }
    } 
 }

int main(){
       int arr[]={8,9,10,1,2,3,4,5,6,7,8};
       cout<<pivot(arr,0,11);
  return 0;
}