#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
   void insertionSort(int *arr,int size,int i=1){
    if(size<i) return ;
    int currentElem=arr[i],j=i-1;
    while(j>=0 && arr[j]>currentElem){
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=currentElem;
    insertionSort(arr,size,i+1);
   }

int main(){
   int arr[1]={1};
   insertionSort(arr,1);
   for(int e:arr){
    cout<<e<<' ';
   }
  return 0;
}