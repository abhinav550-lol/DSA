#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
 int partition(int *arr,int s,int e){
    int pivot = arr[s],count=0;

    for(int i=s+1;i<=e;i++){
        if(arr[i]<=pivot) count++;
    }
    
    int pivotIndex= s+count;
    swap(arr[s],arr[pivotIndex]);

    int i=s,j=e;    
    while(i<pivotIndex && j>pivotIndex){
        while(arr[i]<=arr[pivotIndex]){i++;}
        while(arr[j]>arr[pivotIndex]){j--;}
        if(i<pivotIndex && j>pivotIndex)
        swap(arr[i++],arr[j--]);
    }
    return pivotIndex;
 }

 void quickSort(int *arr,int s,int e){
    if(s>=e) return ;

    int P=partition(arr,s,e);

    quickSort(arr,s,P-1);
    quickSort(arr,P+1,e);

 }

int main(){
   int arr[5]={3,5,9,1,2};
   int n=sizeof(arr)/sizeof(arr[0]);

   quickSort(arr,0,n-1);

   for(int i:arr) cout<<i<<' ';
  return 0;
}