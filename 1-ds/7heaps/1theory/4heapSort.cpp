#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
void heapify(int *arr ,int size ,int i){
    int largestIndex = i;
    int leftIndex = 2* i;
    int rightIndex = 2* i + 1;

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

void heapSort(int *arr,int size){
    int heapSize = size;
    while( heapSize > 1){
        swap(arr[1] , arr[heapSize]);
        heapSize--;
        heapify(arr, heapSize, 1);
    }
}

int main(){
   int arr[6] = {-1,55 ,54 ,53 , 50 , 52};
   heapSort(arr,5);
   for(int i : arr) cout << i <<' '; 
  return 0;
}