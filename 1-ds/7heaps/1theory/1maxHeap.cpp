#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
class maxHeap{
    int *arr;
    int size;
    public:
    maxHeap(int capacity = 5){
        arr = new int[capacity];
        size = 0;
    } 
    
    void insert(int x){
        size++;
        int index = size;
        arr[index] = x;

        while(index>1){
            int parentIndex = index /2;
            if(arr[parentIndex] < arr[index]){
            swap(arr[parentIndex], arr[index]);
            index = parentIndex;
            }else
                break;
        }
    }

    void remove(){
        if(size == 0) return ;

        arr[1] = arr[size];

        size--;

        int index = 1;

        while(index < size){
            int leftIndex = 2*index;
            int rightIndex = 2*index + 1;
            if(size >= leftIndex && arr[leftIndex] > arr[index]){
            swap(arr[leftIndex], arr[index]);
            index = leftIndex;
            } 
            else if(size >= rightIndex && arr[rightIndex] > arr[index]){
             swap(arr[rightIndex], arr[index]);
             index = rightIndex;
            }else{
                return ;
            }
        }
    }

    void print(){
        for(int i = 1; i <= size ; i++) cout << arr[i] << ' ';
        cout << endl;
    }
};

int main(){
 maxHeap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.remove();
    h.print();
  return 0;
}