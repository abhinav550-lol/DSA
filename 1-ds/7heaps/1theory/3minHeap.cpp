#include <bits/stdc++.h> 
void heapify(vector<int>& arr , int size ,int i){
    int smallest = i;
    int leftChild = 2 * i ; 
    int rightChild = 2 * i + 1; 

    if(leftChild < size && arr[leftChild] < arr[smallest]){
        smallest = leftChild;
    }
    if(rightChild < size && arr[rightChild] < arr[smallest]){
        smallest = rightChild;
    }

    if(smallest != i){
        swap(arr[smallest] , arr[i]);
        heapify(arr,size,smallest);
    }
}

vector<int> buildMinHeap(vector<int> &arr)
{
    int size = arr.size();
    for(int i = size/2 ; i>= 1;i--){
    heapify(arr,size,i);
        }
    return arr;
}
