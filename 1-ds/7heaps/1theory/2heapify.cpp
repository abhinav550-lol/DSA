#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 

void heapify(int *arr, int size , int i){
    int largestIndex = i;
    int leftIndex = 2*i;
    int rightIndex = 2*i + 1;

    if(leftIndex <= size && arr[leftIndex] > arr[largestIndex]){
        largestIndex = leftIndex;
    }
    if(rightIndex <= size && arr[rightIndex] > arr[largestIndex]){
        largestIndex = rightIndex;
    }

    if(largestIndex != i){
        swap(arr[largestIndex] , arr[i]);
        heapify(arr,size,largestIndex);
    }
}

void convertToHeap(int *arr, int size ){
    for(int i = size / 2; i>=1 ; i--){
        heapify(arr,size,i);
    }
}

int main(){
   int arr[6] = {-1, 54 ,53 , 55 , 52 , 50};
   int size = sizeof(arr)/sizeof(arr[0]);
   convertToHeap(arr,size);
   for(int i = 1; i< size ; i++)  cout << arr[i] <<' ';
  
  return 0;
}