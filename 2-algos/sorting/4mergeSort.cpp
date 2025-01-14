#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
void merge(int arr[],int s,int e){
    int mid=s+(e-s)/2;

    int len1=mid-s+1;
    int len2=e-mid;

    int *arr1=new int[len1];
    int *arr2=new int[len2];

    int mainArrayIndex = s;
    for(int i=0;i<len1;i++){
        arr1[i]=arr[mainArrayIndex++];
    }

    mainArrayIndex = mid+1;
    for(int i=0;i<len2;i++){
        arr2[i]=arr[mainArrayIndex++];
    }

    int i=0,j=0;
    mainArrayIndex=s;
    while(i<len1 && j<len2){
        if(arr1[i]<arr2[j]){
            arr[mainArrayIndex++]=arr1[i++];
        }else{
            arr[mainArrayIndex++]=arr2[j++];
        }
    }
    while(i<len1){
        arr[mainArrayIndex++]=arr1[i++];
    }
    while(j<len2){
        arr[mainArrayIndex++]=arr2[j++];
    }
     
    delete []arr1;
    delete []arr2;
}


  void mergeSort(int arr[],int s, int e){
  if(s>=e){ return ;}

  int mid=s+(e-s)/2;

    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);
    
    merge(arr,s,e);
 }


int main(){
   int arr[5]={19,9,5,34,23};
   int n=sizeof(arr)/sizeof(arr[0]);
   mergeSort(arr,0,n-1);
   for(int i:arr) cout<<i<<' ';
   return 0;
}