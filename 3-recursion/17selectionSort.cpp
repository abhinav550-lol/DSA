#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
 void selectionSort(int *arr,int size,int i=0){
    if(i>=size-1) return ;
        int currentPos=i;
        for(int j=i+1;j<size;j++){
            if(arr[currentPos]>arr[j])
                currentPos=j;
        }
        swap(arr[currentPos],arr[i]);
       selectionSort(arr,size,i+1);
 }

int main(){
   int arr[7]={12,23,32,5,4,13,98};
   selectionSort(arr,7);
   for(int e : arr)
    cout<<e<<' ';
  return 0;
}