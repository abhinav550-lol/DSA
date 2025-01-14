#include <iostream>
#include<bits/stdc++.h>
using namespace std;

 int firstOccurence(int *arr,int start,int end,int key){
    int mid=start+(end-start)/2;
    while (start<end)
    {
        if(arr[mid]==key && arr[mid-1]!=key) return mid;
        if(arr[mid]==key && arr[mid-1]==key){
            mid--;
        }else if(arr[mid]>key){
            return firstOccurence(arr,start,mid-1,key);
        }else{
             return firstOccurence(arr,mid+1,end,key);
        }
    }
    
 }
 
 int lastOccurence(int *arr,int start,int end,int key){
    int mid=start+(end-start)/2;
    while (start<end)
    {
        if(arr[mid]==key && arr[mid+1]!=key) return mid;
        if(arr[mid]==key && arr[mid+1]==key){
            mid++;
        }else if(arr[mid]>key){
            return lastOccurence(arr,start,mid-1,key);
        }else{
             return lastOccurence(arr,mid+1,end,key);
        }
    }
    
 }
 
int main(){
   int arr[10]={1,2,2,3,3,3,3,3,3,3};
   cout<<firstOccurence(arr,0,9,2)<<' '<<lastOccurence(arr,0,9,2);
  return 0;
}